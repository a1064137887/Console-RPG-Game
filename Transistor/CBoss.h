/*
File Name : CBoss.h
Function : Boss Class
Updata time : 2017 11 17
*/

#ifndef CBOSS_H
#define CBOSS_H
#include "CMonster.h"

class CBoss :public CMonster
{
public:
	CBoss();
	void tubePrint(int _x, int _y);//��ӡѪ������ ��������ͼƬ���Ͻǿ���̨���꣩
	int atkAction(CRole &);//����
	void beenAtkAction(int);//������
	void printStaticPicture(int, int);//��ֹվ��ProcessͼƬ(������ͼƬ���Ͻǿ���̨����)
	void cleanPixelPicture(int, int);//���ProcessͼƬ(������ͼƬ���Ͻǿ���̨����)
	void printAttackPicture(int, int);//ƽa  ProcessͼƬ    ����Ϊ����̨����ʼ����
};

#endif