#include "CEquip.h"


//��ӡװ����    ����Ϊ����̨����ʼλ��
void CEquip::printUI(int x,int y)
{
	int _x = x;
	int _y = y;
	map<int, CItem>::iterator iter = m_EquipContainer.begin();
	
	iter = m_EquipContainer.find(IN_Weapon);                   //Ѱ��װ�����е�����
	if (m_EquipContainer.end() != iter)
	{
		switch (iter->second.m_ID)
		{
			case 20000:gotoXY(x++, y); color(10); cout << "A"; color(15); break;
			case 20100:gotoXY(x++, y); color(10); cout << "B"; color(15); break;
			case 30000:gotoXY(x++, y); color(13); cout << "T"; color(15); break;
			default:
				break;
		}
	}
	else
	{
		gotoXY(x++, y); cout << "��";					//û�ҵ����һ���հ׿�
	}

	iter = m_EquipContainer.find(IN_Corselet);					//Ѱ��װ�����еķ���
	if (m_EquipContainer.end() != iter)
	{
		switch (iter->second.m_ID)
		{
			case 20000:gotoXY(x++, y); color(10); cout << "A"; color(15); break;
			case 20100:gotoXY(x++, y); color(10); cout << "B"; color(15); break;
			case 30000:gotoXY(x++, y); color(13); cout << "T"; color(15); break;
			default:
				break;
		}
	}
	else
	{
		gotoXY(x++, y); cout << "��";					//û�ҵ����һ���հ׿�	
	}

	//**********************************************�����
	iter = m_EquipContainer.find(IN_Shoe);					//Ѱ��װ�����е�Ь��
	if (m_EquipContainer.end() != iter)
	{
		switch (iter->second.m_ID)
		{
		case 20000:gotoXY(x++, y); color(10); cout << "A"; color(15); break;
		case 20100:gotoXY(x++, y); color(10); cout << "B"; color(15); break;
		case 30000:gotoXY(x++, y); color(13); cout << "T"; color(15); break;
		default:
			break;
		}
	}
	else
	{
		gotoXY(x++, y); cout << "��";					//û�ҵ����һ���հ׿�	
	}

	iter = m_EquipContainer.find(IN_Shoe);					//Ѱ��װ�����е���Ʒ
	if (m_EquipContainer.end() != iter)
	{
		switch (iter->second.m_ID)
		{
		case 20000:gotoXY(x++, y); color(10); cout << "A"; color(15); break;
		case 20100:gotoXY(x++, y); color(10); cout << "B"; color(15); break;
		case 30000:gotoXY(x++, y); color(13); cout << "T"; color(15); break;
		default:
			break;
		}
	}
	else
	{
		gotoXY(x++, y); cout << "��";					//û�ҵ����һ���հ׿�	
	}
	//****************************************************

	x = _x + 8;
	y = _y;

	iter = m_EquipContainer.begin();
	if (!m_EquipContainer.empty())					//���װ��������    Ĭ�ϴ�ӡװ���������е���Ԫ����Ϣ
	{
		color(14);
		gotoXY(x++, y); cout << iter->second.m_Name;
		gotoXY(x, y); cout << iter->second.m_Describe;
		color(15);
	}
}

//�������̨      ����Ϊ����̨����ʼλ��
void CEquip::cleanEquipUI(int x, int y)
{
	for (int i = x; i < x+11; i++)
	{
		for (int j = y; j < y+9; j++)
		{
			gotoXY(i, j); cout << "  ";
		}
	}
}

//��ӡװ����ϸ��Ϣ      ����Ϊ����̨����ʼλ��
void CEquip::printEquipInfo(int x, int y, const map<int, CItem>::iterator _iter)
{
	color(14);
	gotoXY(x, y); cout << _iter->second.m_Name;
	gotoXY(x + 1, y); cout << _iter->second.m_Describe;
	color(15);
}

//�������̨       ����Ϊ����̨����ʼλ��
void CEquip::cleanEquipInfo(int x, int y)
{
	gotoXY(x++, y); cout << "                                                           ";
	gotoXY(x++, y); cout << "                                                           ";
}