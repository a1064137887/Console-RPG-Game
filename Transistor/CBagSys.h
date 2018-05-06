/*
File Name : CBagSys.h
Function : Bag Manage Singleton
Updata time : 2017 11 11
*/

#ifndef CBAGSYS_H
#define CBAGSYS_H
#include "CSingleton.h"
#include "Game.h"
#include "CItem.h"
#include "comment.h"
#include "Mydefine.h"
#include "CRole.h"

class CBagSys :public CSingleton < CBagSys >
{
public:
	void init(char *_FileName);//��Ϸ���е�������
	void showItem(int x,int y,ItemType _type);//չʾ��Ʒ    ����Ϊ����̨����������Ʒ����ö��
	void ctrlOfShop(int x, int y, ItemType _type);//���ƣ����̵���棩    ����Ϊ����ʼλ��
	
	map<int, CItem> m_ItemContainer;
protected:
	//map<int, CItem> m_ItemContainer;
	GET_SET(CRole*, m_Player, Player);
	void printItemInfo(int x, int y, const map<int, CItem>::iterator _iter);//�����Ʒ��ϸ��Ϣ     ����Ϊ����ʼλ�ú͵�����
	void cleanItemInfo(int x, int y);//�������̨��Ʒ��ϸ��Ϣ     ����Ϊ����ʼλ��
	void cleanShopInfo(int x, int y);//�������̨��Ʒ��ϸ��Ϣ      ����Ϊ����ʼλ��
};

#endif