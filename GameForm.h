#pragma once
#include "GameLogic.h"
#include "GameUser.h"
namespace szablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class GameForm : public System::Windows::Forms::Form {
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label_difficulty;



	private: System::Windows::Forms::Label^ label_username;
	private: System::Windows::Forms::Label^ label_points;



	private: System::Windows::Forms::Label^ label_wrong_guess;

	private: System::Windows::Forms::Label^ label_right_guess;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label_hint;


	public:
		GameForm(std::string name, std::string difficulty, int removeDigits);

		void createGame();

		void UpdateDifficulty();

		GameUser* getGameUser();
		int getEntriesRight();
		int getEntriesWrong();
		int getHint();

		void setGameUser(GameUser* gameuser);

	private:
		GameLogic* gameLogic;
		GameUser* gameUser;

		int entries;
		int entries_wrong;
		int hint;
		int difficulty;

		void unFocusBox();
		void UpdateUserName();
		void UpdatePoints();
		void CreateTextBoxes();
		void CreateTextBox(TableLayoutPanel^ parentTable, int row, int col);
		bool ProcessBlock(TableLayoutPanel^ tb, int blockRow, int blockCol);
		void UpdateTextBox(TableLayoutPanel^ tb, int rowOffset, int colOffset, int value);
		//events handler
		void TextBox_KeyPress(Object^ sender, KeyPressEventArgs^ e);
		void LockedTextBox_Click(Object^ sender, EventArgs^ e);
		void verify_button_Click(System::Object^ sender, System::EventArgs^ e);
		void help_button_Click(System::Object^ sender, System::EventArgs^ e);
		void reset_button_Click(System::Object^ sender, System::EventArgs^ e);

	protected:
		~GameForm() {
			if (components) {
				delete components;
			}
			if (gameUser) {
				delete gameUser;
			} 
		}


