

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"contact.h"
void menu()//界面
{
	printf("******************************\n");
	printf("****** 1.添加    2.删除    ***\n");
	printf("****** 3.搜索    4.修改    ***\n");
	printf("****** 5.查看    0.退出    ***\n");
	printf("******************************\n");
}
enum Option//枚举类型
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
int main()
{
	int input = 0;
	//创建一个通讯录
	/* struct是定义结构体的关键字
	Contact是结构体的名字
		con是结构体变量
		在C语言  如果要创建结构体变量  必须在结构体名字前加struct
		也就是 struct Contact    这个相当于是一个新的类型  和int之类的类似*/
	struct Contact con;//定义结构体变量
	//初始化通讯录
	InitContact(&con);//将con的地址传给InitContact函数 以此来进行初始化con
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}