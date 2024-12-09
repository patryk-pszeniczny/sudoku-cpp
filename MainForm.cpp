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
		std::string valueName = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
		std::string valueDifficulty = msclr::interop::marshal_as<std::string>(this->groupBox2->Text);
		if (this->gameform != nullptr) {
			this->gameform->Close();
			this->gameform = nullptr;
		}
		if(this->gameUser == nullptr || this->gameUser->getName() != valueName)
			this->gameUser = new GameUser(valueName, 0, valueDifficulty);
		this->gameform = gcnew GameForm(gameUser, this->trackBar1->Value);
		this->gameform->Show();
		
	}
	void MainForm::clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->textBox1->Text = "Patryk Pszeniczny";
		this->trackBar1->Value = 1;
		this->groupBox2->Text = L"Peaceful";
		if (this->gameUser != nullptr) {
			this->gameUser = nullptr;
		}
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
}
