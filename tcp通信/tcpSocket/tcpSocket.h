#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include <WinSock2.h>   //windowsƽ̨�������ͷ�ļ�
#pragma comment(lib,"ws2_32.lib")  //���ļ�
#include <stdbool.h>
#include <stdio.h>
#define PORT 8888
#define err(errMsg) printf("[line:%d]%s failed code %d",__LINE__,errMsg,WSAGetLastError())

//�������
bool init_Socket();
//�ر������
bool close_Socket();
//����������socket
SOCKET createServerSocket();
//�����ͻ���socket
SOCKET createClientSocket(const char* ip);

#endif // !_TCPSOCKET_H_
