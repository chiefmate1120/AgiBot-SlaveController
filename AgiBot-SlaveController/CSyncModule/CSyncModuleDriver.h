///////////////////////////////////////////////////////////////////////////////
// CSyncModuleDriver.h

#ifndef __CSYNCMODULEDRIVER_H__
#define __CSYNCMODULEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define CSYNCMODULEDRV_NAME        "CSYNCMODULE"
#define CSYNCMODULEDRV_Major       1
#define CSYNCMODULEDRV_Minor       0

#define DEVICE_CLASS CCSyncModuleDriver

#include "ObjDriver.h"

class CCSyncModuleDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl CSYNCMODULEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(CSYNCMODULEDRV)
	VxD_Service( CSYNCMODULEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __CSYNCMODULEDRIVER_H__