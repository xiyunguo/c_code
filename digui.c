
//接受一个整型值（无符号），按照顺序打印它的每一位
#include <stdio.h>
void print(int n)
{
 if(n>9)
 {
 print(n/10);
 }
 printf("%d ", n%10);
}
int main()
{
 unsigned int num = 1234;
 print(num);
 return 0;
}






//求n的阶乘（不考虑溢出）
#include <stdio.h>
int Fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac(n - 1);
}
int main()
{
	int n = 5;
	int ret = Fac(n);
	printf("%d\n", ret);
	return 0;
}






//求第n个斐波那契数（不考虑溢出）
#include <stdio.h>
//递归——很慢
int Fib1(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fib1(n - 1) + Fib1(n - 2);
}
//迭代
int Fib2(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 5;
	int ret = Fib2(n);
	printf("%d\n", ret);
	return 0;
}






//计算一个数的每位之和（递归实现）
//写一个递归函数，输入一个非负整数，返回组成它的数字之和
int DigitSum(unsigned int num)
{
    if(num > 9)
    {
        return DigitSum(num/10)+num%10;
    }
    else
    {
        return num;
    }
}
int main()
{
    unsigned int num = 0;
    scanf("%d",&num);
    int ret = DigitSum(num);
    printf("ret = %d\n",ret);
}








//递归实现n的k次方
double Pow(int n,int k)
{
    //n^k = n * n^(k-1)
    if(k<0)
        return (1.0/Pow(n,-k));
    else if(k == 0)
        return 1;
    else
        return n*Pow(n,k-1);
}
int main()
{
    int n = 0;
    int k = 0;
    scanf("%d%d",&n,&k);
    double ret = Pow(n,k);
    printf("ret = %lf\n",ret);
    return 0;
}
