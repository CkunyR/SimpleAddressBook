#pragma once

#pragma once

#include<string.h>
//Ϊ���Ժ��޸ı����ļ��Ӷ�������ȫ�ֱ���
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define MAX 1000
//���������˵���Ϣ
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
	struct PeoInfo data[MAX];//PeoInfo ����������� data��������
	//1000���˵����ݴ����data������ ��ΪPeoInfo�а���һ���˵�ȫ����Ϣ
	//����ֱ��ʹ��PeoInfo����ṹ������������һ���ṹ������
	int sz;//��¼��ǰͨѶ¼��Ч��Ϣ�ĸ���
};
//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);

//������ϵ��
void AddContact(struct Contact* pc);

//��ʾ��ϵ��
void ShowContact(struct Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(struct Contact* pc);

//����ָ����ϵ��
void SearchContact(const struct Contact* pc);

//�޸�ָ����ϵ��

