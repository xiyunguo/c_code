#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("**********************************\n");
	printf("******0.exit       1.add    ******\n");
	printf("******2.del        3.modify ******\n");
	printf("******4.search     5.sort   ******\n");
	printf("******6.show                ******\n");
	printf("**********************************\n");
}
int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;//con����ͨѶ¼���������1000��Ԫ�صĽṹ�������size
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			printf("�˳�\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);	
}