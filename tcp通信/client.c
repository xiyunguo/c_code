#define _CRT_SECURE_NO_WARNINGS 1
#include "../tcpSocket/tcpSocket.h"
int main()
{
	init_Socket();
	SOCKET fd = createClientSocket("127.0.0.1");
	//char buf[BUFSIZ] = "������ǿͻ���QAQ";
	char recvbuf[BUFSIZ] = { 0 };
	char sendbuf[BUFSIZ] = "������ǿͻ���QAQ";
	//��˵һ�仰������к�
	if (SOCKET_ERROR == send(fd, sendbuf, strlen(sendbuf), 0))
	{
		err("send");
	}
	memset(sendbuf, 0, sizeof(sendbuf));

	while (true)
	{
		//������Ϣ
		printf("send>");
		gets_s(sendbuf, BUFSIZ);
		if (SOCKET_ERROR == send(fd, sendbuf, strlen(sendbuf), 0))
		{
			err("send");
		}
		memset(sendbuf, 0, sizeof(sendbuf));
		//recv��ָ����socket������Ϣ
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