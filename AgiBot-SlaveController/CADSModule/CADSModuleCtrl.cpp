// CADSModuleCtrl.cpp : Implementation of CTcCADSModuleCtrl
#include "TcPch.h"
#pragma hdrstop

#include "CADSModuleW32.h"
#include "CADSModuleCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CCADSModuleCtrl

CCADSModuleCtrl::CCADSModuleCtrl() 
	: ITcOCFCtrlImpl<CCADSModuleCtrl, CCADSModuleClassFactory>() 
{
}

CCADSModuleCtrl::~CCADSModuleCtrl()
{
}

