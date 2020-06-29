#include "pch.h"
#include <stdlib.h>
#include <time.h>

using namespace System;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}

#include "Form1.h"
#include "MyForm_menu.h"

using namespace System::Windows::Forms;

[STAThread]
int main() {
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 
	Application::Run(gcnew MenuJuego::MyForm_Menu());
	return 0;
}