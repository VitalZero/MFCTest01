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
		Documentos documento = Documentos::Nada, unsigned short int impuesto = 16,
		const CString& fechaSolicitud = "0", const CString& fechaAutorizado = "0");
	~Requi() = default;

public:
	void Serialize( CArchive& ar );
	void Solicitar( const CString& fechaSolicitud );
	void Autorizar( const CString& fechaAutorizado );
	unsigned int NumRequi() const	{ return requi;	}
	unsigned long Monto() const { return monto; }
	const CString& FechaOrigen() const { return fechaOrigen; }
	unsigned short int TasaIVA() const { return impuesto;  }
	DECLARE_SERIAL( Requi )

private:
	static constexpr char version = 1;
	unsigned int requi;
  char estado;
	char documento;
	CString fechaOrigen;
	CString fechaSolicitud;
	CString fechaAutorizado;
	unsigned long monto;
	unsigned short int impuesto;
};