#ifndef MSWINSOCKUTIL_H_
#define MSWINSOCKUTIL_H_

//////////////////////////////////////////////////////////////////////////
//��Ҫapi����AcceptEx��GetSocketAddr
//////////////////////////////////////////////////////////////////////////
#ifdef WIN32
#include <winsock2.h>
#include <mswsock.h>

namespace mdk
{



	class MsWinsockUtil
	{
	public:
		//���غ���
		static void	LoadExtensionFunction( SOCKET ActiveSocket );	

		//connectex
		static void LoadClientFunction(SOCKET ActiveSocket);

		//AcceptEx
		static LPFN_ACCEPTEX				m_lpfnAccepteEx;			
		//GetAcceptExSockAddrs����
		static LPFN_GETACCEPTEXSOCKADDRS	m_lpfnGetAcceptExSockAddrs;

		//connect
		static LPFN_CONNECTEX				m_lpnConnectEx;			//����
	private:
		static bool LoadExtensionFunction( SOCKET ActiveSocket,	GUID FunctionID, void **ppFunc);
	};

}

#endif

#endif