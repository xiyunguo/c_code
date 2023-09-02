#define _CRT_SECURE_NO_WARNINGS 1
#include "../tcpSocket/tcpSocket.h"
int main()
{
	init_Socket();
	SOCKET fd = createClientSocket("127.0.0.1");
	//char buf[BUFSIZ] = "你好我是客户端QAQ";
	char recvbuf[BUFSIZ] = { 0 };
	char sendbuf[BUFSIZ] = "你好我是客户端QAQ";
	//先说一句话，打个招呼
	if (SOCKET_ERROR == send(fd, sendbuf, strlen(sendbuf), 0))
	{
		err("send");
	}
	memset(sendbuf, 0, sizeof(sendbuf));

	while (true)
	{
		//发送消息
		printf("send>");
		gets_s(sendbuf, BUFSIZ);
		if (SOCKET_ERROR == send(fd, sendbuf, strlen(sendbuf), 0))
		{
			err("send");
		}
		memset(sendbuf, 0, sizeof(sendbuf));
		//recv从指定的socket接受消息
		if (0 < recv(fd, recvbuf, BUFSIZ, 0))
		{
			printf("recv:%s\n", recvbuf);
			memset(recvbuf, 0, sizeof(recvbuf));
		}

		
	}

	closesocket(fd);
	close_Socket();
	printf("client------end------\n");
	return 0;
}