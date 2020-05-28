#pragma once

#include "ColeccionRequis.h"
#include <afxwin.h>
#include <afxcview.h>

class MainFrame : public CFrameWnd
{
public:
	MainFrame()
	{
		Create( NULL, "MFC App tutorial", WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
			CRect( 100, 100, 700, 600 ) );

		requis.Insertar( 22334, 4567800, "01/05/2020" );
		requis.Insertar( 21345, 1672000, "01/04/2020" );
		requis.Insertar( 22386, 1725996, "20/05/2020" );
	}

protected:
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	void OnGuardarClick();
	void OnCargarClick();
	DECLARE_MESSAGE_MAP()

private:
	void CreateControls();
	void CreateListView();

private:
	CEdit* edit = nullptr;
	CButton* btnGuardar = nullptr;
	CButton* btnCargar = nullptr;
	CListCtrl* listView = nullptr;
	CFont font;
	ColeccionRequis requis;
};