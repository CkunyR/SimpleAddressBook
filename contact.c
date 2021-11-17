

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void InitContact(struct Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, MAX * sizeof(struct PeoInfo));
	//memset(pc->data,0,sizeof(pc->data)); ��ֵ����ʽ
	//memset�����ڴ�memset(���õĶ������õ�ֵ�����õĿռ��С)
}
void AddContact(struct Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("����������:>");
		scanf("%d", &(pc->data[pc->sz].age));
		//������Ϊ������ֻ�����һ���
		//���Լ���ȡ��ַ����&
		printf("�������Ա�:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("������绰:>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("�������ַ:>");
		scanf("%s", pc->data[pc->sz].addr);
		printf("��ӳɹ�\n");
		pc->sz++;
	}
}
void ShowContact(struct Contact* pc)
{
	int i = 0;
	printf("%15s\t%5s\t%8s\t%15s\t%30s\n", "name", "age", "sex", "tele", "addr");
	for (i = 0; i < pc->sz; i++)
	{
		//��ӡÿһ������
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
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;

	}
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);//nameΪ������
	//����
	int pos = FindContactByName(pc, name);
	//ɾ��
	if (pos == -1)
	{
		printf("ָ������ϵ�˲�����");
	}
	else
	{
		int j = 0;
		for (j = pos; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�\n");
	}
}


void SearchContact(const struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("����Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("���޴���\n");
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
	printf("����Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (-1 == pos)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("�������µ�����:>");
		scanf("%s", pc->data[pos].name);
		printf("�������µ�����:>");
		scanf("%d", &(pc->data[pos].age));
		//������Ϊ������ֻ�����һ���
		//���Լ���ȡ��ַ����&
		printf("�������µ��Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("�������µĵ绰:>");
		scanf("%s", pc->data[pos].tele);
		printf("�������µĵ�ַ:>");
		scanf("%s", pc->data[pos].addr);


	}

}
