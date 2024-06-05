// CSyncModuleCtrl.cpp : Implementation of CTcCSyncModuleCtrl
#include "TcPch.h"
#pragma hdrstop

#include "CSyncModuleW32.h"
#include "CSyncModuleCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CCSyncModuleCtrl

CCSyncModuleCtrl::CCSyncModuleCtrl() 
	: ITcOCFCtrlImpl<CCSyncModuleCtrl, CCSyncModuleClassFactory>() 
{
}

CCSyncModuleCtrl::~CCSyncModuleCtrl()
{
}

