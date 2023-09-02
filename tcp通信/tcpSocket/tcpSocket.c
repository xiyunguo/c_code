#include "tcpSocket.h"

//打开网络库
bool init_Socket()
{
	//wsa  windows socket async    windows异步套接字
	//parm1:请求的socket版本   parm2:传出参数
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		err("WSAStartup");
		return false;
	}
	return true;
}
//关闭网络库
bool close_Socket()
{
	if (0 != WSACleanup())
	{
		err("WSACleanup");
		return false;
	}
	return true;
}

//创建服务器socket
SOCKET createServerSocket()
{
	//1.创建空的Socket   买新手机
	//parm1:af 地址协议族 ipv4 ipv6
	//parm2:type 传输协议类型  流式套接字 数据报(SOCK_DGRAM)
	//parm3:protocl  使用具体的某个传输协议
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET)
	{
		err("socket");
		return INVALID_SOCKET;
	}
	//2.给socket绑定IP地址和端口号   买卡才能打电话
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//和创建socket时的必须一样
	addr.sin_port = htons(PORT);//大端存储和小端存储    将本地字节序转为网络字节序
	addr.sin_addr.S_un.S_addr = ADDR_ANY;//inet_addr("127.0.0.1");

	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		err("bind");
		return false;
	}

	//3.监听电话
	listen(fd, 10);
	return fd;
}
//创建客户端socket
SOCKET createClientSocket(const char* ip)
{
	//1.创建空的Socket   买新手机
	//parm1:af 地址协议族 ipv4 ipv6
	//parm2:type 传输协议类型  流式套接字 数据报(SOCK_DGRAM)
	//parm3:protocl  使用具体的某个传输协议
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET)
	{
		err("socket");
		return INVALID_SOCKET;
	}
	//2.与服务器建立链接
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//和创建socket时的必须一样
	addr.sin_port = htons(PORT);//大端存储和小端存储    将本地字节序转为网络字节序
	addr.sin_addr.S_un.S_addr = inet_addr(ip);
	printf("正链接服务器%s......\n",ip);
	if (INVALID_SOCKET == connect(fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		err("connect");
		return false;
	}
	printf("已经链接到服务器%s\n", ip);
	return fd;
}
