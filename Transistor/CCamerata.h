/*
File Name : CCamerata.h
Function : Camerata Class
Updata time : 2017 11 16
*/

#ifndef CCAMERATA_H
#define CCAMERATA_H

#include "CMonster.h"

class CCamerata :public CMonster
{
public:
	CCamerata();
	void tubePrint(int _x, int _y);//��ӡѪ������ ��������ͼƬ���Ͻǿ���̨���꣩
	int atkAction(CRole &);//����
	void beenAtkAction(int);//������
	void printStaticPicture(int, int);//��ֹվ��ProcessͼƬ(������ͼƬ���Ͻǿ���̨����)
	void cleanPixelPicture(int, int);//���ProcessͼƬ(������ͼƬ���Ͻǿ���̨����)
	void printAttackPicture(int, int);//ƽa  ProcessͼƬ    ����Ϊ����̨����ʼ����
};

#endif