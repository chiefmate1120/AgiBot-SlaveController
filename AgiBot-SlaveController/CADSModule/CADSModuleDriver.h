///////////////////////////////////////////////////////////////////////////////
// CADSModuleDriver.h

#ifndef __CADSMODULEDRIVER_H__
#define __CADSMODULEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define CADSMODULEDRV_NAME        "CADSMODULE"
#define CADSMODULEDRV_Major       1
#define CADSMODULEDRV_Minor       0

#define DEVICE_CLASS CCADSModuleDriver

#include "ObjDriver.h"

class CCADSModuleDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl CADSMODULEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(CADSMODULEDRV)
	VxD_Service( CADSMODULEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __CADSMODULEDRIVER_H__