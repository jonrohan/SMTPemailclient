#include "stdafx.h"
#include "mainEmailForm.h"
#include <windows.h>

using namespace SMTPemailclient;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;
	Application::Run(new mainEmailForm());
	return 0;
}