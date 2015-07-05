// LoginGate.h: interface for the TestServer class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _LOGINGATESERVER_H_
#define _LOGINGATESERVER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "frame/netserver/NetServer.h"
#include "mdk/Singleton.h"


class CLoginGateServer : public mdk::NetServer  
{
public:
	CLoginGateServer();
	virtual ~CLoginGateServer();

	/*
	*  ����������
	*/
	bool StartServer(unsigned short nPort);			//����������


	/*
	* �������ر�
	*/
	bool StopServer();								//�������ر�

	/*
	* ��������������
	*/
	bool ConnectServer(char * szIp,int nPort,void *pSrvInfo,int nReconnectTime);

protected:
	/*
	 *	���������߳�
	 */
	void* Main(void* pParam);
	
	/**
	 * �������¼��ص�����
	 * 
	 * ������ʵ�־�������ҵ����
	 * 
	 */
	void OnConnect(mdk::NetHost& host);
	/**
	 * ���ӹر��¼����ص�����
	 * 
	 * ������ʵ�־���Ͽ�����ҵ����
	 * 
	 */
	void OnCloseConnect(mdk::NetHost& host);
	/**
	 * ���ݵ���ص�����
	 * 
	 * ������ʵ�־���Ͽ�����ҵ����
	 * 
	*/
	void OnMsg(mdk::NetHost& host);
};

#endif // _LOGINGATESERVER_H_)
