// CLoginGateServer.cpp: implementation of the CLoginGateServer class.
//
//////////////////////////////////////////////////////////////////////

#include "LoginGateServer.h"
#include <stdio.h>
#include <string.h>
#ifndef WIN32
#include <unistd.h>
#endif
#include <Windows.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLoginGateServer::CLoginGateServer()
{

	//Listen(8888);

	//Connect("10.10.10.82", 5678,NULL, 5);//连接自身，未测试，不建议这么做
}

CLoginGateServer::~CLoginGateServer()
{

}

/*
 *	服务器主线程
 */
void* CLoginGateServer::Main(void* pParam)
{
	while ( IsOk() )
	{
		//执行业务
#ifndef WIN32
		usleep( 1000 * 1000 );
#else
		Sleep( 1000 );
#endif
	}
	
	return 0;
}

/**
 * 新连接事件回调方法
 * 
 * 派生类实现具体连接业务处理
 * 当连接其他服务器时，可以host.IsServer来判断是否为一个服务器。
 * 操作同玩家操作一样。。
 *
 * 
 */
void CLoginGateServer::OnConnect(mdk::NetHost& host)
{
	printf( "new client(%d) connect in\n", host.ID() );
}

/**
 * 连接关闭事件，回调方法
 * 
 * 派生类实现具体断开连接业务处理
 * 
 */
void CLoginGateServer::OnCloseConnect(mdk::NetHost &host)
{
	printf( "client(%d) close connect\n", host.ID() );
}

void CLoginGateServer::OnMsg(mdk::NetHost &host)
{
	//假设报文结构为：2byte表示数据长度+报文数据
	unsigned char c[256];
	/*
		读取数据长度，长度不足2byte直接返回，等待下次数据到达时再读取
		只读取2byte，false表示，不将读取到的数据从缓冲中删除，下次还是可以读到
	*/
	if ( !host.Recv( c, 2, false ) ) return;
	unsigned short len = 0;
	memcpy( &len, c, 2 );//得到数据长度
	len += 2;//报文长度 = 报文头长度+数据长度
	if ( len > 256 ) 
	{
		printf( "close client:invaild fromat msg\n" );
		host.Close();
		return;
	}
	if ( !host.Recv(c, len) ) return;//将报文读出，并从接收缓冲中删除，绝对不可能长度不够，即使连接已经断开，也可以读到数据
	host.Send( c, len );//收到消息原样回复
}

bool CLoginGateServer::StopServer()
{
	Stop();

	return true;
}

bool CLoginGateServer::StartServer( unsigned short nPort )
{
	//开启服务器
	SetIOThreadCount(4);//设置网络IO线程数量
	SetWorkThreadCount(4);//设置工作线程数

	Listen(nPort);


	const char *pRet = Start();
	if(pRet)
	{
		printf("服务器启动失败:%s\n",pRet);
		return false;
	}
	else
		return true;
}


bool CLoginGateServer::ConnectServer( char * szIp,int nPort,void *pSrvInfo,int nReconnectTime )
{
	//连接其他服务器
	return Connect(szIp,nPort,pSrvInfo,nReconnectTime);
}
