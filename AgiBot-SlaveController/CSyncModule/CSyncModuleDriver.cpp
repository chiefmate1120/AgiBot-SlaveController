///////////////////////////////////////////////////////////////////////////////
// CSyncModuleDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "CSyncModuleDriver.h"
#include "CSyncModuleClassFactory.h"

DECLARE_GENERIC_DEVICE(CSYNCMODULEDRV)

IOSTATUS CCSyncModuleDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CCSyncModuleClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CCSyncModuleDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CCSyncModuleDriver::CSYNCMODULEDRV_GetVersion( )
{
	return( (CSYNCMODULEDRV_Major << 8) | CSYNCMODULEDRV_Minor );
}

