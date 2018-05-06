#include "CBoss.h"
#include "comment.h"
#include "CRole.h"

CBoss::CBoss()
{
	m_Name = "Royce";
	m_HP = 20480;
	m_MP = 12000;
	m_Atk = 500;
	m_Def = 360;
	m_MaxHP = 20480;
	m_MaxMP = 12000;

	m_MonsterPictureX = 13;
	m_MonsterPictureY = 12;

	m_PattackM_X = 13;
	m_PattackM_Y = 28;

	m_MattackP_X = 13;
	m_MattackP_Y = 34;

	m_MinfoPut_X = 10;
	m_MinfoPut_Y = 19;

	m_ExperienceNum = 15000;

	m_Golden = 15000;
}


//��ӡѪ������ ��������ͼƬ���Ͻǿ���̨���꣩
void CBoss::tubePrint(int _x, int _y)
{
	int FallHPCell = m_MaxHP / 20;//�ó�һ��Ѫ����
	int FallMPCell = m_MaxMP / 20;//�ó�һ��������
	int HPTubeArr[20] = { 0 };//�������Ѫ�������飬5%Ϊһ��0������Ѫ
	int MPTubeArr[20] = { 0 };//����������������飬5%Ϊһ��0��������

	if (0 > m_HP)
	{
		m_HP = 0;//Ѫ������
		for (int i = 19; i >= 0; i--)
			HPTubeArr[i] = 1;
	}

	for (int i = 19; i > (0 == m_HP%FallHPCell ? m_HP / FallHPCell - 1 : m_HP / FallHPCell); i--)
	{
		HPTubeArr[i] = 1;
	}

	gotoXY(_x++, _y); color(4);
	for (int i = 0; i < sizeof(HPTubeArr) / 4; i++)
	{
		switch (HPTubeArr[i])
		{
		case 0:cout << "��"; break;
		case 1:cout << "��"; break;
		default:break;
		}
	}

	color(15); cout << "  " << m_HP << "      ";

	if (0 > m_MP)
	{
		m_MP = 0;//��������
		for (int i = 19; i >= 0; i--)
			MPTubeArr[i] = 1;
	}

	for (int i = 19; i > (0 == m_MP%FallMPCell ? m_MP / FallMPCell - 1 : m_MP / FallMPCell); i--)
	{
		MPTubeArr[i] = 1;
	}

	gotoXY(_x, _y); color(1);
	for (int i = 0; i < sizeof(MPTubeArr) / 4; i++)
	{
		switch (MPTubeArr[i])
		{
		case 0:cout << "��"; break;
		case 1:cout << "��";  break;
		default:break;
		}
	}
	color(15); cout << "  " << m_MP << "      ";
}


//��ֹվ��RoyceͼƬ(����:ͼƬ���Ͻǿ���̨����)
void CBoss::printStaticPicture(int _PositionX, int _PositionY)
{
	int MonsterStatic_1[15][15] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0,      //1��ɫ  2��ɫ   3��ɫ   4��ɫ
		0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0,     //5����ɫ    6��ɫ    7���    8���
		0, 0, 2, 3, 3, 2, 1, 1, 1, 2, 3, 2, 3, 7, 0,   //0��ɫ
		0, 2, 3, 3, 3, 2, 1, 3, 2, 3, 2, 3, 2, 6, 0, 
		0, 2, 2, 3, 2, 1, 3, 1, 1, 1, 1, 1, 1, 5, 0,
		0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0,
		0, 4, 4, 4, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0,
		4, 4, 4, 4, 4, 4, 1, 1, 5, 0, 0, 0, 0, 0, 0,
		4, 8, 4, 8, 4, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 4, 8, 0,
		1, 5, 0, 0, 1, 1, 4, 1, 1, 1, 1, 5, 4, 8, 0,
		1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 4, 8, 0, 0,
		0, 1, 1, 1, 5, 4, 4, 4, 4, 8, 0, 4, 8, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	};

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			gotoXY(_PositionX + i, _PositionY + j);
			switch (MonsterStatic_1[i][j])
			{
			case 0:cout << "  "; break;
			case 1:color(10); cout << "��"; break;
			case 2:color(15); cout << "��"; break;
			case 3:color(0); cout << "��"; break;
			case 4:color(12); cout << "��"; break;
			case 5:color(2); cout << "��"; break;
			case 6:color(7); cout << "��"; break;
			case 7:color(8); cout << "��"; break;
			case 8:color(4); cout << "��"; break;
			case 9:color(14); cout << "��"; break;
			case 10:color(6); cout << "��"; break;
			}
		}
		cout << endl;
	}
}

//ƽa  RoyacͼƬ    ����Ϊ����̨����ʼ����
void CBoss::printAttackPicture(int _PositionX, int _PositionY)
{
	int MonsterStatic_2[15][20] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0,
		0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 10, 4, 8,		//1��ɫ  2��ɫ   3��ɫ   4��ɫ
		0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 9, 10, 4, 8,		//5����ɫ    6��ɫ    7���    8���
		0, 0, 2, 3, 3, 2, 1, 1, 1, 2, 3, 2, 3, 7, 0, 9, 9, 10, 4, 4,		//0��ɫ
		0, 2, 3, 3, 3, 2, 1, 3, 2, 3, 2, 3, 2, 6, 0, 0, 0, 4, 4, 0, 
		0, 2, 2, 3, 2, 1, 3, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0,			//9ǳ��    10��
		0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0,
		0, 4, 4, 4, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		4, 4, 4, 4, 4, 4, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		4, 8, 4, 8, 4, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 4, 8, 0, 0, 0, 0, 0, 0,
		1, 5, 0, 0, 1, 1, 4, 1, 1, 1, 1, 5, 4, 8, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 4, 8, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 1, 5, 4, 4, 4, 4, 8, 0, 4, 8, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			gotoXY(_PositionX + i, _PositionY + j);
			switch (MonsterStatic_2[i][j])
			{
				case 0:cout << "  "; break;
				case 1:color(10); cout << "��"; break;
				case 2:color(15); cout << "��"; break;
				case 3:color(0); cout << "��"; break;
				case 4:color(12); cout << "��"; break;
				case 5:color(2); cout << "��"; break;
				case 6:color(7); cout << "��"; break;
				case 7:color(8); cout << "��"; break;
				case 8:color(4); cout << "��"; break;
				case 9:color(14); cout << "��"; break;
				case 10:color(6); cout << "��"; break;
			}
		}
		cout << endl;
	}

}

//���ProcessͼƬ(������ͼƬ���Ͻǿ���̨����)
void CBoss::cleanPixelPicture(int _PositionX, int _PositionY)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			gotoXY(_PositionX + i, _PositionY + j);
			cout << "  ";
		}
		cout << endl;
	}
}

//����
int CBoss::atkAction(CRole &_Role)
{
	int hurt = m_Atk - _Role.getDef();

	if (hurt < 0)				//�ж��˺��Ƿ�δ������ǿ���Ƽ�
		hurt = 1;

	_Role.beenAtkAction(hurt);

	return hurt;
}

//������
void CBoss::beenAtkAction(int _hurt)
{
	m_HP -= _hurt;
}