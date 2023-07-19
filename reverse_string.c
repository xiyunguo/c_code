#include <stdio.h>
#include <string.h>
//编写函数实现将参数字符串中的字符反向排列（递归实现），不能使用C函数库中的字符串操作函数

//不用递归实现strlen
int my_strlen(char* str)
{
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
//用递归实现strlen
int my_strlen1(char* str)
{
	if (*str != '\0')
		return 1 + my_strlen1(str + 1);
	else
		return 0;
}
//不用递归实现逆序
void reverse_string(char arr[])
{
    int left = 0;
    //int right = strlen(arr)-1;
    int right = my_strlen(arr)-1;

    while(left<right)
    {
        char tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }

}
//用递归实现逆序
void reverse_string1(char arr[])
{
    char tmp = arr[0];
    int len = my_strlen(arr);
    arr[0] = arr[len-1];
    arr[len-1] = '\0';
    if(my_strlen(arr+1) >= 2)
    {
        reverse_string1(arr+1);
    }
    arr[len-1] = tmp;
}
int main()
{
    char arr[] = "abcdefg";
    reverse_string1(arr);
    printf("%s\n",arr);
    return 0;
}