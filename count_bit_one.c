#include <stdio.h>
//统计二进制中1的个数
int count_bit_one(int n)
{
    int count = 0;
    while(n)
    {
        if(n%2 == 1)
        {
            count++;
        }
        n = n/2;    
    }
     return count;
}
int main()
{
    int a = 0;
    scanf("%d",&a);
    //写一个函数求a的二进制（补码）表示中有几个1
    int count = count_bit_one(a);
    printf("count = %d\n",count);
    return 0;

}
//此时，负数搞不定，可以将函数形参改一下
int count_bit_one(unsigned int n)
{
    int count = 0;
    while(n)
    {
        if(n%2 == 1)
        {
            count++;
        }
        n = n/2;    
    }
     return count;
}
//另一种思路，按位与
int count_bit_one(int n)
{
    int count = 0;
    int i = 0;
    for(i=0;i<32;i++)
    {
        if((n>>i)&1==1)
        {
            count++;
        }
    }
    return count;
}
//更加高效
int count_bit_one(int n)
{
    int count = 0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}