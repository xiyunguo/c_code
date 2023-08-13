#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SIZE * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;//设置通讯录最初只有0个元素
	ps->capacity = DEFAULT_SIZE;
}
static void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//增容
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
	//检测当前通讯录的容量
	//1.如果满了，就增加空间
	//2.如果不满，啥事都不干
	CheckCapacity(ps);
	//增加数据
	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入号码:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址:>");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("新增成功\n");
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-3s\t%-5s\t%-12s\t%-30s\t\n", "姓名", "年龄", "性别", "号码", "地址");
			printf("%-10s\t%-3d\t%-5s\t%-12s\t%-30s\t\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//找不到的情况
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的名字:>");
	scanf("%s", &name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改的名字:>");
	scanf("%s", &name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("姓名:>");
		scanf("%s", ps->data[ret].name);
		printf("年龄:>");
		scanf("%d", &(ps->data[ret].age));
		printf("性别:>");
		scanf("%s", ps->data[ret].sex);
		printf("号码:>");
		scanf("%s", ps->data[ret].tele);
		printf("地址:>");
		scanf("%s", ps->data[ret].addr);
		printf("修改成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的名字:>");
	scanf("%s", &name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%-10s\t%-3s\t%-5s\t%-12s\t%-30s\t\n", "姓名", "年龄", "性别", "号码", "地址");
		printf("%-10s\t%-3d\t%-5s\t%-12s\t%-30s\t\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr);
	}
}

static int cmp_contact_by_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}
static int cmp_contact_by_name(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用><=比较，应该用strcmp函数
	return strcmp(((struct PeoInfo*)e1)->name,((struct PeoInfo*)e2)->name);
}
static int cmp_contact_by_sex(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用><=比较，应该用strcmp函数
	return strcmp(((struct PeoInfo*)e1)->sex, ((struct PeoInfo*)e2)->sex);
}
static int cmp_contact_by_tele(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用><=比较，应该用strcmp函数
	return strcmp(((struct PeoInfo*)e1)->tele, ((struct PeoInfo*)e2)->tele);
}
static int cmp_contact_by_addr(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用><=比较，应该用strcmp函数
	return strcmp(((struct PeoInfo*)e1)->addr, ((struct PeoInfo*)e2)->addr);
}

static void Swap(char* buf1, char* buf2, int width)
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
static void bubble_sort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))
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
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) >
				0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,
					width);
			}
		}
	}
}



static void menu_sort()
{
	printf("---------------------\n");
	printf("***1.name   2.age***\n");
	printf("***3.sex    4.tele**\n");
	printf("***5.addr   0.exit**\n");
	printf("---------------------\n");
}
void SortContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int input1 = 0;
		menu_sort();
		printf("请选择排序方式:>");
		scanf("%d", &input1);
		switch (input1)
		{
		case exit1:
			printf("退出Sort\n");
			break;
		case name:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_name);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_name);
			printf("排序成功\n");
			ShowContact(ps);
			break;
		case age:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_age);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_age);
			printf("排序成功\n");
			ShowContact(ps);
			break;
		case sex:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_sex);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_sex);
			printf("排序成功\n");
			ShowContact(ps);
			break;
		case tele:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_tele);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_tele);
			printf("排序成功\n");
			ShowContact(ps);
			break;
		case addr:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_addr);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_addr);
			printf("排序成功\n");
			ShowContact(ps);
			break;
		default:
			printf("选择排序方式错误\n");
			break;
		}	
	}
}


void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}