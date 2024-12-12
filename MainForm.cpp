#include "MainForm.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include "GameForm.h"
#include "GameUser.h"
#include "AboutForm.h"
namespace szablon {
    MainForm::MainForm(void) {
        InitializeComponent();
    }
	void MainForm::difficultyBar_Scroll(System::Object^ sender, System::EventArgs^ e){
		std::string difficulty = "";
		int diff = this->trackBar1->Value;
		if (diff >= 70) difficulty = "HardCore";
		else if (diff >= 60) difficulty = "Hard";
		else if (diff >= 50) difficulty = "Advanced";
		else if (diff >= 40) difficulty = "Medium";
		else if (diff >= 30) difficulty = "Normal";
		else if (diff >= 20) difficulty = "Easy";
		else if (diff >= 10) difficulty = "Beginner";
		else difficulty = "Peaceful";
		this->groupBox2->Text = gcnew System::String(difficulty.c_str());
    }
	void MainForm::start_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!this->readyToPlay) {
			System::String^ message = "Kliknij w 'stats', \nAby za³adowaæ statystki i rozegraæ grê";
			MessageBox::Show(message,"START",MessageBoxButtons::OK,MessageBoxIcon::Information);
			return;
		}
		std::string name = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
		std::string difficulty = msclr::interop::marshal_as<std::string>(this->groupBox2->Text);
		int digitsDifficulty = this->trackBar1->Value;

		if (this->gameform != nullptr) {
			this->gameform->Close();
			this->gameform = nullptr;
		}
		GameUser* gameuser = this->gameStats->getGameUser(name);
		if (!gameuser) {
			gameuser = new GameUser(name, 0, 0, difficulty, false);
		}else {
			gameuser->setDifficulty(difficulty);
		}
		this->gameform = gcnew GameForm(gameuser, difficulty, digitsDifficulty, this->gameStats);
		this->gameform->Show();
		
	}
	void MainForm::clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->readyToPlay = false;
		this->gameStats = nullptr;
		this->textBox1->Text = "Patryk Pszeniczny";
		this->trackBar1->Value = 1;
		this->groupBox2->Text = L"Peaceful";
		if (this->gameform != nullptr) {
			this->gameform->Close();
			this->gameform = nullptr;
		}
	}
	void MainForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	void MainForm::aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		AboutForm^ aboutForm = gcnew AboutForm();
		aboutForm->Show();
	}
	void MainForm::statsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->gameStats = new GameStats();
		this->readyToPlay = gameStats->openDialogFile();
	}
	void MainForm::setGameStats(GameStats* gamestats) {
		this->gameStats = gamestats;
	}
	GameStats* MainForm::getGameStats() {
		return this->gameStats;
	}
	void MainForm::setReadyToPlay(bool value) {
		this->readyToPlay = value;
	}
	bool MainForm::getReadyToPlay() {
		return this->readyToPlay;
	}
}
