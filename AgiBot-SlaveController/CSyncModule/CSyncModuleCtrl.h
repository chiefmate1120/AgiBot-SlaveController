///////////////////////////////////////////////////////////////////////////////
// CSyncModuleCtrl.h

#ifndef __CSYNCMODULECTRL_H__
#define __CSYNCMODULECTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "CSyncModuleW32.h"
#include "TcBase.h"
#include "CSyncModuleClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CCSyncModuleCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CCSyncModuleCtrl, &CLSID_CSyncModuleCtrl>
	, public ICSyncModuleCtrl
	, public ITcOCFCtrlImpl<CCSyncModuleCtrl, CCSyncModuleClassFactory>
{
public:
	CCSyncModuleCtrl();
	virtual ~CCSyncModuleCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_CSYNCMODULECTRL)
DECLARE_NOT_AGGREGATABLE(CCSyncModuleCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCSyncModuleCtrl)
	COM_INTERFACE_ENTRY(ICSyncModuleCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __CSYNCMODULECTRL_H__
