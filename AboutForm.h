#pragma once

namespace szablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AboutForm : public System::Windows::Forms::Form {
	public:
		AboutForm(void);

	protected:
		~AboutForm() {
			if (components) {
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label_university;
		System::Windows::Forms::Label^ label_instruction;
		System::Windows::Forms::GroupBox^ groupBox_info;
		System::Windows::Forms::Label^ label_name;
		System::Windows::Forms::Label^ label_course;
		System::Windows::Forms::Label^ label_group;
		System::Windows::Forms::Label^ label_year;
		System::Windows::Forms::PictureBox^ pictureBox_logo;

	protected:
		void form_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->pictureBox_logo = (gcnew System::Windows::Forms::PictureBox());
			this->label_university = (gcnew System::Windows::Forms::Label());
			this->label_instruction = (gcnew System::Windows::Forms::Label());
			this->groupBox_info = (gcnew System::Windows::Forms::GroupBox());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->label_course = (gcnew System::Windows::Forms::Label());
			this->label_group = (gcnew System::Windows::Forms::Label());
			this->label_year = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_logo))->BeginInit();
			this->groupBox_info->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox_logo
			// 
			this->pictureBox_logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_logo.Image")));
			this->pictureBox_logo->Location = System::Drawing::Point(0, -2);
			this->pictureBox_logo->Name = L"pictureBox_logo";
			this->pictureBox_logo->Size = System::Drawing::Size(512, 512);
			this->pictureBox_logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_logo->TabIndex = 0;
			this->pictureBox_logo->TabStop = false;
			// 
			// label_university
			// 
			this->label_university->AutoSize = true;
			this->label_university->BackColor = System::Drawing::Color::Transparent;
			this->label_university->Font = (gcnew System::Drawing::Font(L"Oswald", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_university->ForeColor = System::Drawing::Color::White;
			this->label_university->Location = System::Drawing::Point(177, 426);
			this->label_university->Name = L"label_university";
			this->label_university->Size = System::Drawing::Size(166, 26);
			this->label_university->TabIndex = 9;
			this->label_university->Text = L"Politechnika Koszaliñska";
			// 
			// label_instruction
			// 
			this->label_instruction->AutoSize = true;
			this->label_instruction->Font = (gcnew System::Drawing::Font(L"Oswald", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_instruction->ForeColor = System::Drawing::Color::White;
			this->label_instruction->Location = System::Drawing::Point(14, 452);
			this->label_instruction->Name = L"label_instruction";
			this->label_instruction->Size = System::Drawing::Size(483, 46);
			this->label_instruction->TabIndex = 10;
			this->label_instruction->Text = L"Naciœnij klawisz \'P\', aby zamkn¹æ to okno.";
			// 
			// groupBox_info
			// 
			this->groupBox_info->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_info->Controls->Add(this->label_name);
			this->groupBox_info->Controls->Add(this->label_course);
			this->groupBox_info->Controls->Add(this->label_group);
			this->groupBox_info->Controls->Add(this->label_year);
			this->groupBox_info->Font = (gcnew System::Drawing::Font(L"Oswald", 11.25F, System::Drawing::FontStyle::Bold));
			this->groupBox_info->ForeColor = System::Drawing::Color::White;
			this->groupBox_info->Location = System::Drawing::Point(12, 12);
			this->groupBox_info->Name = L"groupBox_info";
			this->groupBox_info->Size = System::Drawing::Size(251, 105);
			this->groupBox_info->TabIndex = 12;
			this->groupBox_info->TabStop = false;
			this->groupBox_info->Text = L"Dane";
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Oswald", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_name->Location = System::Drawing::Point(6, 26);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(131, 27);
			this->label_name->TabIndex = 1;
			this->label_name->Text = L"Patryk Pszeniczny";
			this->label_name->Click += gcnew System::EventHandler(this, &AboutForm::label_name_Click);
			// 
			// label_course
			// 
			this->label_course->AutoSize = true;
			this->label_course->Font = (gcnew System::Drawing::Font(L"Oswald", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_course->Location = System::Drawing::Point(7, 48);
			this->label_course->Name = L"label_course";
			this->label_course->Size = System::Drawing::Size(196, 27);
			this->label_course->TabIndex = 2;
			this->label_course->Text = L"Informatyka Niestacjonarny";
			this->label_course->Click += gcnew System::EventHandler(this, &AboutForm::label_course_Click);
			// 
			// label_group
			// 
			this->label_group->AutoSize = true;
			this->label_group->Font = (gcnew System::Drawing::Font(L"Oswald", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_group->Location = System::Drawing::Point(7, 70);
			this->label_group->Name = L"label_group";
			this->label_group->Size = System::Drawing::Size(140, 27);
			this->label_group->TabIndex = 3;
			this->label_group->Text = L"Semetr III, Grupa II";
			this->label_group->Click += gcnew System::EventHandler(this, &AboutForm::label_group_Click);
			// 
			// label_year
			// 
			this->label_year->AutoSize = true;
			this->label_year->Font = (gcnew System::Drawing::Font(L"Oswald", 12, System::Drawing::FontStyle::Bold));
			this->label_year->Location = System::Drawing::Point(144, 70);
			this->label_year->Name = L"label_year";
			this->label_year->Size = System::Drawing::Size(45, 27);
			this->label_year->TabIndex = 4;
			this->label_year->Text = L"2024";
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Teal;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(509, 507);
			this->Controls->Add(this->groupBox_info);
			this->Controls->Add(this->label_instruction);
			this->Controls->Add(this->label_university);
			this->Controls->Add(this->pictureBox_logo);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AboutForm";
			this->Text = L"Sudoku - Patryk Pszeniczny :: v1.0";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AboutForm::form_KeyPress);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_logo))->EndInit();
			this->groupBox_info->ResumeLayout(false);
			this->groupBox_info->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label_name_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label_course_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label_group_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
