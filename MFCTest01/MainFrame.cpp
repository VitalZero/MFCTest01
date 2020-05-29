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

		return 0;
	}
	return -1;
}

void MainFrame::OnGuardarClick()
{
	requis.Guardar();

	MessageBox( "Se guardaron los datos" );
}

void MainFrame::OnCargarClick()
{
	ColeccionRequis rs;
	rs.Cargar();
	int sz = rs.Lista().GetSize();

	CString str( "Requisiciones:\n" );

	for ( int i = 0; i < sz; ++i )
	{
		str.AppendFormat( "Numero de requi: %d\n", rs.Lista().GetAt( i ).NumRequi() );
	}

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
	listView->InsertColumn( 0, "Requisicion", 0, 80, 0 );
	listView->InsertColumn( 1, "Monto", 0, 80, 1 );
	listView->InsertColumn( 2, "Fecha Origen", 0, 90, 2 );
	listView->InsertColumn( 3, "IVA", 0, 40, 3 );

	ColeccionRequis rs;
	rs.Cargar();
	int sz = rs.Lista().GetSize();

	CString str;

	for ( int i = 0; i < sz; ++i )
	{
		str.Format( "%d", rs.Lista().GetAt( i ).NumRequi() );
		listView->InsertItem( 0, str.GetBuffer() );

		str.Format( "%d", rs.Lista().GetAt( i ).Monto() );
		str.Insert( str.GetLength() - 2, "." );
		listView->SetItemText( 0, 1, str.GetBuffer() );

		str = rs.Lista().GetAt( i ).FechaOrigen();
		listView->SetItemText( 0, 2, str.GetBuffer() );

		str.Format( "%d", rs.Lista().GetAt( i ).TasaIVA() );
		listView->SetItemText( 0, 3, str.GetBuffer() );

		//str.AppendFormat( "Numero de requi: %d\n", rs.Lista().GetAt( i ).NumRequi() );
	}

}
