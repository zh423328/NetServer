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

	//Connect("10.10.10.82", 5678,NULL, 5);//��������δ���ԣ���������ô��
}

CLoginGateServer::~CLoginGateServer()
{

}

/*
 *	���������߳�
 */
void* CLoginGateServer::Main(void* pParam)
{
	while ( IsOk() )
	{
		//ִ��ҵ��
#ifndef WIN32
		usleep( 1000 * 1000 );
#else
		Sleep( 1000 );
#endif
	}
	
	return 0;
}

/**
 * �������¼��ص�����
 * 
 * ������ʵ�־�������ҵ����
 * ����������������ʱ������host.IsServer���ж��Ƿ�Ϊһ����������
 * ����ͬ��Ҳ���һ������
 *
 * 
 */
void CLoginGateServer::OnConnect(mdk::NetHost& host)
{
	printf( "new client(%d) connect in\n", host.ID() );
}

/**
 * ���ӹر��¼����ص�����
 * 
 * ������ʵ�־���Ͽ�����ҵ����
 * 
 */
void CLoginGateServer::OnCloseConnect(mdk::NetHost &host)
{
	printf( "client(%d) close connect\n", host.ID() );
}

void CLoginGateServer::OnMsg(mdk::NetHost &host)
{
	//���豨�ĽṹΪ��2byte��ʾ���ݳ���+��������
	unsigned char c[256];
	/*
		��ȡ���ݳ��ȣ����Ȳ���2byteֱ�ӷ��أ��ȴ��´����ݵ���ʱ�ٶ�ȡ
		ֻ��ȡ2byte��false��ʾ��������ȡ�������ݴӻ�����ɾ�����´λ��ǿ��Զ���
	*/
	if ( !host.Recv( c, 2, false ) ) return;
	unsigned short len = 0;
	memcpy( &len, c, 2 );//�õ����ݳ���
	len += 2;//���ĳ��� = ����ͷ����+���ݳ���
	if ( len > 256 ) 
	{
		printf( "close client:invaild fromat msg\n" );
		host.Close();
		return;
	}
	if ( !host.Recv(c, len) ) return;//�����Ķ��������ӽ��ջ�����ɾ�������Բ����ܳ��Ȳ�������ʹ�����Ѿ��Ͽ���Ҳ���Զ�������
	host.Send( c, len );//�յ���Ϣԭ���ظ�
}

bool CLoginGateServer::StopServer()
{
	Stop();

	return true;
}

bool CLoginGateServer::StartServer( unsigned short nPort )
{
	//����������
	SetIOThreadCount(4);//��������IO�߳�����
	SetWorkThreadCount(4);//���ù����߳���

	Listen(nPort);


	const char *pRet = Start();
	if(pRet)
	{
		printf("����������ʧ��:%s\n",pRet);
		return false;
	}
	else
		return true;
}


bool CLoginGateServer::ConnectServer( char * szIp,int nPort,void *pSrvInfo,int nReconnectTime )
{
	//��������������
	return Connect(szIp,nPort,pSrvInfo,nReconnectTime);
}
