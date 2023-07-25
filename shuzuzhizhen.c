int (*p)[10];
//解释：p先和*结合，说明p是一个指针变量，然后指针指向的是一个大小为10个整型的数组。所以p是一个指针，指向一个数组，叫数组指针。
//这里要注意：[]的优先级要高于*号的，所以必须加上()来保证p先和*结合


#include <stdio.h>
int main()
{
	int arr[10] = {0};
	printf("%p\n",arr);
	printf("%p\n",&arr);
	return 0;
}//打印地址是一样的


#include <stdio.h>
int main()
{
	int arr[10] = {0};
	printf("arr = %p\n",arr);
	printf("&arr = %p\n",&arr);
	
	printf("arr+1 = %p\n",arr+1);//地址+4
	printf("&arr+1 = %p\n",&arr+1);//地址+40
	return 0;
}


//数组指针的使用
#include <stdio.h>
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	int (*p)[10] = &arr;//把数组arr的地址赋值给数组指针变量p，但是我们一般很少这样写代码
	return 0;
}


//一个例子

#include <stdio.h>
//参数是数组的形式
void print_arr1(int arr[3][5],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
//参数是指针的形式
void print_arr2(int (*arr)[5],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
            printf("%d ",*(*(arr+i)+j));
            printf("%d ",*(arr[i]+j));
            printf("%d ",arr[i][j]);
            printf("%d ",(*(arr+i))[j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = {1,2,3,4,5,6,7,8,9,10};
	print_arr1(arr,3,5);
	//数组名arr，表示首元素的地址
	//但是二维数组的首元素是二维数组的第一行
	//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
	//可以数组指针来接收
	print_arr2(arr,3,5);
	return 0;
}



int arr[5];//arr是一个整型数组，数组5个元素，每个元素是整型
int *parr1[10];//parr1是一个数组，数组有10个元素，每个元素的类型是int*   parr1是指针数组
int (*parr2)[10];//parr2是一个指针，指针指向了一个数组，数组10个元素，每个元素的类型是int   parr2是数组指针
int (*parr3[10])[5];//parr3是一个数组，该数组有10个元素，每个元素是一个数组指针，该数组指针指向的数组有5个元素，每个元素是int