#include <stdio.h>
#include <string.h>
#include <assert.h>
//自行实现strcpy函数
//7分
void my_strcpy(char* dest,char* src)
{
    while(*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = *src;
}
//8分
void my_strcpy1(char* dest,char* src)
{
    if(dest != NULL && src != NULL)
    {
        while( *dest++ = *src++)
        {
            ;
        }
    }
}
//9分
void my_strcpy2(char* dest,char* src)
{
    assert(dest != NULL);//断言
    assert(src != NULL);
    while( *dest++ = *src++)
        {
            ;
        }
}
//10分
char* my_strcpy3(char* dest,const char* src)
{
    char* ret = dest;
    assert(dest != NULL);//断言，保证指针的有效性
    assert(src != NULL);
    //把src指向的字符串拷贝到dest指向的空间，包含'\0'字符
    while( *dest++ = *src++)
        {
            ;
        }
    return ret;
}

int main()
{
    char arr1[] = "################################";
    char arr2[] = "bit";
    //strcpy(arr1,arr2);
    //my_strcpy2(arr1,arr2);
    //printf("%s\n",arr1);
    printf("%s\n",my_strcpy3(arr1,arr2));
    return 0;
}


//const修饰指针时的情况
int main1()
{
    int n = 100;
    const int num = 10;
    const int* p = &num;
    //*p = 30;报错
    //int* const p = &num;
    //p = &n;报错
    //const放在指针变量的*左边时，修饰的是*p，也就是说：不能通过p来改变*p(num)的值
    //const放在指针变量的*右边时，修饰的是指针变量p本身，p不能被改变
    printf("%d\n",num);
    return 0;
}




//自行实现strlen函数
int my_strlen(const char* str)
{
    int count = 0;
    assert(str != NULL);
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
int main()
{
    char arr[] = "abcdef";
    int len = my_strlen(arr);
    printf("%d\n",len);
    return 0;
}