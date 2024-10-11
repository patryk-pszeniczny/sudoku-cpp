#pragma once
#include "SudokuGenerate.h"
namespace szablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class MainForm : public System::Windows::Forms::Form

	{
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ entries_label;
	public:
		SudokuGenerate* generator;
		MainForm(void);
		int entries;
		int entries_wrong;
	private:
		void CreateTextBoxes();
		void CreateTextBox(TableLayoutPanel^ parentTable, int row, int col);
		void TextBox_KeyPress(Object^ sender, KeyPressEventArgs^ e);
		void LockedTextBox_Click(Object^ sender, EventArgs^ e);
	protected:
		~MainForm(){
			if (components){
				delete components;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
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
			this->entries_label = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->table->SuspendLayout();
			this->panel1->SuspendLayout();
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
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Oswald", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(65, 178);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 46);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Solutions:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Oswald", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(65, 224);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 46);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Samplings: ";
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
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(19)), static_cast<System::Int32>(static_cast<System::Byte>(19)),
				static_cast<System::Int32>(static_cast<System::Byte>(19)));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->entries_label);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(512, -3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(385, 596);
			this->panel1->TabIndex = 8;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);
			// 
			// entries_label
			// 
			this->entries_label->AutoSize = true;
			this->entries_label->Font = (gcnew System::Drawing::Font(L"Oswald", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->entries_label->ForeColor = System::Drawing::SystemColors::Control;
			this->entries_label->Location = System::Drawing::Point(65, 270);
			this->entries_label->Name = L"entries_label";
			this->entries_label->Size = System::Drawing::Size(171, 46);
			this->entries_label->TabIndex = 9;
			this->entries_label->Text = L"Entries: [0/0]";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Oswald", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(65, 132);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(214, 46);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Difficulty: Normal";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Oswald", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(29, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(343, 109);
			this->label3->TabIndex = 7;
			this->label3->Text = L"STATYSTYKI";
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
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click_1);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(896, 579);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->table);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->table->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->generator->checkSudoku()) {
			MessageBox::Show("BRAWO", "Wygra³eœ talon :3");
			return;
		}
		MessageBox::Show("Next time braku", ":(");

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int blockRow = 0; blockRow < 3; blockRow++) {
			for (int blockCol = 0; blockCol < 3; blockCol++) {
				TableLayoutPanel^ tb = dynamic_cast<TableLayoutPanel^>(this->table->GetControlFromPosition(blockCol, blockRow));
				if (tb != nullptr && ProcessBlock(tb, blockRow, blockCol)) {
					return;
				}
			}
		}
	}
	private: bool ProcessBlock(TableLayoutPanel^ tb, int blockRow, int blockCol) {
		for (int rowOffset = 0; rowOffset < 3; rowOffset++) {
			for (int colOffset = 0; colOffset < 3; colOffset++) {
				   int globalRow = blockRow * 3 + rowOffset;
				   int globalCol = blockCol * 3 + colOffset;
				   int value = this->generator->copy_board[globalRow][globalCol];

				   if (value != 0) {
					   UpdateTextBox(tb, rowOffset, colOffset, value);
					   this->generator->board[globalRow][globalCol] = value;
					   this->generator->copy_board[globalRow][globalCol] = 0;
					   return true;
				   }
			   }
		}
		return false;
	}
		  
	private: void UpdateTextBox(TableLayoutPanel^ tb, int rowOffset, int colOffset, int value) {
		TextBox^ textBox = dynamic_cast<TextBox^>(tb->GetControlFromPosition(colOffset, rowOffset));
		if (textBox != nullptr) {
			//251 66 66
			textBox->BackColor = System::Drawing::Color::FromArgb(
				static_cast<System::Int32>(static_cast<System::Byte>(173)), 
				static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			textBox->Text = value.ToString();
			textBox->ForeColor = System::Drawing::SystemColors::Control;
			textBox->Enabled = false;
			textBox->ReadOnly = true;
		}
	}
	
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
