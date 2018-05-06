/*
File Name : CRoleBag.h
Function : Bag Blongs Role
Updata time : 2017 11 16
*/

#ifndef CROLEBAG_H
#define CROLEBAG_H
#include "comment.h"
#include "CItem.h"

class CRoleBag
{
public:
	CRoleBag();
	void addItem(CItem &_Item);//�����Ʒ���뱳��
	int searchItem(int _ID);//�ӱ����в�����Ʒ������ֵΪ�±�
	void printBag(int x,int y);//�����鿴      ����Ϊ����ʼλ��
	void setBagSize(int _size);//���ñ�����С
	void printItemInfo(int x, int y, const vector<CItem>::iterator _iter);//�����Ʒ��ϸ��Ϣ     ����Ϊ����ʼλ�ú͵�����
	void cleanBagInfo(int x, int y);//�������̨������Ϣ         ����Ϊ����ʼλ��
	void cleanItemInfo(int x, int y);//�������̨��Ʒ��ϸ��Ϣ     ����Ϊ����ʼλ��

	vector<CItem> m_BagContainer;


	int m_Size;//��������
	int m_MaxSize;//�����������

};

#endif