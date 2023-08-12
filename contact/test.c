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
	//创建通讯录
	struct Contact con;//con就是通讯录，里面包含1000个元素的结构体数组和size
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
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
			printf("退出\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);	
}