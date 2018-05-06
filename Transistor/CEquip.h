/*
File Name : CEquip.h
Function : Equipment Information
Updata time : 2017 11 15
*/

#ifndef CEQUIP_H
#define CEQUIP_H
#include "comment.h"
#include "Game.h"
#include "CItem.h"

class CEquip
{
public:
	void printUI(int x,int y);//��ӡװ����    ����Ϊ����̨����ʼλ��
	map<int, CItem> m_EquipContainer;
	void cleanEquipUI(int x, int y);//�������̨      ����Ϊ����̨����ʼλ��
	void printEquipInfo(int x, int y,const map<int,CItem>::iterator _iter);//��ӡװ����ϸ��Ϣ      ����Ϊ����̨����ʼλ��
	void cleanEquipInfo(int x, int y);//�������̨       ����Ϊ����̨����ʼλ��
};

#endif