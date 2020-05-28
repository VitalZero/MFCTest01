#include "Requisicion.h"

Requi::Requi( const Requi & otro )
{
	*this = otro;
}

Requi & Requi::operator=( const Requi & otro )
{
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
	Documentos documento, unsigned short int impuesto,
	const CString& fechaSolicitud, const CString& fechaAutorizado )
	:
	requi(requi), monto(monto), fechaOrigen(fechaOrigen), documento( Documentos::Nada ),
	estado( Estatus::Libre ),	impuesto( impuesto ), fechaSolicitud( fechaSolicitud ), 
	fechaAutorizado( fechaAutorizado )
{}

void Requi::Serialize( CArchive& ar )
{
	CObject::Serialize( ar );

	if ( ar.IsStoring() )
	{
		ar << version << requi << monto << estado << documento << impuesto << fechaOrigen
			<< fechaSolicitud << fechaAutorizado;
	}
	else
	{
		char tmpVersion;

		ar >> tmpVersion;

		if ( tmpVersion != version )
			throw CString( "Version de requisicion invalida." );

		ar >> requi >> monto >> estado >> documento >> impuesto >> fechaOrigen
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
