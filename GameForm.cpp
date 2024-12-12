#include "GameForm.h"
#include "GameUser.h"
#include "GameLogic.h"
#include "GameStats.h"
#include <iostream>
#include <string>
#include <algorithm>

namespace szablon {
    GameForm::GameForm(GameUser* gameuser, std::string difficulty, int difficultyRemoveDigits, GameStats* gameStats)
    {
        InitializeComponent();
        this->gameUser = gameuser;
        this->gameStats = gameStats;
        this->difficulty = difficultyRemoveDigits;
        this->createGame();
    }
    void GameForm::createGame() {
        this->entries = 0;
        this->entries_wrong = 0;
        this->hint = 0;

        this->gameLogic = new GameLogic();
        this->gameLogic->fillArrays();
        this->gameLogic->GenerateSudoku();
        this->gameLogic->removeDigits(this->difficulty);
        this->CreateTextBoxes();
        this->unFocusBox();
        this->UpdateUserName();
        this->UpdatePoints();
        this->UpdateDifficulty();
        this->UpdateHighScore();
    }
    void GameForm::UpdateDifficulty() {
        this->label_difficulty->Text = "Trudność: " + gcnew System::String(this->gameUser->getDifficulty().c_str());
    }
    void GameForm::UpdateUserName() {
        this->label_username->Text = "Nazwa: " + gcnew System::String(this->gameUser->getName().c_str());
    }
    void GameForm::UpdatePoints() {
        this->label_points->Text = "Punkty: " + this->gameUser->getPoints();
        this->label_total->Text = "Total: " + this->gameUser->getTotal();
    }
    void GameForm::UpdateHighScore() {
        this->high_score_name->Text = "Nazwa: "+gcnew System::String(this->gameStats->getHighScoreUser()->getName().c_str());
        this->high_score_points->Text = "Punkty: " + this->gameStats->getHighScore();
        this->high_score_sum->Text = "Suma Punktów: " + this->gameStats->getHighScoreSum();
    }
    void GameForm::CreateTextBoxes() {
        for (int blockRow = 0; blockRow < 3; blockRow++)
        for (int blockCol = 0; blockCol < 3; blockCol++) {
            auto tb = dynamic_cast<TableLayoutPanel^>(this->table->GetControlFromPosition(blockCol, blockRow));
            if (!tb) continue;
            for (int rowOffset = 0; rowOffset < 3; rowOffset++)
            for (int colOffset = 0; colOffset < 3; colOffset++) {
                int globalRow = blockRow * 3 + rowOffset;
                int globalCol = blockCol * 3 + colOffset;
                CreateTextBox(tb, globalRow, globalCol);
            }
        }
        label1->Text += this->gameLogic->getGenerateTime() + "ms";
        label2->Text += this->gameLogic->getSamples();
    }
    void GameForm::CreateTextBox(TableLayoutPanel^ parentTable, int row, int col) {
        TextBox^ text = gcnew TextBox();
        text->BackColor = System::Drawing::Color::FromArgb(13, 50, 50);
        text->Padding = System::Windows::Forms::Padding(0);
        text->Margin = System::Windows::Forms::Padding(0);
        text->Width = 57;
        text->Height = 57;
        text->AutoSize = false;
        text->MaxLength = 1;
        text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        text->ForeColor = ForeColor.White;
        text->TextAlign = HorizontalAlignment::Center;
        text->KeyPress += gcnew KeyPressEventHandler(this, &GameForm::TextBox_KeyPress);

        int value = gameLogic->getBoard(row, col);
        text->Name = L"text_" + row + "_" + col;
        text->Tag = gcnew array<int>{ row, col };

        if (value != 0) {
            text->Text = value.ToString();
            text->ReadOnly = true;
            text->BackColor = System::Drawing::Color::FromArgb(20, 170, 20);
            text->Click += gcnew EventHandler(this, &GameForm::LockedTextBox_Click);
        }

        parentTable->Controls->Add(text, col % 3, row % 3);
    }
    void GameForm::TextBox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
    {
        if ((!Char::IsDigit(e->KeyChar) || e->KeyChar == '0') && e->KeyChar != (char)Keys::Back) {
            e->Handled = true;
            return;
        }
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);
        if (!textBox || textBox->ReadOnly) {
            this->unFocusBox();
            return;
        }
        if (e->KeyChar == (char)Keys::Back) {
            return;
        }
        int value = e->KeyChar - '0';
        auto coordinates = dynamic_cast<array<int>^>(textBox->Tag);
        if (!coordinates) return;
        
        int row = coordinates[0];
        int col = coordinates[1];

