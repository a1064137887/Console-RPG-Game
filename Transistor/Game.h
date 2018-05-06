/*
File Name : Game.h
Function : Game Element
Updata time : 2017 11 14
*/

#ifndef GAME_H
#define GAME_H

//��ͼ����
enum MapName
{
	MN_None,
	MN_Map1,
	MN_Map2,
	MN_Map3,
	MN_Map4,
	MN_Shop,
	MN_Map5,
	MN_Boss,
};

//��ʼ�������ѡ��
enum PlayerChoose
{
	BeginGame = 26,
	LoadGame,//27
	GameExplain,//28
	Exit//29
};

//��ͼԪ��
enum MapElement
{
	None=-1,//��ͼ�еĿ�ȱ
	Road=0,//											0
	Border,//��					                        1
	Roof_Red,//�ݶ����죩��						2
	RoofTriangle1,//��									3
	RoofTriangle2,//��									4
	RoofTriangle3,//��									5
	RoofTriangle4,//��									6 
	Tree,//��												7
	Grass,//��												8
	Water,//��												9
	Window,//��											10 
	Fence,//դ��   ��									11
	Body,//��ʼ�����ʬ��							12
	Wall,//������ǽ										13
	Roof_Blue,//�ݶ�������							14
	Roof_White,//�ݶ����ף�						15
	Weapon_Person,//��������					16
	Corselet_Person,//�����ߵ�					17
	Medicine_Person,//��ҩ��						18

	//��ͼ���͵�
	Map1ToMap2=100,
	
	Map2ToMap1,//101
	Map2ToMap3,
	Map2ToShop,
	ShopToMap2,

	Map3ToMap2,//105
	Map3ToMap4,

	Map4ToMap5,//107
	Map4ToMap3,

	Map5ToMap4,//109
	Map5ToBoss,

	BossToMap5,//111
};

//��������
enum ItemType
{
	IN_None=-1,
	IN_Medicine = 0,		//ҩ��
	IN_Weapon,				//����
	IN_Corselet,				//����
	IN_Shoe,					//Ь��
	IN_Decoration			//��Ʒ
};

//��������
enum MonsterType
{
	MT_Process = 50,		//��ͨ��
	MT_Camerata,			//��Ӣ��
	MT_Boss,					//BOSS
};

//���ս���е�ѡ��
enum FightChoose
{
	FC_Atack = 3,			//����
	FC_Skill = 5,				//����
	FC_Item = 7,				//����
	FC_Run = 9,				//����
};

//����̨�����
enum SpecialPoint
{
	//���Ѫ����ӡ����
	SP_PlayerTubeX = 4,
	SP_PlayerTubeY = 50,

	//����Ѫ����ӡ����
	SP_MonsterTubeX = 4,
	SP_MonsterTubeY = 5,

	//ս����  �����Ĵ�ӡλ��
	SP_FightBagPrintX = 12,
	SP_FightBagPrintY = 37,

	//��ɫ��ӡ���ֹ������
	SP_RnamePrintX = 3,
	SP_RnamePrintY = 3,

	//�����ӡ���ֹ������
	SP_MnamePrintX = 3,
	SP_MnamePrintY = 48,
};

//��ESC��ҵ�ѡ��
enum ESCchoose
{
	E_Continue=16,		//������Ϸ
	E_Save,						//������Ϸ
	E_Menu,					//����ѡ��
	E_Exit,						//�˳���Ϸ
};
#endif