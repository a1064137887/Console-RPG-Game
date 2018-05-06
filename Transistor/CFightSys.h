/*
File Name : CFightSys.h
Function : Fight Control System
Updata time : 2017 11 19
*/

#ifndef CFIGHTSYS_H
#define CFIGHTSYS_H

#include "CSingleton.h"
#include "Mydefine.h"
#include "Game.h"
class CRole;
class CMonster;

class CFightSys :public CSingleton < CFightSys >
{
public:
	void printFightUI();	//��ӡս������
	bool ctrlOfFight(MonsterType _MonsterType);	//���ƣ���ս���У�����Ϊ��������ö��

protected:
	GET_SET(CRole*, m_Player, Player);	//���ָ��
	void upMonsterInfo(CMonster *);		//��������ȼ������ֵ�����
	bool isMonsterDead(const CMonster *_monster);					//�жϹ��Ƿ�����		��������true
	bool isPlayerDead();			//�ж������Ƿ�����        ��������true
	void PaMvideo(CMonster *pMonster);			//��ɫ�����ֶ���		����Ϊ����ָ��
	void MaPvideo(CMonster *pMonster,MonsterType _MonsterType);			//�ֹ�����ɫ����		����Ϊ����ָ��͹�������
};

#endif