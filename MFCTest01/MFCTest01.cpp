#include <afxwin.h>

class MainFrame : public CFrameWnd
{
public:
	MainFrame()
	{
		Create( NULL, L"MFC App tutorial", WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
			CRect( 100, 100, 500, 300 ) );
	}

protected:
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	DECLARE_MESSAGE_MAP()
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
		return 0;
	}

	return -1;
}
