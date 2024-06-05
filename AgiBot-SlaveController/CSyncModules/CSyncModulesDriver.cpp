///////////////////////////////////////////////////////////////////////////////
// CSyncModulesDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "CSyncModulesDriver.h"
#include "CSyncModulesClassFactory.h"

DECLARE_GENERIC_DEVICE(CSYNCMODULESDRV)

IOSTATUS CCSyncModulesDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CCSyncModulesClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CCSyncModulesDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CCSyncModulesDriver::CSYNCMODULESDRV_GetVersion( )
{
	return( (CSYNCMODULESDRV_Major << 8) | CSYNCMODULESDRV_Minor );
}

