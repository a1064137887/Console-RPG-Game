/*
File Name : CRole.h
Function : Role Class
Updata time : 2017 11 16
*/

#ifndef CROLE_H
#define CROLE_H
#include "comment.h"
#include "Mydefine.h"
#include "CRoleBag.h"
#include "CEquip.h"

class CRoleBag;
class CEquip;
class CMonster;

class CRole
{
public:
	CRole();
	void move(int dx, int dy);//�ƶ�
	void setPosition(int _x, int _y);//���ý�ɫ����
	void print();//��ӡ��ɫ
	void getPosition(int &_x, int &_y);//�����������
	void setPlayerInfoFromXML(const char *_FileName);//��XML�ļ��ж�ȡ�����ʼ��Ϣ
	void outputBag(int _x,int _y);//�鿴����      ����Ϊ����ʼλ��
	void ctrlOfBag(int _x, int _y);//���ƣ��ڱ�����	��ս״̬��     ����Ϊ����ʼλ��
	void ctrlOfBagInFight(int _x, int _y);//���ƣ��ڱ�����		ս��״̬��      ����Ϊ����ʼλ��
	void outputEquip(int _x, int _y);//�鿴װ����      ����Ϊ����ʼλ��
	void ctrlOfEquip(int _x, int _y);//���ƣ���װ�����У�  ����Ϊ����ʼλ��
	int atkAction(CMonster &);//����    ����ֵΪ�˺���ֵ
	void beenAtkAction(int _hurt);//����������   ����Ϊ�˺�ֵ
	void tubePrint(int _x,int _y);//��ӡ����Ѫ�����������ڿ���̨��λ�ã�
	void upLevel();		//����
	void upInfo();		//���ݵȼ���������
	
	int skill1(CMonster &_monster);//����1
	void printSkill1Picture(int x, int y);//��ӡ����1��ͼƬ     ����Ϊ����̨����ʼλ��
	void cleanSkill1Picture(int x, int y);//�������ͼƬ     ����Ϊ����̨����ʼλ��
	void printStaticPicture(int _x, int _y);//��ֹվ������ͼƬ(����:ͼƬ���Ͻǿ���̨����)
	void printAttackPicture(int _x, int _y);//ƽa����ͼƬ     ����Ϊ����̨����ʼλ��
	void cleanPixelPicture(int _x, int _y);//�������ͼƬ(����:ͼƬ���Ͻǿ���̨����)

	int m_PlayerPictureX;				//��ɫͼƬ��ӡλ��
	int m_PlayerPictureY;

	int m_RinfoPut_X;					//��ɫ�����ֵ�����
	int m_RinfoPut_Y;

	friend CRole& operator+(CRole &_role, CMonster &_monster);		//����+�����  ���Ӿ���

	CRoleBag m_Bag;    //���ﱳ��
	CEquip m_Equip;     //����װ��

protected:
	GET_SET(string, m_Name, Name);
	GET_SET(int, m_PositionX, PositionX);
	GET_SET(int, m_PositionY, PositionY);
	GET_SET(int, m_Golden, Golden);
	GET_SET(int, m_HP, HP);
	GET_SET(int, m_MP, MP);
	GET_SET(int, m_MaxHP, MaxHP);
	GET_SET(int, m_MaxMP, MaxMP);
	GET_SET(int, m_Atk, Atk);
	GET_SET(int, m_Def, Def);
	GET_SET(int, m_InMapName, InMapName);			//��ɫ���ڵ�ͼ����
	GET_SET(int, m_BagSize, BagSize);			//�����ʼ�����ߴ�
	GET_SET(int, m_Level, Level);			//��ɫ�ȼ�
	GET_SET(int, m_Experience, Experience);				//����
	GET_SET(int, m_UpExperience, UpExperience);		//�������辭��

	void maxInfoProtect();				//�������ֵ����
};

#endif;