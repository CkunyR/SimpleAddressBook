

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void InitContact(struct Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, MAX * sizeof(struct PeoInfo));
	//memset(pc->data,0,sizeof(pc->data)); 等值于上式
	//memset设置内存memset(设置的对象，设置的值，设置的空间大小)
}
void AddContact(struct Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录满了\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pc->sz].age));
		//其他项为数组名只有这个一项不是
		//所以加上取地址符号&
		printf("请输入性别:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[pc->sz].addr);
		printf("添加成功\n");
		pc->sz++;
	}
}
void ShowContact(struct Contact* pc)
{
	int i = 0;
	printf("%15s\t%5s\t%8s\t%15s\t%30s\n", "name", "age", "sex", "tele", "addr");
	for (i = 0; i < pc->sz; i++)
	{
		//打印每一个数据
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}
int FindContactByName(const struct Contact* pc, const char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;

}
void DelContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;

	}
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除人的名字:>");
	scanf("%s", name);//name为数组名
	//查找
	int pos = FindContactByName(pc, name);
	//删除
	if (pos == -1)
	{
		printf("指定的联系人不存在");
	}
	else
	{
		int j = 0;
		for (j = pos; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}


void SearchContact(const struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%15s\t%5s\t%8s\t%15s\t%30s\n", "name", "age", "sex", "tele", "addr");
		printf("%15s\t%5d\t%8s\t%15s\t%30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}
void ModifyContact(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入新的名字:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入新的年龄:>");
		scanf("%d", &(pc->data[pos].age));
		//其他项为数组名只有这个一项不是
		//所以加上取地址符号&
		printf("请输入新的性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);


	}

}
