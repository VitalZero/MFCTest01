#pragma once
#include "Requisicion.h"
//#include <vector>
#include "Encabezado.h"

using Requisiciones = CArray<Requi, Requi>;

class ColeccionRequis
{
public:
	void Insertar( unsigned int requi, unsigned long monto,
		const CString& fechaOrigen, Requi::Documentos documento = Requi::Documentos::Nada, 
		unsigned short int impuesto  = 16);
	void Guardar();
	void Cargar();
	const Requisiciones& Lista() const { return requisiciones; }
	void SolicitarRequi( int requi, const CString& fechaSolicitud );
	void AutorizarRequi( int requi, const CString& fechaAutorizado );

private:
	void GuardarEncabezado( CArchive& ar, Encabezado& encabezado );
	bool LeerEncabezado( CArchive& ar, Encabezado& encabezado );

private:
	//std::vector<Requi> otrarequi;
	Requisiciones requisiciones;
};