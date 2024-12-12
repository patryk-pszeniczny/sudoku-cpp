#include "GameStats.h"
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <memory>
namespace szablon {
	GameStats::GameStats(): highScore(0), highScoreSum(0), gameuser(nullptr) {}

	void GameStats::loadUser(std::string split) {
		std::vector<std::string> lines;
		std::istringstream stream(split);
		std::string segment;
		while (std::getline(stream, segment, ';')) {
			lines.push_back(segment);
		}

		if (lines.empty()) {
			return;
		}
		std::string userName = lines[0];
		GameUser* gameuser = new GameUser(userName, 0, 0, "-", true);
		int pointSum = 0;
		for (size_t i = 1; i < lines.size(); ++i) {
			try {
				int points = std::stoi(lines[i]);
				pointSum += points;

				if (highScore < points) {
					highScore = points;
					this->gameuser = gameuser;
				}
			}
			catch (const std::exception& e) {
				continue;
			}
		}

		if (highScoreSum < pointSum) {
			highScoreSum = pointSum;
		}

		gameuser->setTotal(pointSum);
		this->vectorGameUsers.push_back(gameuser);
	}

	GameUser* GameStats::getGameUser(std::string name)
	{
		for (GameUser* user : vectorGameUsers) {
			if (user->getName() == name) {
				return user;
			}
		}
		return nullptr;
	}
	void GameStats::saveUser(GameUser* gu)
	{
		if (!gu) {
			System::Windows::Forms::MessageBox::Show("Invalid user!",
				"Error",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);
			return;
		}

		std::ifstream inputFile(filePathNative);
		if (!inputFile.is_open()) {
			System::Windows::Forms::MessageBox::Show("Could not open file for saving user data!",
				"Error",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);
			return;
		}

		std::vector<std::string> lines;
		std::string line;
		bool updated = false;

		while (std::getline(inputFile, line)) {
			std::vector<std::string> parts;
			std::istringstream stream(line);
			std::string part;
			while (std::getline(stream, part, ';')) {
				parts.push_back(part);
			}

			if (!parts.empty() && parts[0] == gu->getName()) {
				line += ";" + std::to_string(gu->getPoints());
				updated = true;
			}
			lines.push_back(line);
		}

		inputFile.close();

		if (!updated) {
			lines.push_back(gu->getName() + ";" + std::to_string(gu->getPoints()));
		}

		gu->setTotal(gu->getTotalPoints());
		gu->setFromBase(true);

		std::ofstream outputFile(filePathNative);
		if (!outputFile.is_open()) {
			System::Windows::Forms::MessageBox::Show("Could not write to file!",
				"Error",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);
			return;
		}

		for (const auto& updatedLine : lines) {
			outputFile << updatedLine << std::endl;
		}

		outputFile.close();
		System::Windows::Forms::MessageBox::Show("User data saved successfully!",
			"Info",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information);
	}
	bool GameStats::openDialogFile() {
		System::Windows::Forms::OpenFileDialog^ openFileDialog = gcnew System::Windows::Forms::OpenFileDialog();
		openFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
		openFileDialog->Title = "Select a Statistics File";

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			filePathNative = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);

			std::ifstream inputFile(filePathNative);
			if (!inputFile.is_open()) {
				System::Windows::Forms::MessageBox::Show("Failed to load the file!",
					"Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
				return false;
			}

			std::string line;
			while (std::getline(inputFile, line)) {
				loadUser(line);
			}

			inputFile.close();

			System::Windows::Forms::MessageBox::Show("Statistics successfully loaded!",
				"Info",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Information);

			return true;
		}

		System::Windows::Forms::MessageBox::Show("No file selected!",
			"Info",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information);
		return false;
	}
	GameUser* GameStats::getHighScoreUser() {
		return this->gameuser;
	}
	int GameStats::getHighScore()
	{
		return this->highScore;
	}
	int GameStats::getHighScoreSum()
	{
		return this->highScoreSum;
	}
	GameStats::~GameStats()
	{
		for (auto user : vectorGameUsers) {
			delete user;
		}
		vectorGameUsers.clear();
	}

}