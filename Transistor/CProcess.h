/*
File Name : CProcess.h
Function : Process Class
Updata time : 2017 11 3
*/

#ifndef CPROCESS_H
#define CPROCESS_H
#include "CMonster.h"
class CRole;

class CProcess:public CMonster
{	
public:
	CProcess();
	void tubePrint(int _x, int _y);//��ӡѪ������ ��������ͼƬ���Ͻǿ���̨���꣩
	int atkAction(CRole &);//����
	void beenAtkAction(int);//������
	void printStaticPicture(int, int);//��ֹվ��ProcessͼƬ(������ͼƬ���Ͻǿ���̨����)
	void cleanPixelPicture(int, int);//���ProcessͼƬ(������ͼƬ���Ͻǿ���̨����)
	void printAttackPicture(int, int);//ƽa  ProcessͼƬ    ����Ϊ����̨����ʼ����
};

#endif