#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <afxwin.h>

class MainFrame : public CFrameWnd
{
public:
	MainFrame()
	{
		Create( NULL, L"MFC App tutorial", WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
			CRect( 100, 100, 500, 300 ) );
	}
	~MainFrame()
	{
		delete edit;
		edit = nullptr;
	}

protected:
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	DECLARE_MESSAGE_MAP()

private:
	CEdit* edit = nullptr;
	CButton* button = nullptr;
	CFont font;
};

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
};

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

MFCTest app;

int MainFrame::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if ( CFrameWnd::OnCreate( lpCreateStruct ) == 0 )
	{
		MessageBox( L"The Window has been created!" );

		edit = new CEdit();
		edit->Create( WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_NOHIDESEL,
			CRect( 10, 10, 110, 34 ), this, 1001 );
		edit->SetFocus();

		button = new CButton();
		button->Create( L"Aceptar", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
			CRect( 10, 70, 75, 93 ), this, 1002 );

		// Get the system message box font
		NONCLIENTMETRICS ncm;
		ncm.cbSize = sizeof( ncm );
		SystemParametersInfo( SPI_GETNONCLIENTMETRICS, ncm.cbSize, &ncm, 0 );
		LOGFONT lfDlgFont = ncm.lfMessageFont;
		
		font.CreateFontIndirect( &lfDlgFont );

		edit->SetFont( &font );
		button->SetFont( &font );

		return 0;
	}

	return -1;
}
