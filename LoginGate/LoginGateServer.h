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
	*  服务器启动
	*/
	bool StartServer(unsigned short nPort);			//启动服务器


	/*
	* 服务器关闭
	*/
	bool StopServer();								//服务器关闭

	/*
	* 连接其他服务器
	*/
	bool ConnectServer(char * szIp,int nPort,void *pSrvInfo,int nReconnectTime);

protected:
	/*
	 *	服务器主线程
	 */
	void* Main(void* pParam);
	
	/**
	 * 新连接事件回调方法
	 * 
	 * 派生类实现具体连接业务处理
	 * 
	 */
	void OnConnect(mdk::NetHost& host);
	/**
	 * 连接关闭事件，回调方法
	 * 
	 * 派生类实现具体断开连接业务处理
	 * 
	 */
	void OnCloseConnect(mdk::NetHost& host);
	/**
	 * 数据到达，回调方法
	 * 
	 * 派生类实现具体断开连接业务处理
	 * 
	*/
	void OnMsg(mdk::NetHost& host);
};

#endif // _LOGINGATESERVER_H_)
