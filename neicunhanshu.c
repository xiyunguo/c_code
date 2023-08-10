//内存函数举例

//1.memcpy

//void * memcpy ( void * destination, const void * source, size_t num );
//用法
/* memcpy example */
#include <stdio.h>
#include <string.h>
struct {
	char name[40];
	int age;
} person, person_copy;
int main()
{
	char myname[] = "Pierre de Fermat";
	/* using memcpy to copy string: */
	memcpy(person.name, myname, strlen(myname)+1 );
	person.age = 46;
	/* using memcpy to copy structure: */
	memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
	return 0;
}

//模拟实现
#include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}

struct s 
{
	char name[20];
	int age;
};
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[10] = { 1 };
	struct s arr3[] = { {"张三",20},{"李四",30} };
	struct s arr4[3] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	my_memcpy(arr4, arr3, sizeof(arr3));
	return 0;
}

//2.memmove

//void * memmove ( void * destination, const void * source, size_t num );
//用法
/* memmove example */
#include <stdio.h>
#include <string.h>
int main ()
{
  char str[] = "memmove can be very useful......";
  memmove (str+20,str+15,11);
  puts (str);
  return 0;
}

/* memmove example */
#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);//memmove can be very very useful.
	return 0;
}

//模拟实现
#include <stdio.h>
//C语言标准
//memcpy只要处理不重叠的内存拷贝就可以
//memmove处理重叠内存的拷贝
void* my_memmove(void* dest,void* src,size_t num)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	if (dest < src)
	{
		//前->后
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}	
	}
	else
	{
		//后->前
		dest = (char*)dest + num - 1;
		src = (char*)src + num - 1;
		while (num--)
		{
			*(char*)dest = *(char*)src;
			--(char*)dest;
			--(char*)src;
		}
	}
	return ret;
}
void* my_memmove2(void* dest, void* src, size_t num)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	if (dest < src || dest>(char*)src+num)
	{
		//前->后
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		//后->前
		dest = (char*)dest + num - 1;
		src = (char*)src + num - 1;
		while (num--)
		{
			*(char*)dest = *(char*)src;
			--(char*)dest;
			--(char*)src;
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	//my_memcpy(arr + 2, arr, 20);//不能实现
	//memcpy(arr + 2, arr, 20);//超额实现
	my_memmove2(arr+2 , arr, 20);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


//3.memcmp

//int memcmp ( const void * ptr1,  const void * ptr2,  size_t num );
//用法
/* memcmp example */
#include <stdio.h>
#include <string.h>
int main ()
{
  char buffer1[] = "DWgaOtP12df0";
  char buffer2[] = "DWGAOTP12DF0";
  int n;
  n=memcmp ( buffer1, buffer2, sizeof(buffer1) );
  if (n>0) printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
  else if (n<0) printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
  else printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);
  return 0;
}


/*memcmp example*/
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 };
	int ret = memcmp(arr1, arr2, 8);
	printf("%d\n", ret);//0
	return 0;
}
/*memset example*/
int main52()
{
	//char arr[10] = "";
	//memset(arr, '#', 10);//10个字节
	int arr[10] = { 0 };
	memset(arr, 1, 10);//01 01 01 01 01 01 01 01 01 01 00 00 00 00 00 00...
	return 0;
}