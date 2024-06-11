///////////////////////////////////////////////////////////////////////////////
// CADSModuleCtrl.h

#ifndef __CADSMODULECTRL_H__
#define __CADSMODULECTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "CADSModuleW32.h"
#include "TcBase.h"
#include "CADSModuleClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CCADSModuleCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CCADSModuleCtrl, &CLSID_CADSModuleCtrl>
	, public ICADSModuleCtrl
	, public ITcOCFCtrlImpl<CCADSModuleCtrl, CCADSModuleClassFactory>
{
public:
	CCADSModuleCtrl();
	virtual ~CCADSModuleCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_CADSMODULECTRL)
DECLARE_NOT_AGGREGATABLE(CCADSModuleCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCADSModuleCtrl)
	COM_INTERFACE_ENTRY(ICADSModuleCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __CADSMODULECTRL_H__
