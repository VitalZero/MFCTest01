#pragma once
#include <afxwin.h>

class Requi : public CObject
{
public:
	enum Estatus : char
	{
		Libre = 'L', Solicitado = 'S', Autorizado = 'A', Rechazado = 'R', Cancelado = 'C'
	};

public:
	Requi() {}
	Requi( const Requi& otro );
	Requi& operator=( const Requi& otro );
	Requi(unsigned int requi, unsigned long monto, const CString& fechaOrigen, 
		unsigned short int impuesto );
	~Requi() {}

public:
	void Serialize( CArchive& ar );
	void Solicitar( const CString& fechaSolicitud );
	void Autorizar( const CString& fechaAutorizado );
	unsigned int NumRequi() const
	{
		return requi;
	}
	DECLARE_SERIAL( Requi )

private:
	unsigned int requi;
  char estado;
	CString fechaOrigen;
	CString fechaSolicitud;
	CString fechaAutorizado;
	unsigned long monto;
	unsigned short int impuesto;
};