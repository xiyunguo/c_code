#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SIZE * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
	ps->capacity = DEFAULT_SIZE;
}
static void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
	//��⵱ǰͨѶ¼������
	//1.������ˣ������ӿռ�
	//2.���������ɶ�¶�����
	CheckCapacity(ps);
	//��������
	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("����������:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("���������:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ:>");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("�����ɹ�\n");
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-3s\t%-5s\t%-12s\t%-30s\t\n", "����", "����", "�Ա�", "����", "��ַ");
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
	return -1;//�Ҳ��������
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ��������:>");
	scanf("%s", &name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ�����:>");
	scanf("%s", &name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("����:>");
		scanf("%s", ps->data[ret].name);
		printf("����:>");
		scanf("%d", &(ps->data[ret].age));
		printf("�Ա�:>");
		scanf("%s", ps->data[ret].sex);
		printf("����:>");
		scanf("%s", ps->data[ret].tele);
		printf("��ַ:>");
		scanf("%s", ps->data[ret].addr);
		printf("�޸ĳɹ�\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�����:>");
	scanf("%s", &name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%-10s\t%-3s\t%-5s\t%-12s\t%-30s\t\n", "����", "����", "�Ա�", "����", "��ַ");
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
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ����><=�Ƚϣ�Ӧ����strcmp����
	return strcmp(((struct PeoInfo*)e1)->name,((struct PeoInfo*)e2)->name);
}
static int cmp_contact_by_sex(const void* e1, const void* e2)
{
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ����><=�Ƚϣ�Ӧ����strcmp����
	return strcmp(((struct PeoInfo*)e1)->sex, ((struct PeoInfo*)e2)->sex);
}
static int cmp_contact_by_tele(const void* e1, const void* e2)
{
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ����><=�Ƚϣ�Ӧ����strcmp����
	return strcmp(((struct PeoInfo*)e1)->tele, ((struct PeoInfo*)e2)->tele);
}
static int cmp_contact_by_addr(const void* e1, const void* e2)
{
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ����><=�Ƚϣ�Ӧ����strcmp����
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
//ʵ��bubble_sort�����ĳ���Ա�����Ƿ�֪��δ���������������--��֪��
//�ǳ���ԱҲ��֪�������Ƚϵ�����Ԫ�ص�����
static void bubble_sort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))
{
	int i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		//ÿһ�˱ȽϵĶ���
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//����Ԫ�صıȽ�
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) >
				0)
			{
				//����
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
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int input1 = 0;
		menu_sort();
		printf("��ѡ������ʽ:>");
		scanf("%d", &input1);
		switch (input1)
		{
		case exit1:
			printf("�˳�Sort\n");
			break;
		case name:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_name);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_name);
			printf("����ɹ�\n");
			ShowContact(ps);
			break;
		case age:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_age);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_age);
			printf("����ɹ�\n");
			ShowContact(ps);
			break;
		case sex:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_sex);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_sex);
			printf("����ɹ�\n");
			ShowContact(ps);
			break;
		case tele:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_tele);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_tele);
			printf("����ɹ�\n");
			ShowContact(ps);
			break;
		case addr:
			//qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_addr);
			bubble_sort(ps->data, ps->size, sizeof(ps->data[0]), cmp_contact_by_addr);
			printf("����ɹ�\n");
			ShowContact(ps);
			break;
		default:
			printf("ѡ������ʽ����\n");
			break;
		}	
	}
}


void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}