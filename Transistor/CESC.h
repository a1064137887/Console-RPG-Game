/*
FIle Name : CESC.h
Function : ESC choose UI
Updata time : 2017 11 17
*/

#ifndef CESC_H
#define CESC_H
#include "CSingleton.h"
#include "Mydefine.h"
#include "CRole.h"

class CESC :public CSingleton < CESC >
{
public:
	void print();//��ӡ����
	int ctrlOfSence();//���ƣ���ESC�����У�
	void action(int cursor);//����ѡ����������   ����Ϊ���λ��
	void saveInXML();//�浽XML�ļ���
	GET_SET(CRole*, m_Player, Player);
};

#endif