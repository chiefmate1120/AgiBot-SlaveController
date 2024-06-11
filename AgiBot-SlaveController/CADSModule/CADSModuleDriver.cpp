///////////////////////////////////////////////////////////////////////////////
// CADSModuleDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "CADSModuleDriver.h"
#include "CADSModuleClassFactory.h"

DECLARE_GENERIC_DEVICE(CADSMODULEDRV)

IOSTATUS CCADSModuleDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CCADSModuleClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CCADSModuleDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CCADSModuleDriver::CADSMODULEDRV_GetVersion( )
{
	return( (CADSMODULEDRV_Major << 8) | CADSMODULEDRV_Minor );
}

