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
		ar << firma << versionMayor << versionMenor << numRequis;
	}
	else
	{
		CString tmpFirma;
		ar >> tmpFirma;

		if ( tmpFirma != firma )
			throw CString( "Tipo de archivo diferente" );
		
		char tmpVMaj;
		char tmpVMin;

		ar >> tmpVMaj >> tmpVMin;
		
		if ( tmpVMaj != versionMayor || tmpVMin != versionMenor )
			throw CString( "Versi�n inv�lida" );
		
		ar >> numRequis;
	}
}
