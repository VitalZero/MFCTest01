#pragma once

#include "ColeccionRequis.h"
#include <afxwin.h>

class MainFrame : public CFrameWnd
{
public:
	MainFrame()
	{
		Create( NULL, L"MFC App tutorial", WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
			CRect( 100, 100, 500, 300 ) );

		requis.Insertar( 22334, 4567800, "01/05/2020" );
		requis.Insertar( 21345, 1672000, "01/04/2020", 16 );
	}

protected:
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	void OnGuardarClick();
	void OnCargarClick();
	DECLARE_MESSAGE_MAP()

private:
	CEdit* edit = nullptr;
	CButton* btnGuardar = nullptr;
	CButton* btnCargar = nullptr;
	CFont font;
	ColeccionRequis requis;
};