	private: System::Windows::Forms::TableLayoutPanel^ table;
	private: System::Windows::Forms::TableLayoutPanel^ table_2_2;
	private: System::Windows::Forms::TableLayoutPanel^ table_2_1;
	private: System::Windows::Forms::TableLayoutPanel^ table_2_0;
	private: System::Windows::Forms::TableLayoutPanel^ table_1_2;
	private: System::Windows::Forms::TableLayoutPanel^ table_1_1;
	private: System::Windows::Forms::TableLayoutPanel^ table_1_0;
	private: System::Windows::Forms::TableLayoutPanel^ table_0_2;
	private: System::Windows::Forms::TableLayoutPanel^ table_0_1;
	private: System::Windows::Forms::TableLayoutPanel^ table_0_0;

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->table = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_2_2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_2_1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_2_0 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_1_2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_1_1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_1_0 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_0_2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_0_1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->table_0_0 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label_hint = (gcnew System::Windows::Forms::Label());
			this->label_username = (gcnew System::Windows::Forms::Label());
			this->label_points = (gcnew System::Windows::Forms::Label());
			this->label_wrong_guess = (gcnew System::Windows::Forms::Label());
			this->label_right_guess = (gcnew System::Windows::Forms::Label());
			this->label_difficulty = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->table->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// table
			// 
			this->table->ColumnCount = 3;
			this->table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table->Controls->Add(this->table_2_2, 2, 2);
			this->table->Controls->Add(this->table_2_1, 1, 2);
			this->table->Controls->Add(this->table_2_0, 0, 2);
			this->table->Controls->Add(this->table_1_2, 2, 1);
			this->table->Controls->Add(this->table_1_1, 1, 1);
			this->table->Controls->Add(this->table_1_0, 0, 1);
			this->table->Controls->Add(this->table_0_2, 2, 0);
			this->table->Controls->Add(this->table_0_1, 1, 0);
			this->table->Controls->Add(this->table_0_0, 0, 0);
			this->table->Location = System::Drawing::Point(9, 9);
			this->table->Margin = System::Windows::Forms::Padding(0);
			this->table->Name = L"table";
			this->table->RowCount = 3;
			this->table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table->Size = System::Drawing::Size(500, 500);
			this->table->TabIndex = 3;
			// 
			// table_2_2
			// 
			this->table_2_2->ColumnCount = 3;
			this->table_2_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_2_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_2->Location = System::Drawing::Point(334, 334);
			this->table_2_2->Margin = System::Windows::Forms::Padding(2);
			this->table_2_2->Name = L"table_2_2";
			this->table_2_2->RowCount = 3;
			this->table_2_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_2->Size = System::Drawing::Size(161, 161);
			this->table_2_2->TabIndex = 8;
			// 
			// table_2_1
			// 
			this->table_2_1->ColumnCount = 3;
			this->table_2_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_2_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_1->Location = System::Drawing::Point(168, 334);
			this->table_2_1->Margin = System::Windows::Forms::Padding(2);
			this->table_2_1->Name = L"table_2_1";
			this->table_2_1->RowCount = 3;
			this->table_2_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_1->Size = System::Drawing::Size(160, 161);
			this->table_2_1->TabIndex = 7;
			// 
			// table_2_0
			// 
			this->table_2_0->ColumnCount = 3;
			this->table_2_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_2_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_2_0->Location = System::Drawing::Point(2, 334);
			this->table_2_0->Margin = System::Windows::Forms::Padding(2);
			this->table_2_0->Name = L"table_2_0";
			this->table_2_0->RowCount = 3;
			this->table_2_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_2_0->Size = System::Drawing::Size(159, 161);
			this->table_2_0->TabIndex = 6;
			// 
			// table_1_2
			// 
			this->table_1_2->ColumnCount = 3;
			this->table_1_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_1_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_2->Location = System::Drawing::Point(334, 168);
			this->table_1_2->Margin = System::Windows::Forms::Padding(2);
			this->table_1_2->Name = L"table_1_2";
			this->table_1_2->RowCount = 3;
			this->table_1_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_2->Size = System::Drawing::Size(161, 160);
			this->table_1_2->TabIndex = 5;
			// 
			// table_1_1
			// 
			this->table_1_1->ColumnCount = 3;
			this->table_1_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_1_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_1->Location = System::Drawing::Point(168, 168);
			this->table_1_1->Margin = System::Windows::Forms::Padding(2);
			this->table_1_1->Name = L"table_1_1";
			this->table_1_1->RowCount = 3;
			this->table_1_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_1->Size = System::Drawing::Size(160, 160);
			this->table_1_1->TabIndex = 4;
			// 
			// table_1_0
			// 
			this->table_1_0->ColumnCount = 3;
			this->table_1_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_1_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_1_0->Location = System::Drawing::Point(2, 168);
			this->table_1_0->Margin = System::Windows::Forms::Padding(2);
			this->table_1_0->Name = L"table_1_0";
			this->table_1_0->RowCount = 3;
			this->table_1_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_1_0->Size = System::Drawing::Size(159, 160);
			this->table_1_0->TabIndex = 3;
			// 
			// table_0_2
			// 
			this->table_0_2->ColumnCount = 3;
			this->table_0_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_0_2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_2->Location = System::Drawing::Point(334, 2);
			this->table_0_2->Margin = System::Windows::Forms::Padding(2);
			this->table_0_2->Name = L"table_0_2";
			this->table_0_2->RowCount = 3;
			this->table_0_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_2->Size = System::Drawing::Size(161, 159);
			this->table_0_2->TabIndex = 2;
			// 
			// table_0_1
			// 
			this->table_0_1->ColumnCount = 3;
			this->table_0_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_0_1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_1->Location = System::Drawing::Point(168, 2);
			this->table_0_1->Margin = System::Windows::Forms::Padding(2);
			this->table_0_1->Name = L"table_0_1";
			this->table_0_1->RowCount = 3;
			this->table_0_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_1->Size = System::Drawing::Size(160, 159);
			this->table_0_1->TabIndex = 1;
			// 
			// table_0_0
			// 
			this->table_0_0->ColumnCount = 3;
			this->table_0_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->table_0_0->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->table_0_0->Location = System::Drawing::Point(2, 2);
			this->table_0_0->Margin = System::Windows::Forms::Padding(2);
			this->table_0_0->Name = L"table_0_0";
			this->table_0_0->RowCount = 3;
			this->table_0_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_0->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->table_0_0->Size = System::Drawing::Size(159, 159);
			this->table_0_0->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Oswald", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->ForeColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(9, 520);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 48);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Sprawdz";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &GameForm::verify_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Oswald", 15.25F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(6, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 36);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Generowanie: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Oswald", 15.25F, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(6, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 36);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Kroki: ";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Oswald", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->ForeColor = System::Drawing::SystemColors::Control;
			this->button3->Location = System::Drawing::Point(178, 520);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(160, 49);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Pomoc";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &GameForm::help_button_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->groupBox3);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(512, -3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(385, 586);
			this->panel1->TabIndex = 8;
			// 
			// label_hint
			// 
			this->label_hint->AutoSize = true;
			this->label_hint->Font = (gcnew System::Drawing::Font(L"Oswald", 15.25F, System::Drawing::FontStyle::Bold));
			this->label_hint->ForeColor = System::Drawing::SystemColors::Control;
			this->label_hint->Location = System::Drawing::Point(6, 96);
			this->label_hint->Name = L"label_hint";
			this->label_hint->Size = System::Drawing::Size(131, 36);
			this->label_hint->TabIndex = 16;
			this->label_hint->Text = L"Wskazówki: 0";
			// 
			// label_username
			// 
			this->label_username->AutoSize = true;
			this->label_username->Font = (gcnew System::Drawing::Font(L"Oswald", 15.25F, System::Drawing::FontStyle::Bold));
			this->label_username->ForeColor = System::Drawing::SystemColors::Control;
			this->label_username->Location = System::Drawing::Point(5, 24);
			this->label_username->Name = L"label_username";
			this->label_username->Size = System::Drawing::Size(74, 36);
			this->label_username->TabIndex = 14;
			this->label_username->Text = L"Nazwa:";
			// 
			// label_points
			// 
			this->label_points->AutoSize = true;
			this->label_points->Font = (gcnew System::Drawing::Font(L"Oswald", 15.25F, System::Drawing::FontStyle::Bold));
			this->label_points->ForeColor = System::Drawing::SystemColors::Control;
			this->label_points->Location = System::Drawing::Point(5, 60);
			this->label_points->Name = L"label_points";
			this->label_points->Size = System::Drawing::Size(87, 36);
			this->label_points->TabIndex = 13;
			this->label_points->Text = L"Punkty: ";
			// 
			// label_wrong_guess
			// 
			this->label_wrong_guess->AutoSize = true;
			this->label_wrong_guess->Font = (gcnew System::Drawing::Font(L"Oswald", 15.25F, System::Drawing::FontStyle::Bold));
			this->label_wrong_guess->ForeColor = System::Drawing::SystemColors::Control;
			this->label_wrong_guess->Location = System::Drawing::Point(6, 60);
			this->label_wrong_guess->Name = L"label_wrong_guess";
			this->label_wrong_guess->Size = System::Drawing::Size(99, 36);
			this->label_wrong_guess->TabIndex = 11;
			this->label_wrong_guess->Text = L"B³êdne: 0";
			// 
			// label_right_guess
			// 
			this->label_right_guess->AutoSize = true;
			this->label_right_guess->Font = (gcnew System::Drawing::Font(L"Oswald", 15.25F, System::Drawing::FontStyle::Bold));
			this->label_right_guess->ForeColor = System::Drawing::SystemColors::Control;
			this->label_right_guess->Location = System::Drawing::Point(6, 24);
			this->label_right_guess->Name = L"label_right_guess";
			this->label_right_guess->Size = System::Drawing::Size(123, 36);
			this->label_right_guess->TabIndex = 10;
			this->label_right_guess->Text = L"Poprawne: 0";
			// 
			// label_difficulty
			// 
			this->label_difficulty->AutoSize = true;
			this->label_difficulty->Font = (gcnew System::Drawing::Font(L"Oswald", 15.25F, System::Drawing::FontStyle::Bold));
			this->label_difficulty->ForeColor = System::Drawing::SystemColors::Control;
			this->label_difficulty->Location = System::Drawing::Point(6, 24);
			this->label_difficulty->Name = L"label_difficulty";
			this->label_difficulty->Size = System::Drawing::Size(105, 36);
			this->label_difficulty->TabIndex = 8;
			this->label_difficulty->Text = L"Trudnoœæ: ";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Oswald", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(345, 519);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 49);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &GameForm::reset_button_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_username);
			this->groupBox1->Controls->Add(this->label_points);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Oswald", 10.25F, System::Drawing::FontStyle::Bold));
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(48, 121);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(302, 103);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Informacje";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label_difficulty);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Oswald", 10.25F, System::Drawing::FontStyle::Bold));
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(48, 230);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(302, 140);
			this->groupBox2->TabIndex = 18;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ustawienia";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label_right_guess);
			this->groupBox3->Controls->Add(this->label_wrong_guess);
			this->groupBox3->Controls->Add(this->label_hint);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Oswald", 10.25F, System::Drawing::FontStyle::Bold));
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(48, 376);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(302, 136);
			this->groupBox3->TabIndex = 19;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Wpisy";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Oswald", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(29, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(343, 109);
			this->label3->TabIndex = 7;
			this->label3->Text = L"STATYSTYKI";
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Teal;
			this->ClientSize = System::Drawing::Size(896, 579);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->table);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"GameForm";
			this->Text = L"Sudoku - Patryk Pszeniczny :: v1.0";
			this->table->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
