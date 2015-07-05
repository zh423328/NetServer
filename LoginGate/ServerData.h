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

	std::string m_clientIp;	//玩家ip
};

enum
{
	SERVER_TYPE_NONE,		//none
	SERVER_TYPE_LOGINGATE,	//logingate
	SERVER_TYPE_LOGINSRV,	//loginsrv

	SERVER_TYPE_MAX,
};

//服务器连接数据
class ServerInfo 
{
public:
	ServerInfo();
	~ServerInfo();


	//可以是域名
	SYNTHESIZE(std::string,m_strIp,ServerIP);
	//端口号
	SYNTHESIZE(int,m_nPort,ServerPort);
	//类型
	SYNTHESIZE(int,m_nServerType,ServerType);
};
#endif//-- _SERVERDATA_H_--