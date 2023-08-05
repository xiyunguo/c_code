//要把函数的地址存到一个数组中，那这个数组就叫函数指针数组
//函数指针数组的用途：转移表
#include <stdio.h>
void menu()
{
	printf("**************************\n");
	printf("*****1.Add     2.Sub******\n");
	printf("*****3.Mul     4.Div******\n");
	printf("*********  0.exit  *******\n");
	printf("**************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
//使用switch case语句实现
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Add(x, y));
			break;
		case 2:
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Sub(x, y));
			break;
		case 3:
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Mul(x, y));
			break;
		case 4:
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Div(x, y));
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
//使用函数指针数组的实现
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	//pfArr是一个函数指针数组 ——转移表
	int (*pfArr[])(int, int) = {0,Add,Sub,Mul,Div};
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出\n");
		}
		else
		{
			printf("选择错误\n");
		}
	} while(input);
    return 0;
}