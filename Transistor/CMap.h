/*
File Name:CMap.h
Function:Map Class
Updata time:2017 11 16
*/

#ifndef CMAP_H
#define CMAP_H
#include  "CRole.h"

class CMap
{
public:
	CMap();
	~CMap();
	int **m_pMap;//��ŵ�ͼԪ�صĶ���ָ��
	void setMapFromFile(char *);//���ļ������ͼ��Ϣ
	void print();//��ӡ��ͼ
	void ctrlOfMap();//���ƣ��ڵ�ͼ�У�
	int interactOfMap(int dx, int dy);//��ͼ����������ֵΪ��ͼԪ�أ�
	void printPlayerInfo();//���ı�������ӡ��ɫ��Ϣ
	void cleanRoleInfo();//�����ڿ���̨����Ľ�ɫ�ĸ�����Ϣ

private:
	GET_SET(int, m_Row, Row);
	GET_SET(int, m_Col, Col);
	int m_textPositionX;//�ı������������
	int m_textPositionY;//�ı������������
	void initMemory();//�����ڴ�
	void interactOfMapElement(int dx, int dy);//����ƫ����������Ӧ����
	void rePrint();//�黹��ͼԪ��
	GET_SET(CRole*, m_Player, Player);//���ָ��
	bool m_isBody;//��¼�Ƿ�����ʬ��
	void collisionBody();//��������ʬ�崥������
};


#endif