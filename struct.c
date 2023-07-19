typedef struct Stu
{
    char name[20];
    short age;
    char tele[12];
    char sex[5];
}Stu;

void Print(Stu s)
{
    printf("name:%s\n",s.name);
    printf("age :%d\n",s.age);
    printf("tele:%s\n",s.tele);
    printf("sex :%s\n",s.sex);

}

void Print2(Stu* ps)
{
    printf("name:%s\n",ps->name);
    printf("age :%d\n",ps->age);
    printf("tele:%s\n",ps->tele);
    printf("sex :%s\n",ps->sex);//等效于(*ps).sex


}
int main()
{
    Stu s = {"zhangsan",23,"18893227395","未知"};
    Print(s);
    Print2(&s);//首选Print2函数，函数传参的时候，参数是需要压栈的。如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销比较大，所以会导致性能的下降。
    return 0;
}