/*
File name : CBeginScene.h
Function : Game Begin UI
Updata time : 2017 11 10
*/

#ifndef CBEGINSCENE_H
#define CBEGINSCENE_H
#include "CSingleton.h"

class CBeginScene:public CSingleton<CBeginScene>
{
public:
	void print();//��ӡ����
	int ctrlOfScene();//���ƣ��ڳ����У�
	void action(int _flag);//����ѡ����������   ����Ϊ���λ��

protected:
	void printGameExplain();//��ӡ��Ϸ��ʾ
};

#endif