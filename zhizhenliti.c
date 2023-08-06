//指针和数组笔试题解析
//一维数组
int a[] = {1,2,3,4};
//数组名是首元素的地址
//1.sizeof(数组名)表示整个数组
//2.&数组名 - 数组名表示整个数组
printf("%d\n",sizeof(a));//4*4=16 sizeof(数组名)-计算的是数组总大小-单位是字节-16
printf("%d\n",sizeof(a+0));//4/8 -数组名这里表示首元素的地址，a+0还是首元素地址，地址的大小就是4/8个字节
printf("%d\n",sizeof(*a));//4 -数组名表示首元素地址，*a就是首元素，sizeof(*a)就是4
printf("%d\n",sizeof(a+1));//4/8 -数组名这里表示首元素的地址，a+1是第2个元素的地址，地址的大小就是4/8个字节
printf("%d\n",sizeof(a[1]));//4 - 第2个元素的大小
printf("%d\n",sizeof(&a));//4/8 - &a取出的是数组的地址，但是数组的地址那也是地址，地址的大小就是4/8个字节
printf("%d\n",sizeof(*&a));//16 - &a是数组的地址，数组的地址解引用访问的数组，sizeof计算的就是数组的大小，单位是字节
printf("%d\n",sizeof(&a+1));//4/8 - &a是数组的地址，&a+1虽然地址跳过整个数组，但还是地址，所以是4/8个字节
printf("%d\n",sizeof(&a[0]));//4/8 - &a[0]是第一个元素的地址
printf("%d\n",sizeof(&a[0]+1));//4/8 - &a[0]+1是第二个元素的地址


//字符数组
char arr[] = {'a','b','c','d','e','f'};
printf("%d\n", sizeof(arr));//6
printf("%d\n", sizeof(arr+0));//4/8
printf("%d\n", sizeof(*arr));//1
printf("%d\n", sizeof(arr[1]));//1
printf("%d\n", sizeof(&arr));//4/8
printf("%d\n", sizeof(&arr+1));//4/8
printf("%d\n", sizeof(&arr[0]+1));//4/8


printf("%d\n", strlen(arr));//随机值
printf("%d\n", strlen(arr+0));//随机值
printf("%d\n", strlen(*arr));//报错error  因为输入给strlen的是'a'的ascii码值97，将97当作地址开始找'\0',所以报错
printf("%d\n", strlen(arr[1]));//报错
printf("%d\n", strlen(&arr));//随机值
printf("%d\n", strlen(&arr+1));//随机值-6
printf("%d\n", strlen(&arr[0]+1));//随机值-1


char arr[] = "abcdef";
printf("%d\n", sizeof(arr));//7
printf("%d\n", sizeof(arr+0));//4/8
printf("%d\n", sizeof(*arr));//1
printf("%d\n", sizeof(arr[1]));//1
printf("%d\n", sizeof(&arr));//4/8
printf("%d\n", sizeof(&arr+1));//4/8
printf("%d\n", sizeof(&arr[0]+1));//4/8


printf("%d\n", strlen(arr));//6
printf("%d\n", strlen(arr+0));//6
printf("%d\n", strlen(*arr));//error
printf("%d\n", strlen(arr[1]));//error
printf("%d\n", strlen(&arr));//6 有警告  char (*p)[7] = &arr 
printf("%d\n", strlen(&arr+1));//随机值  有警告
printf("%d\n", strlen(&arr[0]+1));//5


char *p = "abcdef";
printf("%d\n", sizeof(p));//4/8
printf("%d\n", sizeof(p+1));//4/8
printf("%d\n", sizeof(*p));//1
printf("%d\n", sizeof(p[0]));//1
printf("%d\n", sizeof(&p));//4/8
printf("%d\n", sizeof(&p+1));//4/8
printf("%d\n", sizeof(&p[0]+1));//4/8

printf("%d\n", strlen(p));//6
printf("%d\n", strlen(p+1));//5
printf("%d\n", strlen(*p));//error
printf("%d\n", strlen(p[0]));//error
printf("%d\n", strlen(&p));//随机值
printf("%d\n", strlen(&p+1));//随机值
printf("%d\n", strlen(&p[0]+1));//5


//二维数组
int a[3][4] = {0};
printf("%d\n",sizeof(a));//3*4*4=48
printf("%d\n",sizeof(a[0][0]));//4
printf("%d\n",sizeof(a[0]));//4*4=16
printf("%d\n",sizeof(a[0]+1));//4/8 - 第一行第二个元素的地址
printf("%d\n",sizeof(*(a[0]+1)));//4
printf("%d\n",sizeof(a+1));//4/8 - 第二行一维数组的地址
printf("%d\n",sizeof(*(a+1)));//16 ==sizeof(a[1])
printf("%d\n",sizeof(&a[0]+1));//4/8  第二行的地址
printf("%d\n",sizeof(*(&a[0]+1)));//16
printf("%d\n",sizeof(*a));//16   第一行的大小
printf("%d\n",sizeof(a[3]));//16 - sizeof内部的表达式是不真实参与运算的

//数组名的意义：

//1.  sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。
//2.  &数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
//3. 除此之外所有的数组名都表示首元素的地址。



//指针八道典型笔试题
//一
int main()
{
 int a[5] = { 1, 2, 3, 4, 5 };
 int *ptr = (int *)(&a + 1);
 printf( "%d,%d", *(a + 1), *(ptr - 1));
 return 0;
}
//程序的结果是什么？
//2 5


//二
//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
 int Num;
 char *pcName;
 short sDate;
 char cha[2];
 short sBa[4];
}*p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节
int main()
{
 printf("%p\n", p + 0x1);//00100014
 printf("%p\n", (unsigned long)p + 0x1);//00100001
 printf("%p\n", (unsigned int*)p + 0x1);//00100004
 return 0;
}


//三
int main()
{
 int a[4] = { 1, 2, 3, 4 };
 int *ptr1 = (int *)(&a + 1);
 int *ptr2 = (int *)((int)a + 1);
 printf( "%x,%x", ptr1[-1], *ptr2);//00000004   02000000  以%x打印出来后是4 2000000
 return 0;
}


//四
#include <stdio.h>
int main()
{
 int a[3][2] = { (0, 1), (2, 3), (4, 5) };//注意逗号表达式  存的值是1 3 5
 int *p;
 p = a[0];
 printf( "%d", p[0]);//1
 return 0;
}


//五
int main()
{
 int a[5][5];
 int(*p)[4];
 p = a;
 printf( "%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//FFFFFFFC  -4
 return 0;
}


//六
int main()
{
 int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 int *ptr1 = (int *)(&aa + 1);
 int *ptr2 = (int *)(*(aa + 1));
 printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10  5
 return 0;
}


//七
#include <stdio.h>
int main()
{
 char *a[] = {"work","at","alibaba"};
 char**pa = a;
 pa++;
 printf("%s\n", *pa);//at
 return 0;
}


//八（经典）
int main()
{
 char *c[] = {"ENTER","NEW","POINT","FIRST"};
 char**cp[] = {c+3,c+2,c+1,c};
 char***cpp = cp;
 printf("%s\n", **++cpp);//POINT
 printf("%s\n", *--*++cpp+3);//ER
 printf("%s\n", *cpp[-2]+3);//ST
 printf("%s\n", cpp[-1][-1]+1);//EW
 return 0;
}