        gameLogic->setBoard(row, col, value);
        if (value == gameLogic->getCopyBoard(row, col)) {
            this->unFocusBox();
            textBox->BackColor = System::Drawing::Color::FromArgb(255, 170, 20);
            textBox->Text = value.ToString();
            textBox->ReadOnly = true;
            textBox->Click += gcnew EventHandler(this, &GameForm::LockedTextBox_Click);
            this->gameLogic->setCopyBoard(row, col, 0);
            this->entries++;
            this->gameUser->addPoints(5);
        }
        else {
            this->entries_wrong++;
            this->gameUser->removePoints(1);
        }
        this->UpdatePoints();
        this->label_wrong_guess->Text = "Błędne: " + this->entries_wrong;
        this->label_right_guess->Text = "Poprawne: " + this->entries;
    }
    void GameForm::LockedTextBox_Click(Object^ sender, EventArgs^ e) {
        this->unFocusBox();
    }
    void GameForm::unFocusBox()
    {
        this->table->Focus();
        this->table->Select();
    }
    void GameForm::verify_button_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->gameLogic->checkSudoku()) {
            System::String^ userName = gcnew System::String(this->gameUser->getName().c_str());
            System::String^ message = "Gratulacje " + userName + "!\nUdało Ci się poprawnie rozwiązać sudoku!\n\nUzyskując " +
                this->gameUser->getPoints().ToString() + " Punktów \n";

            MessageBox::Show(
                message,
                "Wygrana",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information
            );
            this->gameStats->saveUser(this->gameUser);
            this->Close();
            return;
        }
            MessageBox::Show(
                "Niestety, rozwiązanie jest błędne. Spróbuj jeszcze raz!",
                "Błąd",
                MessageBoxButtons::OK,
                MessageBoxIcon::Error
            );
    }

    void GameForm::help_button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                TableLayoutPanel^ tb = dynamic_cast<TableLayoutPanel^>(this->table->GetControlFromPosition(blockCol, blockRow));
                if (tb != nullptr && ProcessBlock(tb, blockRow, blockCol)) {
                    return;
                }
            }
        }
    }
    void GameForm::reset_button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        for (int blockRow = 0; blockRow < 3; blockRow++)
        for (int blockCol = 0; blockCol < 3; blockCol++) {
            auto tb = dynamic_cast<TableLayoutPanel^>(this->table->GetControlFromPosition(blockCol, blockRow));
            if (tb == nullptr) continue;
            for (int rowOffset = 0; rowOffset < 3; rowOffset++)
            for (int colOffset = 0; colOffset < 3; colOffset++) {
                auto textBox = dynamic_cast<TextBox^>(tb->GetControlFromPosition(colOffset, rowOffset));
                if (textBox)tb->Controls->Remove(textBox);
            }
        }
        this->label_wrong_guess->Text = "Błędne: 0";
        this->label_right_guess->Text = "Poprawne: 0";
        this->label_hint->Text = "Wskazówki: 0";
        this->label1->Text = "Generowanie: ";
        this->label2->Text = "Kroki: ";

        this->entries = 0;
        this->entries_wrong = 0;
        this->hint = 0;
        this->gameUser->setPoints(0);

        this->createGame();
        this->unFocusBox();

    }
    bool GameForm::ProcessBlock(TableLayoutPanel^ tb, int blockRow, int blockCol) {
        for (int rowOffset = 0; rowOffset < 3; rowOffset++) {
            for (int colOffset = 0; colOffset < 3; colOffset++) {
                int globalRow = blockRow * 3 + rowOffset;
                int globalCol = blockCol * 3 + colOffset;
                int value = this->gameLogic->getCopyBoard(globalRow, globalCol);

                if (value != 0) {
                    UpdateTextBox(tb, rowOffset, colOffset, value);
                    this->gameLogic->setBoard(globalRow, globalCol, value);
                    this->gameLogic->setCopyBoard(globalRow, globalCol, 0);
                    this->gameUser->removePoints(5);
                    this->UpdatePoints();
                    return true;
                }
            }
        }
        return false;
    }
    void GameForm::UpdateTextBox(TableLayoutPanel^ tb, int rowOffset, int colOffset, int value) {
        TextBox^ textBox = dynamic_cast<TextBox^>(tb->GetControlFromPosition(colOffset, rowOffset));
        if (textBox != nullptr) {
            //HELP ACTION
            textBox->BackColor = System::Drawing::Color::FromArgb(170, 20, 20);
            textBox->Text = value.ToString();
            textBox->ReadOnly = true;
            textBox->Click += gcnew EventHandler(this, &GameForm::LockedTextBox_Click);
            this->label_hint->Text = "Wskazówki: " + (++this->hint);
        }
    }
    GameUser* GameForm::getGameUser()
    {
        return this->gameUser;
    }
    GameStats* GameForm::getGameStats() {
        return this->gameStats;
    }
    int GameForm::getEntriesRight()
    {
        return this->entries;
    }
    int GameForm::getEntriesWrong()
    {
        return this->entries_wrong;
    }
    int GameForm::getHint()
    {
        return this->hint;
    }
    void GameForm::setGameUser(GameUser* gameuser)
    {
        this->gameUser = gameuser;
    }
}
