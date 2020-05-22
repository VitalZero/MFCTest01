#include "MainFrame.h"

BEGIN_MESSAGE_MAP( MainFrame, CFrameWnd )
	ON_WM_CREATE()
	ON_COMMAND( 1002, MainFrame::OnGuardarClick )
	ON_COMMAND( 1003, MainFrame::OnCargarClick )
END_MESSAGE_MAP()

int MainFrame::OnCreate( LPCREATESTRUCT lpCreateStruct )
{

	if ( CFrameWnd::OnCreate( lpCreateStruct ) == 0 )
	{
		MessageBox( L"The Window has been created!" );

		edit = new CEdit;
		edit->Create( WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_NOHIDESEL,
			CRect( 10, 10, 110, 34 ), this, 1001 );

		edit->SetFocus();

		btnGuardar = new CButton;
		btnGuardar->Create( L"Guardar", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
			CRect( 10, 70, 75, 93 ), this, 1002 );

		btnCargar = new CButton;
		btnCargar->Create( L"Cargar", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
			CRect( 85, 70, 160, 93 ), this, 1003 );

		// Get the system message box font
		NONCLIENTMETRICS ncm;
		ncm.cbSize = sizeof( ncm );
		SystemParametersInfo( SPI_GETNONCLIENTMETRICS, ncm.cbSize, &ncm, 0 );
		LOGFONT lfDlgFont = ncm.lfMessageFont;

		font.CreateFontIndirect( &lfDlgFont );

		edit->SetFont( &font );
		btnGuardar->SetFont( &font );
		btnCargar->SetFont( &font );

		return 0;
	}
	return -1;
}

void MainFrame::OnGuardarClick()
{
	requis.Guardar();
	//requis.Cargar();

	MessageBox( L"Hola mundo!" );
}

void MainFrame::OnCargarClick()
{
	ColeccionRequis rs;
	rs.Cargar();
	CString str;
	str.Format( L"Numero de requi: %d", rs.Lista().GetAt( 0 ).NumRequi() );

	MessageBox( str );
}
