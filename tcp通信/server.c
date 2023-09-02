#define _CRT_SECURE_NO_WARNINGS 1
#include "..\tcpSocket\tcpSocket.h"

int main()
{
	init_Socket();
	SOCKET serfd = createServerSocket();
	printf("wait client connect...\n");
	//如果有客户端请求链接
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (INVALID_SOCKET == clifd)
	{
		err("accept");
	}
	printf("client connect scessful!\n");
	//可以和客户端进行通信了
	char recvbuf[BUFSIZ] = { 0 };
	char sendbuf[BUFSIZ] = { 0 };
	if (0 < recv(clifd, recvbuf, BUFSIZ, 0))
	{
		printf("recv:%s\n", recvbuf);
		memset(recvbuf, 0, sizeof(recvbuf));
	}
	while (true)
	{
		//recv从指定的socket接受消息
		if (0 < recv(clifd, recvbuf, BUFSIZ, 0))
		{
			printf("recv:%s\n", recvbuf);
			memset(recvbuf, 0, sizeof(recvbuf));
		}

		//发送消息
		printf("send>");
		gets_s(sendbuf, BUFSIZ);
		if (SOCKET_ERROR == send(clifd, sendbuf, strlen(sendbuf), 0))
		{
			err("send");
		}
		memset(sendbuf, 0, sizeof(sendbuf));
	}

	closesocket(clifd);
	closesocket(serfd);
	close_Socket();
	printf("server------end------\n");
	return 0;
}