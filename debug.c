#include <stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		printf("hehe\n");
		arr[i] = 0;
	}
	return 0;
}
//栈区的默认使用：先使用高地址处的空间，再使用低地址处的空间
// 数组随着下标的增长，地址是由低到高变化
//x86编译&&debug模式下会进入死循环，原因就是数组越界访问，堆放在栈区的arr[12]的地址就是i的地址，然后使得i=0，从而进入死循环
// 而release版本会做出优化，优化后i的地址小于arr的，因此不会陷入死循环，当然还会报错——数组越界