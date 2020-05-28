#include "Encabezado.h"
#include <exception>

Encabezado::Encabezado( unsigned int numRequis )
	:
	numRequis(numRequis)
{
}

void Encabezado::Serialize( CArchive & ar )
{
	if ( ar.IsStoring() )
	{
		ar << firma << version << numRequis;
	}
	else
	{
		CString tmpFirma;
		ar >> tmpFirma;

		if ( tmpFirma != firma )
			throw CString( "Tipo de archivo diferente" );
		
		char tmpVersion;

		ar >> tmpVersion;
		
		if ( tmpVersion != version )
			throw CString( "Versión inválida" );
		
		ar >> numRequis;
	}
}
