

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"contact.h"
void menu()//����
{
	printf("******************************\n");
	printf("****** 1.���    2.ɾ��    ***\n");
	printf("****** 3.����    4.�޸�    ***\n");
	printf("****** 5.�鿴    0.�˳�    ***\n");
	printf("******************************\n");
}
enum Option//ö������
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
	//����һ��ͨѶ¼
	/* struct�Ƕ���ṹ��Ĺؼ���
	Contact�ǽṹ�������
		con�ǽṹ�����
		��C����  ���Ҫ�����ṹ�����  �����ڽṹ������ǰ��struct
		Ҳ���� struct Contact    ����൱����һ���µ�����  ��int֮�������*/
	struct Contact con;//����ṹ�����
	//��ʼ��ͨѶ¼
	InitContact(&con);//��con�ĵ�ַ����InitContact���� �Դ������г�ʼ��con
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}