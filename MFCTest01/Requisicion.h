#pragma once
#include <afxwin.h>

class Requi : public CObject
{
public:
	enum Estatus : char
	{
		Libre = 'L', Solicitado = 'S', Autorizado = 'A', Rechazado = 'R', Cancelado = 'C'
	};
	enum Documentos : char
	{
		Cotizacion = 'C', Factura = 'F', Nada = 'N'
	};

public:
	Requi() {}
	Requi( const Requi& otro );
	Requi& operator=( const Requi& otro );
	Requi(unsigned int requi, unsigned long monto, const CString& fechaOrigen, 
		Documentos documento = Documentos::Nada, unsigned short int impuesto = 16);
	~Requi() = default;

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
	char documento;
	CString fechaOrigen;
	CString fechaSolicitud;
	CString fechaAutorizado;
	unsigned long monto;
	unsigned short int impuesto;
};