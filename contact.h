#pragma once

#pragma once

#include<string.h>
//为了以后修改变量的简便从而创建了全局变量
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define MAX 1000
//描述单个人的信息
struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};
struct Contact
{
	struct PeoInfo data[MAX];//PeoInfo 是数组的类型 data是数组名
	//1000个人的数据存放在data数组中 因为PeoInfo中包含一个人的全部信息
	//所以直接使用PeoInfo这个结构体名字来定义一个结构体数组
	int sz;//记录当前通讯录有效信息的个数
};
//初始化通讯录
void InitContact(struct Contact* pc);

//增加联系人
void AddContact(struct Contact* pc);

//显示联系人
void ShowContact(struct Contact* pc);

//删除指定联系人
void DelContact(struct Contact* pc);

//查找指定联系人
void SearchContact(const struct Contact* pc);

//修改指定联系人

