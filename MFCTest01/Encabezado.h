#pragma once
#include <afxwin.h>

class Encabezado : public CObject
{
public:
	Encabezado( unsigned int numRequis );

public:
	void Serialize( CArchive& ar ) override;
	unsigned int NumRequis() const
	{
		return numRequis;
	}

private:
	unsigned int numRequis;
	static constexpr char versionMayor = 1;
	static constexpr char versionMenor = 0;
	const CString firma = L"VZ";
};