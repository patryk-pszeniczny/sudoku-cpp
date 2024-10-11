#include "MainForm.h"
#include "SudokuGenerate.h"
#include <iostream>
#include <string>
#include <algorithm>


namespace szablon {
    MainForm::MainForm(void) {
        InitializeComponent();
        this->entries = 0;
        this->entries_wrong = 0;
        this->generator = new SudokuGenerate();
        this->generator->fillArrays();
        this->generator->GenerateSudoku();
        this->generator->removeDigits(51);
        this->CreateTextBoxes();

    }
    void MainForm::CreateTextBoxes() {
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                TableLayoutPanel^ tb = dynamic_cast<TableLayoutPanel^>(this->table->GetControlFromPosition(blockCol, blockRow));
                for (int rowOffset = 0; rowOffset < 3; rowOffset++) {
                    for (int colOffset = 0; colOffset < 3; colOffset++) {
                        int globalRow = blockRow * 3 + rowOffset;
                        int globalCol = blockCol * 3 + colOffset;
                        CreateTextBox(tb, globalRow, globalCol);
                    }
                }
            }
        }
        label1->Text += generator->numberOfSolution;
        label2->Text += generator->tryGen;
    }
    void MainForm::CreateTextBox(TableLayoutPanel^ parentTable, int row, int col) {
        TextBox^ text = gcnew TextBox();
        text->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(58)), 
            static_cast<System::Int32>(static_cast<System::Byte>(50)),
            static_cast<System::Int32>(static_cast<System::Byte>(50)));
        text->Padding = System::Windows::Forms::Padding(0);
        text->Margin = System::Windows::Forms::Padding(0);
        text->Width = 57;
        text->Height = 57;
        text->AutoSize = false;
        text->MaxLength = 1;
        text->Font =(gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
        text->ForeColor = System::Drawing::SystemColors::Control;
        text->TextAlign = HorizontalAlignment::Center;
        text->KeyPress += gcnew KeyPressEventHandler(this, &MainForm::TextBox_KeyPress);

        int value = generator->board[row][col];
        text->Name = L"text_" + row + "_" + col;
        text->Tag = gcnew array<int>{ row, col };

        if (value != 0) {
            text->Text = value.ToString();
            text->ReadOnly = true;
            text->Enabled = false;
            //40; 117; 29
            text->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(117)),
                static_cast<System::Int32>(static_cast<System::Byte>(29)));
            text->Click += gcnew EventHandler(this, &MainForm::LockedTextBox_Click);
        }

        parentTable->Controls->Add(text, col % 3, row % 3);
    }
    void MainForm::TextBox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
    {
        if (!Char::IsDigit(e->KeyChar) || e->KeyChar == '0') {
            if (e->KeyChar != (char)Keys::Back) {
                e->Handled = true;
                return;
            }
        }
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);

        if (textBox != nullptr && e->KeyChar != (char)Keys::Back) {
        
            int value = e->KeyChar - '0'; 
            array<int>^ coordinates = dynamic_cast<array<int>^>(textBox->Tag);

            if (coordinates != nullptr) {
                int row = coordinates[0];
                int col = coordinates[1];
                generator->board[row][col] = value;
                int valueCheck = generator->copy_board[row][col];
                this->entries_wrong++;
                if (value == valueCheck) {
                    textBox->BackColor = System::Drawing::Color::FromArgb(
                        static_cast<System::Int32>(static_cast<System::Byte>(255)),
                        static_cast<System::Int32>(static_cast<System::Byte>(128)),
                        static_cast<System::Int32>(static_cast<System::Byte>(0)));
                    textBox->Enabled = false;
                    textBox->Text = value.ToString();
                    textBox->ReadOnly = true;
                    generator->copy_board[row][col] = 0;
                    this->entries++;
                }
                this->entries_label->Text = "Entries: [" + this->entries + "/" + this->entries_wrong + "]";
                return;
            }
        }
    }
    void MainForm::LockedTextBox_Click(Object^ sender, EventArgs^ e){
        MessageBox::Show("To pole jest zablokowane!", "Informacja", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }


}
