/*
File Name : CUISceneSys.h
Function : UI Control System
Updata time : 2017 11 10
*/

#ifndef GUISCENESYS_H
#define GUISCENESYS_H
#include "CSingleton.h"
#include "CBeginScene.h"
#include "Game.h"
#include "CMap.h"
#include "comment.h"

class CUISceneSys :public CSingleton < CUISceneSys >
{
public:
	CBeginScene BeginScene;

	void init();//��ʼ��
	void loadAllMap();//�������е�ͼ

	CMap* getMap(int _MapName);//��õ�ͼ

	void changeInMap(int _name, CRole* _player);//����ҷ����ͼ

	void setMonster(CMap &_map);//����ͼɢ�����   ����Ϊ��ͼ

	void freeAllMap();//�ͷ����е�ͼ

protected:
	map<int, CMap*> m_MapContainer;//���������Ϸ��ͼ������

	CMap *m_pGameMap;//��ͼָ��
	MapName m_MapName;//��ͼ����
};

#endif