///////////////////////////////////////////////////////////////////////////////
// CSyncModulesDriver.h

#ifndef __CSYNCMODULESDRIVER_H__
#define __CSYNCMODULESDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define CSYNCMODULESDRV_NAME        "CSYNCMODULES"
#define CSYNCMODULESDRV_Major       1
#define CSYNCMODULESDRV_Minor       0

#define DEVICE_CLASS CCSyncModulesDriver

#include "ObjDriver.h"

class CCSyncModulesDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl CSYNCMODULESDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(CSYNCMODULESDRV)
	VxD_Service( CSYNCMODULESDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __CSYNCMODULESDRIVER_H__