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
		//MessageBox( "The Window has been created!" );
		CreateListView();
		CreateControls();
	
		listView->InsertItem( 0, "Hola mundo!", 0 );

		return 0;
	}
	return -1;
}

void MainFrame::OnGuardarClick()
{
	requis.Guardar();
	//requis.Cargar();

	MessageBox( "Hola mundo!" );
}

void MainFrame::OnCargarClick()
{
	ColeccionRequis rs;
	rs.Cargar();
	CString str;
	str.Format( "Numero de requi: %d", rs.Lista().GetAt( 0 ).NumRequi() );

	MessageBox( str );
}

void MainFrame::CreateControls()
{
	edit = new CEdit;
	edit->Create( WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_NOHIDESEL,
		CRect( 10, 350, 110, 373 ), this, 1001 );

	edit->SetFocus();

	btnGuardar = new CButton;
	btnGuardar->Create( "Guardar", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
		CRect( 10, 410, 85, 433 ), this, 1002 );

	btnCargar = new CButton;
	btnCargar->Create( "Cargar", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
		CRect( 92, 410, 167, 433 ), this, 1003 );

	// Get the system message box font
	NONCLIENTMETRICS ncm;
	ncm.cbSize = sizeof( ncm );
	SystemParametersInfo( SPI_GETNONCLIENTMETRICS, ncm.cbSize, &ncm, 0 );
	LOGFONT lfDlgFont = ncm.lfMessageFont;

	font.CreateFontIndirect( &lfDlgFont );

	edit->SetFont( &font );
	btnGuardar->SetFont( &font );
	btnCargar->SetFont( &font );
}

void MainFrame::CreateListView()
{
	listView = new CListCtrl;
	listView->Create( LVS_REPORT | WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
		CRect( 10, 10, 500, 200 ), this, 1004 );
	listView->SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );
	listView->InsertColumn( 1, "Requisicion", 0, 80, 0 );
	listView->InsertColumn( 2, "Monto", 0, 100, 1 );
	listView->InsertColumn( 2, "Fecha Origen", 0, 100, 2 );
	listView->InsertColumn( 2, "IVA", 0, 50, 3 );
}
