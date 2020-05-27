#include "ColeccionRequis.h"
#include <afxwin.h>
#include <exception>

void ColeccionRequis::Insertar(unsigned int requi, unsigned long monto, 
	const CString& fechaOrigen, Requi::Documentos documento, unsigned short int impuesto )
{
	Requi r( requi, monto, fechaOrigen, documento, impuesto );

	requisiciones.Add( r );
}

void ColeccionRequis::Guardar()
{
	CFile file;
	file.Open( "datos.txt", CFile::modeCreate | CFile::modeWrite );
	CArchive ar( &file, CArchive::store );

	int numRequis = requisiciones.GetSize();

	Encabezado encabezado( numRequis );

	encabezado.Serialize( ar );

	for ( int i = 0; i < numRequis; ++i )
	{
		requisiciones.GetAt(i).Serialize( ar );
	}
	ar.Close();
	file.Close();
}

void ColeccionRequis::Cargar()
{
	requisiciones.RemoveAll();

	CFile file;
	file.Open( "datos.txt", CFile::modeRead );
	CArchive ar( &file, CArchive::load );

	Encabezado encabezado( 0 );

	encabezado.Serialize( ar );

	if ( encabezado.NumRequis() > 0 )
	{
		for ( int i = 0; i < encabezado.NumRequis(); ++i )
		{
			Requi r;
			r.Serialize( ar );

			requisiciones.Add( r );
		}
	}
	ar.Close();
	file.Close();
}

void ColeccionRequis::SolicitarRequi( int requi, const CString & fechaSolicitud )
{
	for ( int i = 0; i < requisiciones.GetCount(); ++i )
	{
		Requi& r = requisiciones.GetAt( i );
		if ( r.NumRequi() == requi )
		{
			r.Solicitar( fechaSolicitud );
		}
	}
}

void ColeccionRequis::AutorizarRequi( int requi, const CString & fechaAutorizado )
{
	for ( int i = 0; i < requisiciones.GetCount(); ++i )
	{
		Requi& r = requisiciones.GetAt( i );
		if ( r.NumRequi() == requi )
		{
			r.Autorizar( fechaAutorizado );
		}
	}
}

void ColeccionRequis::GuardarEncabezado( CArchive& ar, Encabezado& encabezado )
{
	encabezado.Serialize( ar );
}

bool ColeccionRequis::LeerEncabezado( CArchive& ar, Encabezado& encabezado )
{
	try
	{
		encabezado.Serialize( ar );
	}
	catch ( CString& e )
	{
		CString errorMsg = "Error al cargar el archivo: ";
		
		return false;
	}

	return true;
}
