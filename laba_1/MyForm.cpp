#include "MyForm.h"
#include <windows.h>

using namespace System;
using namespace System::Text;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    laba1::MyForm form;
    Application::Run(% form);
}