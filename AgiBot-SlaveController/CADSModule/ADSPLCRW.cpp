#include "ADSPLCRW.h"
#include "Ams.h"

ADSPLCRW::~ADSPLCRW()
{
//	nErr = AdsPortClose();
}
void ADSPLCRW::init()
{
	m_Addr.netId = AmsGetNetId();
	m_Addr.netId.b[0] = 192;
	m_Addr.netId.b[1] = 168;
	m_Addr.netId.b[2] = 0;
	m_Addr.netId.b[3] = 102;
	m_Addr.netId.b[4] = 1;
	m_Addr.netId.b[5] = 1;
	// and the default PLC port: 
	m_Addr.port = 851;
	char PLCVar[] = { "CartControl.PlcVar" };
	m_varHandRes= AdsReadWriteReq(m_Addr, NOTSAMPLE_INVOKEID_GETHDL_MAINPLCVAR, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(m_writeData), sizeof(PLCVar), PLCVar);
	m_varHandRes = S_OK;
}

void ADSPLCRW::writeByName()
{
	ULONG lHdlTime, lHdlDate, lHdlVar1;

//	if (m_varHandRes != S_OK) {
//		return;
//	}
	m_Addr.netId = AmsGetNetId();
	m_Addr.netId.b[0] = 192;
	m_Addr.netId.b[1] = 168;
	m_Addr.netId.b[2] = 0;
	m_Addr.netId.b[3] = 102;
	m_Addr.netId.b[4] = 1;
	m_Addr.netId.b[5] = 1;
	// and the default PLC port: 
	m_Addr.port = 354;
	
	m_writeData = !m_writeData;
	nErr = AdsWriteReq(m_Addr, NOTSAMPLE_INVOKEID_WRITEDATA_MAINPLCVAR , 0x8502000, 0x81064405, sizeof(m_writeData), &m_writeData);
	//nErr = AdsWriteReq(m_Addr, NOTSAMPLE_INVOKEID_RELEASEHDL_MAINPLCVAR, ADSIGRP_SYM_RELEASEHND, 0, sizeof(m_writeData), &m_writeData);
		
}