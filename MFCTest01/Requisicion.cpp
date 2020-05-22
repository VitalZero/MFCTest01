#include "Requisicion.h"

Requi::Requi( const Requi & otro )
{
	*this = otro;
}

Requi & Requi::operator=( const Requi & otro )
{
	// TODO: insertar una instrucción return aquí
	if ( this != &otro )
	{
		requi = otro.requi;
		estado = otro.estado;
		monto = otro.monto;
		fechaOrigen = otro.fechaOrigen;
		fechaSolicitud = otro.fechaSolicitud;
		fechaAutorizado = otro.fechaAutorizado;
		impuesto = otro.impuesto;
	}

	return *this;
}

IMPLEMENT_SERIAL( Requi, CObject, 0 )

Requi::Requi( unsigned int requi, unsigned long monto, const CString& fechaOrigen,
	unsigned short int impuesto = 16 )
	:
	requi(requi), monto(monto), fechaOrigen(fechaOrigen), estado( Estatus::Libre ),
	impuesto( impuesto ), fechaSolicitud("0"), fechaAutorizado("0")
{}

void Requi::Serialize( CArchive& ar )
{
	CObject::Serialize( ar );

	if ( ar.IsStoring() )
	{
		ar << requi << monto << estado << impuesto << fechaOrigen
			<< fechaSolicitud << fechaAutorizado;
	}
	else
	{
		ar >> requi >> monto >> estado >> impuesto >> fechaOrigen
			>> fechaSolicitud >> fechaAutorizado;
	}
}

void Requi::Solicitar( const CString & fechaSolicitud )
{
	estado = Estatus::Solicitado;
	this->fechaSolicitud = fechaSolicitud;
}

void Requi::Autorizar( const CString & fechaAutorizado )
{
	estado = Estatus::Autorizado;
	this->fechaAutorizado = fechaAutorizado;
}
