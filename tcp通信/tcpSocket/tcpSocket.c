#include "tcpSocket.h"

//�������
bool init_Socket()
{
	//wsa  windows socket async    windows�첽�׽���
	//parm1:�����socket�汾   parm2:��������
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		err("WSAStartup");
		return false;
	}
	return true;
}
//�ر������
bool close_Socket()
{
	if (0 != WSACleanup())
	{
		err("WSACleanup");
		return false;
	}
	return true;
}

//����������socket
SOCKET createServerSocket()
{
	//1.�����յ�Socket   �����ֻ�
	//parm1:af ��ַЭ���� ipv4 ipv6
	//parm2:type ����Э������  ��ʽ�׽��� ���ݱ�(SOCK_DGRAM)
	//parm3:protocl  ʹ�þ����ĳ������Э��
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET)
	{
		err("socket");
		return INVALID_SOCKET;
	}
	//2.��socket��IP��ַ�Ͷ˿ں�   �򿨲��ܴ�绰
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//�ʹ���socketʱ�ı���һ��
	addr.sin_port = htons(PORT);//��˴洢��С�˴洢    �������ֽ���תΪ�����ֽ���
	addr.sin_addr.S_un.S_addr = ADDR_ANY;//inet_addr("127.0.0.1");

	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		err("bind");
		return false;
	}

	//3.�����绰
	listen(fd, 10);
	return fd;
}
//�����ͻ���socket
SOCKET createClientSocket(const char* ip)
{
	//1.�����յ�Socket   �����ֻ�
	//parm1:af ��ַЭ���� ipv4 ipv6
	//parm2:type ����Э������  ��ʽ�׽��� ���ݱ�(SOCK_DGRAM)
	//parm3:protocl  ʹ�þ����ĳ������Э��
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET)
	{
		err("socket");
		return INVALID_SOCKET;
	}
	//2.���������������
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//�ʹ���socketʱ�ı���һ��
	addr.sin_port = htons(PORT);//��˴洢��С�˴洢    �������ֽ���תΪ�����ֽ���
	addr.sin_addr.S_un.S_addr = inet_addr(ip);
	printf("�����ӷ�����%s......\n",ip);
	if (INVALID_SOCKET == connect(fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		err("connect");
		return false;
	}
	printf("�Ѿ����ӵ�������%s\n", ip);
	return fd;
}
