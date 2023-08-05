//1.两个有趣的关于函数指针的代码
//代码1
(*(void (*)())0)();
//把0强制类型转换成：void(*)()函数指针类型 0就是一个函数的地址
//调用0地址处的该函数


//代码2
void (*signal(int , void(*)(int)))(int);//void (*  signal(int , void(*)(int))   )(int)
//此语句是一个函数声明，函数是signal(int , void(*)(int))，返回类型是void (*)(int)函数指针
//signal是一个函数声明，signal函数的参数有2个，第一个是int,第二个是函数指针，该函数指针指向的参数是int，返回类型是void
//signal函数的返回类型也是一个函数指针，该函数指针指向的参数是int，返回类型是void
//对其简化：
typedef void(*pfun_t)(int);
pfun_t signal(int,pfun_t);




//2.&函数名=函数名，没区别
#include <stdio.h>
void test()
{
 printf("hehe\n");
}
int main()
{
 printf("%p\n", test);
 printf("%p\n", &test);
 return 0;
}


//3.*pa和pa都可以，这里的*没有实际作用，写成**pa/***pa都行
int Add(int x,int y);
int main()
{
    int(*pa)(int,int) = Add;
    printf("%d\n",(*pa)(2,3));
    printf("%d\n",pa(2,3));//都可以 
}
