///////////////////////////////////////////////////////////////////////////////
// CSyncModulesCtrl.h

#ifndef __CSYNCMODULESCTRL_H__
#define __CSYNCMODULESCTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "CSyncModulesW32.h"
#include "TcBase.h"
#include "CSyncModulesClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CCSyncModulesCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CCSyncModulesCtrl, &CLSID_CSyncModulesCtrl>
	, public ICSyncModulesCtrl
	, public ITcOCFCtrlImpl<CCSyncModulesCtrl, CCSyncModulesClassFactory>
{
public:
	CCSyncModulesCtrl();
	virtual ~CCSyncModulesCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_CSYNCMODULESCTRL)
DECLARE_NOT_AGGREGATABLE(CCSyncModulesCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCSyncModulesCtrl)
	COM_INTERFACE_ENTRY(ICSyncModulesCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __CSYNCMODULESCTRL_H__
