#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <afxwin.h>
#include "MainFrame.h"

class MFCTest : public CWinApp
{
public:
	BOOL InitInstance()
	{
		MainFrame* mainFrame = new MainFrame();
		m_pMainWnd = mainFrame;

		mainFrame->ShowWindow( SW_NORMAL );
		mainFrame->UpdateWindow();

		return TRUE;
	}

private:
	//MainFrame* mainFrame = nullptr;
};

MFCTest app;