#ifndef _SERVERDATA_H_
#define _SERVERDATA_H_

#include "../include/frame/netserver/HostData.h"
#include "../include/mdk/macrodefine.h"

//clientdata
class ClientInfo : public mdk::HostData
{
public:
	ClientInfo();
	~ClientInfo();

	std::string m_clientIp;	//���ip
};

enum
{
	SERVER_TYPE_NONE,		//none
	SERVER_TYPE_LOGINGATE,	//logingate
	SERVER_TYPE_LOGINSRV,	//loginsrv

	SERVER_TYPE_MAX,
};

//��������������
class ServerInfo 
{
public:
	ServerInfo();
	~ServerInfo();


	//����������
	SYNTHESIZE(std::string,m_strIp,ServerIP);
	//�˿ں�
	SYNTHESIZE(int,m_nPort,ServerPort);
	//����
	SYNTHESIZE(int,m_nServerType,ServerType);
};
#endif//-- _SERVERDATA_H_--