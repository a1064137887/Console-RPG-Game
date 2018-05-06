/*
File Name : CMonster.h
Function : Monster Class
Updata time : 2017 11 17
*/

#ifndef CMONSTER_H
#define CMONSTER_H
#include "Mydefine.h"
#include <string>
using namespace std;
class CRole;

class CMonster
{
public:
	virtual void tubePrint(int _x, int _y) = 0;//��ӡ����Ѫ�����������ڿ���̨��λ�ã�
	virtual int atkAction(CRole &) = 0;//����
	virtual void beenAtkAction(int) = 0;//������
	virtual void printStaticPicture(int, int) = 0;//��ֹվ��ProcessͼƬ(����:ͼƬ���Ͻǿ���̨����)
	virtual void printAttackPicture(int, int) = 0;//ƽa  ProcessͼƬ    ����Ϊ����̨����ʼ����
	virtual void cleanPixelPicture(int, int) = 0;//���ProcessͼƬ(����:ͼƬ���Ͻǿ���̨����)

	//���µ����ڿ���̨���λ�ã�
	int m_MonsterPictureX;			//����ͼƬ��ӡλ��
	int m_MonsterPictureY;

	int m_PattackM_X;					//��ɫ�������﹥������λ��
	int m_PattackM_Y;

	int m_MattackP_X;					//���﹥����ɫ��������λ��
	int m_MattackP_Y;

	int m_MinfoPut_X;					//���������ֵ�����
	int m_MinfoPut_Y;

protected:
	GET_SET(string, m_Name, Name);
	GET_SET(int, m_HP, HP);
	GET_SET(int, m_MaxHP, MaxHp);//���Ѫ��
	GET_SET(int, m_MP, MP);
	GET_SET(int, m_MaxMP, MaxMP);//�������
	GET_SET(int, m_Atk, Atk);
	GET_SET(int, m_Def, Def);
	GET_SET(int, m_ExperienceNum, ExperienceNum); //�����������������
	GET_SET(int, m_Golden, Golden);//���������������Ǯ
};

#endif