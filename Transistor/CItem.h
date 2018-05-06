/*
File Name : CItem.h
Function : Item Class
Updata time : 2017 11 14
*/


#ifndef CITEM_H
#define CITEM_H
#include "Game.h"
#include "comment.h"
class CRole;

class CItem
{
public:
	CItem();

	string m_Name;
	int m_ID;//��Ʒö����
	string m_Describe;//��Ʒ��Ч����
	//=========��������
	int m_HP;//��Ѫ��
	int m_MP;//������
	int m_Atk;//���ӹ�����
	int m_Def;//���ӷ�����

	//==========��Ʒ����
	int m_Num;//����
	int m_Overly;//��������     1Ϊ�ɵ���    0Ϊ���ɵ���
	int m_Price;//��Ʒ�۸�
	int m_Type;//��Ʒ����

	friend CRole& operator+(CRole &_role, CItem &_item);     //���� + �����������ֵ����
	friend CRole& operator-(CRole &_role, CItem &_item);     //���� - �����������ֵ����
};

#endif