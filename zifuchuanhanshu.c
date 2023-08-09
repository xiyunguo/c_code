// 一些字符串函数汇总

//1. strlen
//size_t strlen ( const char * str );
//- 字符串以'\0'作为结束标志，strlen函数返回的是在字符串中'\0'前面出现的字符个数（不包含'\0'）

//- 参数指向的字符串必须要以'\0'结束

//- 注意函数的返回值为size_t，是无符号的
#include <stdio.h>
int main()
{
 const char*str1 = "abcdef";
 const char*str2 = "bbb";
 if(strlen(str2)-strlen(str1)>0)
 {
 printf("str2>str1\n");//输出这个，因为相减结果为无符号数，恒不小于0
 } 
 else
 {
 printf("srt1>str2\n");
 }
 return 0;
}

//模拟实现
#include <stdio.h>
#include <assert.h>
//使用临时变量
int my_strlen(const char* str)
{
    int count = 0;
    assert(str != NULL);
    while(*str)//while(*str != '\0')
    {
        count++;
        str++;
    }
}
//使用递归
int my_strlen1(char* arr)
{
	if (*arr != '\0')
		return 1 + my_strlen1(arr + 1);
	else
		return 0;
}
//指针-指针的方式
int my_strlen2(char* s)
{
    char* p = s;
    while(*p != '\0')
        p++;
    return p-s;
}



//2.strcpy
//char* strcpy(char * destination, const char * source );
//- 源字符串必须以'\0'结束   - 会将源字符串中的'\0'拷贝到目标空间

//- 目标空间必须足够大，以确保能存放源字符串    - 目标空间必须可变    - 返回目的空间的起始地址
//模拟实现
char* my_strcpy(char* dest,const char* src)
{
    assert(dest != NULL);
    assert(src != NULL);
    char* ret = dest;
    //拷贝src指向的字符串到dest指向的空间，包含'\0'
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = *src;//'\0'
    //返回目的空间的起始地址
    return ret;
}
//精简版
char* my_strcpy(char* dest,const char* src)
{
    assert(dest != NULL);
    assert(src != NULL);
    char* ret = dest;
    while(*dest++ = *src++)
    {
        ;
    }
    return ret;
}

//3.strcat
//char * strcat ( char * destination, const char * source );
//- 源字符串必须以'\0'结束，将'\0'也会追加过去 - 目的字符串也得要有'\0'，因为要从'\0'处追加

//- 目标空间必须足够大，能容纳下源字符串的内容  - 目标空间必须可修改  - 字符串自己给自己追加，如何？会崩溃
//模拟实现
char* my_strcat(char* dest,char* src)
{
    char* ret = dest;
    assert(dest != NULL);
    assert(src);
    //1.找到目的字符串的'\0'
    while(*dest != '\0')
    {
        dest++;
    }
    //2.追加
    while(*dest++ = *src++)
    {
        ;
    }
    return ret;
}


//4.strcmp
//int strcmp ( const char * str1, const char * str2 );
//标准规定：
//* 第一个字符串大于第二个字符串，则返回大于0的数字
//* 第一个字符串等于第二个字符串，则返回0
//* 第一个字符串小于第二个字符串，则返回小于0的数字

//模拟实现
int my_strcmp(const char* str1,const char* str2)
{
    assert(str1 && str2);
    //比较
    while(*str1 == *str2)
    {
        if(*str1 == '\0')
        {
            return 0;//相等
        }
        str1++;
        str2++;
    }
    if(*str1 > *str2)     //或者直接return (*str1-*str2)
        return 1;//大于 
    else
        return -1;//小于
}
int main()
{
    char* p1 = "abcde";
    char* p2 = "cdefg";
    int ret = my_strcmp(p1,p2);
    printf("ret = %d\n",ret);
    return 0;
}


//5.strncpy
char * strncpy ( char * destination, const char * source, size_t num );
//- 拷贝num个字符从源字符串到目标空间。
//- 如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个。


//6.strncat
char * strncat ( char * destination, const char * source, size_t num );
//- 从源的第一个字符开始追加到目标地址后面，最后追加上'\0'
//- 如果源中 C 字符串的长度小于 num，则最后只补一个'\0'
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not to be");
	strncat(str1, str2, 6);
	puts(str1);//To be or not
	return 0;
}

//7.strncmp

//int strncmp ( const char * str1, const char * str2, size_t num );

//比较到出现另个字符不一样或者一个字符串结束或者num个字符全部比较完
#include <stdio.h>
#include <string.h>
int main()
{
    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
    int n;
    puts("Looking for R2 astromech droids...");
    for (n = 0; n < 3; n++)
        if (strncmp(str[n], "R2xx", 2) == 0)
        {
            printf("found %s\n", str[n]);//found R2D2   found R2A6
        }
    return 0;
}//

//8.strstr

//char * strstr ( const char *str1, const char * str2);
//在str1中查找str2，找到返回在str1中的起始指针，未找到返回null
int main()
{
	char* p1 = "abcdefabcdef";
	char* p2 = "def";
	char* ret = strstr(p1, p2);
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
	{
		printf("%s\n", ret);//defabcdef
	}
	return 0;
}

//模拟实现
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	char* s1 = NULL;
	char* s2 = NULL;
	char* cur = (char*)p1;
	if (*p2 == '\0')//p2是空字符串
	{
		return (char*)p1;
	}
	
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		cur++;
	}
	return NULL;
}

//9.strtok

//char * strtok ( char * str, const char * sep );
/* strtok example */
#include <stdio.h>
#include <string.h>
int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
 {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
 }
  return 0;
}


#include <stdio.h>
int main()
{
   char *p = "zhangpengwei@bitedu.tech";
 const char* sep = ".@";
 char arr[30];
 char *str = NULL;
 strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
 for(str=strtok(arr, sep); str != NULL; str=strtok(NULL, sep))
 {
 printf("%s\n", str);
 }
}

//10.strerror

//char * strerror ( int errnum );//返回错误码，所对应的错误信息。
/* strerror example : error list */
#include <stdio.h>
#include <string.h>
#include <errno.h>//必须包含的头文件
int main ()
{
    //错误码
	//0 - No error
	//1 - Operation not permitted
	//2 - No such file or directory
	//3 - No such process
	//errno是一个全局的错误码的变量
	//当c语言的库函数在执行过程中，发生了错误，就会把对应的错误码赋值到errno中
	//char* str = strerror(errno);
	//打开文件
     FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	else
	{
		printf("open file success\n");
	}
	return 0;
}


