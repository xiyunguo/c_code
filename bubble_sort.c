int a = 10;
void* p = &a;
//void* 类型的指针，可以接收任意类型的地址
//void* 类型的指针，不能进行解引用操作
//void* 类型的指针，不能进行+-整数的操作


//1.首先演示一下qsort函数的使用：
#include <stdlib.h>
#include <string.h>
struct Stu
{
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	//比较两个整型值
	return *(int*)e1 - *(int*)e2;
}
int cmp_float(const void* e1, const void* e2)
{
	//比较两个浮点数
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用><=比较，应该用strcmp函数
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test2()
{
	float f[] = { 0.9,0.8,0.7,0.6,0.5,0.4 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%f ", f[j]);
	}
}
void test3()
{
	struct Stu s[3] = { {"zhangsan",10},{"lisi",30},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}
void test4()
{
	struct Stu s[3] = { {"zhangsan",10},{"lisi",30},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
//qsort函数参数详解
//第一个参数：待排序数组的首元素地址
//第二个参数：待排序数组的元素个数
//第三个参数，待排序数组的每个元素的大小--单位是字节
//第四个参数：是函数指针，比较两个元素的所用函数的地址-这个函数使用者自己实现，函数指针的两个参数是：待比较的两个元素的地址
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}




//2.使用回调函数，模拟实现qsort(采用冒泡的方式)

//回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，
//当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，
//而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。

//a.首先演示常规bubble算法（只能进行int类型数据排序）
#include <stdio.h>
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设这一趟要排序的数据已经有序
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;//本趟排序的数据其实不完全有序
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	bubble_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;;
}

//b.使用回调函数，实现bubble_sort
#include <stdlib.h>
#include <string.h>
struct Stu
{
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	//比较两个整型值
	return *(int*)e1 - *(int*)e2;
}
int cmp_float(const void* e1, const void* e2)
{
	//比较两个浮点数
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用><=比较，应该用strcmp函数
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
//实现bubble_sort函数的程序员，他是否知道未来排序的数据类型--不知道
//那程序员也不知道，待比较的两个元素的类型
void bubble_sort(void* base,int sz,int width,int (*cmp)(void* e1,void* e2))
{
	int i = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//每一趟比较的对数
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//两个元素的比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//使用bubble_sort的程序员一定知道自己排序的是什么数据
	//就应该知道如何比较待排序数组中的元素
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test2()
{
	float f[] = { 0.9,0.8,0.7,0.6,0.5,0.4 };
	int sz = sizeof(f) / sizeof(f[0]);
	bubble_sort(f, sz, sizeof(f[0]), cmp_float);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%f ", f[j]);
	}
}
void test3()
{
	struct Stu s[3] = { {"zhangsan",10},{"lisi",30},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}
void test4()
{
	struct Stu s[3] = { {"zhangsan",10},{"lisi",30},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}