#pragma once
#include "TcDef.h"
#include "TcBase.h"
#include "TcError.h"
#include "OsBase.h"
#include "AdsR0.h"
#include "Ams.h"
#include "Ads.h"

//sample specific invokeids
//please implement own handling of invokeids!
const ULONG NOTSAMPLE_INVOKEID_GETHDL_MAINPLCVAR = 0x00000001;
const ULONG NOTSAMPLE_INVOKEID_WRITEDATA_MAINPLCVAR = 0x00000002;
const ULONG NOTSAMPLE_INVOKEID_DELNOTIFICATION_MAINPLCVAR = 0x00000003;
const ULONG NOTSAMPLE_INVOKEID_RELEASEHDL_MAINPLCVAR = 0x00000004;


class ADSPLCRW: public CAdsR0FifoPort
{
public:
	ADSPLCRW() = default;
	~ADSPLCRW();

	void init();

	void writeByName();

	int m_varHandRes;
protected:
	// port
	long nErr, nPort;

	// AMS address
	AmsAddr	m_Addr;

	BOOL m_writeData=true;



};
