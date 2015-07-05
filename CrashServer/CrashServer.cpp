// CrashServer.cpp : Defines the entry point for the console application.
// crashserver  dumps
// 
//
#include "stdafx.h"
#include "google_breakpad/CrashHandler.h"
#include "mdk/Thread.h"
#include "mdk/Executor.h"
using namespace mdk;

class CrashServer : public CrashServerHandler
{
public:
	CrashServer()
	{

	}
	~CrashServer()
	{

	}

	bool Start()
	{
		bool bRet = CrashServerHandler::Start();

		if (bRet == false)
		{
			return false;
		}

		printf("dump 服务器启动成功!\n");

		mainThread.Run(Executor::Bind(&CrashServer::CmdThread),this,NULL);

		mainThread.WaitStop();

		return true;
	}

	//启动线程
	void * RemoteCall CmdThread(void*pParam)
	{
		char ch = getchar();

		while (ch != 'q')
		{
			ch = getchar();
		}

		return 0;
	}
private:
	Thread mainThread;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CrashServer *pServer  = new CrashServer();
	if (!pServer->Start())
	{
		printf("dump 服务器启动失败!\n");
		return 1;
	}

	return 0;
}

