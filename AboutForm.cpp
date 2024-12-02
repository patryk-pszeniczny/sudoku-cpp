#include "AboutForm.h"
namespace szablon {
	AboutForm::AboutForm(void) {
		InitializeComponent();
	}
	void AboutForm::form_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == 'P' || e->KeyChar == 'p') {
			this->Close();
		}

	}


}