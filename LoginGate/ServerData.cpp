#include "ServerData.h"


ClientInfo::ClientInfo()
{
}

ClientInfo::~ClientInfo()
{

}


ServerInfo::ServerInfo()
{
	//设置服务器数据
	setServerIP("127.0.0.1");
	setServerPort(1234);
	setServerType(SERVER_TYPE_NONE);
}

ServerInfo::~ServerInfo()
{

}
