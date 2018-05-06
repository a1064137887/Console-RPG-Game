#include "CRole.h"
#include "CMonster.h"
#include "CBagSys.h"

CRole::CRole()
{
	m_Bag.setBagSize(m_BagSize);

	m_PlayerPictureX = 14;
	m_PlayerPictureY = 53;

	m_RinfoPut_X = 10;
	m_RinfoPut_Y = 61;

	m_Level = 1;

	m_Experience = 0;
	m_UpExperience = 300;

	m_InMapName = MN_None;
}

//�ƶ�
void CRole::move(int dx, int dy)
{
	int _NewX = m_PositionX + dx;
	int _NewY = m_PositionY + dy;

	m_PositionX = _NewX;
	m_PositionY = _NewY;
}

//���ý�ɫ����
void CRole::setPosition(int _x, int _y)
{
	m_PositionX = _x;
	m_PositionY = _y;
}

//��ӡ��ɫ
void CRole::print()
{
	color(14);
	gotoXY(m_PositionX, m_PositionY); cout << "��";
	color(15);
}

//�����������
void CRole::getPosition(int &_x,int &_y)
{
	_x = m_PositionX;
	_y = m_PositionY;
}

//��XML�ļ��ж�ȡ�����ʼ��Ϣ
void CRole::setPlayerInfoFromXML(const char *_FileName)
{
	TiXmlDocument doc;
	if (doc.LoadFile(_FileName))
	{
		//�����ɫ��Ϣ
		TiXmlElement *pRole = doc.FirstChildElement("Role");
		m_Name = pRole->Attribute("Name");
		pRole->Attribute("HP", &m_HP);
		pRole->Attribute("MP", &m_MP);
		pRole->Attribute("MaxHP", &m_MaxHP);
		pRole->Attribute("MaxMP", &m_MaxMP);
		pRole->Attribute("Atk", &m_Atk);
		pRole->Attribute("Def", &m_Def);
		pRole->Attribute("BagSize", &m_BagSize);
		pRole->Attribute("Golden", &m_Golden);
		pRole->Attribute("MapName", &m_InMapName);
		pRole->Attribute("Experience", &m_Experience);
		pRole->Attribute("UpExperience", &m_UpExperience);
		pRole->Attribute("PositionX", &m_PositionX);
		pRole->Attribute("PositionY", &m_PositionY);

		m_Bag.setBagSize(m_BagSize);
		//��ȡ������Ϣ
		TiXmlElement *pItem = pRole->FirstChildElement("Item");
		while (pItem != nullptr)
		{
			CItem item;
			item.m_Name = pItem->Attribute("Name");
			item.m_Describe = pItem->GetText();
			pItem->Attribute("HP", &item.m_HP);
			pItem->Attribute("MP", &item.m_MP);
			pItem->Attribute("Atk", &item.m_Atk);
			pItem->Attribute("Def", &item.m_Def);
			pItem->Attribute("Overly", &item.m_Overly);
			pItem->Attribute("Price", &item.m_Price);
			pItem->Attribute("ID", &item.m_ID);
			pItem->Attribute("Type", &item.m_Type);
			//��Itemװ�뱳��
			m_Bag.addItem(item);
			//ƫ����һ����ǩ
			pItem = pItem->NextSiblingElement("Item");
		}


		//��ȡװ����Ϣ
		TiXmlElement *pEquip = pRole->FirstChildElement("Equip");
		while (pEquip != nullptr)
		{
			CItem item;
			item.m_Name = pEquip->Attribute("Name");
			item.m_Describe = pEquip->GetText();
			pEquip->Attribute("HP", &item.m_HP);
			pEquip->Attribute("MP", &item.m_MP);
			pEquip->Attribute("Atk", &item.m_Atk);
			pEquip->Attribute("Def", &item.m_Def);
			pEquip->Attribute("Overly", &item.m_Overly);
			pEquip->Attribute("Price", &item.m_Price);
			pEquip->Attribute("ID", &item.m_ID);
			pEquip->Attribute("Type", &item.m_Type);
			//��itemװ��װ����
			m_Equip.m_EquipContainer.insert(make_pair(item.m_Type, item));
			//ƫ����һ����ǩ
			pEquip = pEquip->NextSiblingElement("Equip");
		}
	}
}


//�鿴����
void CRole::outputBag(int _x,int _y)
{
	m_Bag.printBag(_x, _y);
}

//�鿴װ����
void CRole::outputEquip(int _x, int _y)
{
	m_Equip.printUI(_x, _y);
}

//���ƣ��ڱ����У�  ����Ϊ����ʼλ��
void CRole::ctrlOfBag(int x, int y)
{
	int _x = x + 8;
	int _y = y;

	vector<CItem>::iterator iter = m_Bag.m_BagContainer.begin();

	char key = 0;

	while (true)
	{
		if (m_Bag.m_BagContainer.empty())
		{
			if (_getch())
			{
				m_Bag.cleanBagInfo(x, y);
				return;
			}
		}
		key = _getch();
		switch (key)
		{
		case 'd':
		case 'D':
		{
			iter++;
			if (m_Bag.m_BagContainer.end() == iter)
			{
				iter--;                           //��������λ�������  CRASH    !!!!!!!
				break;
			}
			m_Bag.cleanItemInfo(_x, _y);
			m_Bag.printItemInfo(_x, _y, iter);
		}break;

		case 'a':
		case 'A':
		{
			if (m_Bag.m_BagContainer.begin() == iter)
				break;
			iter--;
			m_Bag.cleanItemInfo(_x, _y);
			m_Bag.printItemInfo(_x, _y, iter);
		}break;

		//=============================ʹ����Ʒ
		case ' ':
		{
			//--------------------------------------------------ʹ������Ʒ
			if (1 == iter->m_Overly && 1 < iter->m_Num)     //��Ʒ���Ե��Ӳ�����Ʒ����Ŀ��Ϊ1��ʱ��    
			{
				*this + *iter;

				maxInfoProtect();												//�������ֵ����

				iter->m_Num--;												  //��Ʒ������ֱ��-1
				gotoXY(_x + 4, _y); cout << "ʹ�óɹ�";
				if (_getch())
				{
					m_Bag.cleanItemInfo(_x, _y);
					gotoXY(_x + 4, _y); cout << "                    ";
					m_Bag.printItemInfo(_x, _y, iter);
				}
				break;
			}
			else if (1 == iter->m_Overly && 1 == iter->m_Num)
			{
				*this + *iter;
				m_Bag.m_BagContainer.erase(iter);
				m_Bag.m_Size--;
				iter = m_Bag.m_BagContainer.begin();                          //��������λ
				gotoXY(_x + 4, _y); cout << "ʹ�óɹ�";
				if (_getch())
				{
					gotoXY(_x + 4, _y); cout << "                    ";
					m_Bag.printBag(x, y);														//���´�ӡ��������
				}
				break;
			}
			//------------------------------------------------------------

			//--------------------------------------------------ʹ��װ��
			if (m_Equip.m_EquipContainer.find(iter->m_Type) != m_Equip.m_EquipContainer.end())  //�ҵ�ͬ��װ��
				break;																															//ֱ������

			m_Equip.m_EquipContainer.insert(make_pair(iter->m_Type, *iter));         //��װ������װ����
			*this + *iter;

			m_Bag.m_BagContainer.erase(iter);				//����Ʒ���е�װ��erase
			m_Bag.m_Size--;												//��Ʒ����Ʒ��������
			iter = m_Bag.m_BagContainer.begin();                          //��������λ
			gotoXY(_x + 4, _y); cout << "ʹ�óɹ�";
			if (_getch())
			{
				gotoXY(_x + 4, _y); cout << "                    ";
				m_Bag.printBag(x, y);														//���´�ӡ��������
			}
			//------------------------------------------------------------

		}break;//===============================

		case 27:
		case 'b':                            //�رձ���
		case 'B':m_Bag.cleanBagInfo(x, y); return;
		}
	}
}

//���ƣ��ڱ�����		ս��״̬��      ����Ϊ����ʼλ��
void CRole::ctrlOfBagInFight(int x, int y)
{
	int _x = x + 8;
	int _y = y;

	vector<CItem>::iterator iter = m_Bag.m_BagContainer.begin();

	char key = 0;

	while (true)
	{
		if (m_Bag.m_BagContainer.empty())
		{
			if (_getch())
			{
				m_Bag.cleanBagInfo(x, y);
				return;
			}
		}
		key = _getch();
		switch (key)
		{
		case 'd':
		case 'D':
		{
			iter++;
			if (m_Bag.m_BagContainer.end() == iter)
			{
				iter--;                           //��������λ�������  CRASH    !!!!!!!
				break;
			}
			m_Bag.cleanItemInfo(_x, _y);
			m_Bag.printItemInfo(_x, _y, iter);
		}break;

		case 'a':
		case 'A':
		{
			if (m_Bag.m_BagContainer.begin() == iter)
				break;
			iter--;
			m_Bag.cleanItemInfo(_x, _y);
			m_Bag.printItemInfo(_x, _y, iter);
		}break;

		//=============================ʹ����Ʒ
		case ' ':
		{
			//--------------------------------------------------ʹ������Ʒ
			if (1 == iter->m_Overly && 1 < iter->m_Num)     //��Ʒ���Ե��Ӳ�����Ʒ����Ŀ��Ϊ1��ʱ��    
			{
				*this + *iter;

				maxInfoProtect();												//�������ֵ����

				iter->m_Num--;												  //��Ʒ������ֱ��-1
				gotoXY(_x + 4, _y); cout << "��  ҩ";
				if (_getch())
				{
					m_Bag.cleanItemInfo(_x, _y);
					gotoXY(_x + 4, _y); cout << "                    ";
					m_Bag.printItemInfo(_x, _y, iter);
					tubePrint(SP_PlayerTubeX, SP_PlayerTubeY);
				}
				break;
			}
			else if (1 == iter->m_Overly && 1 == iter->m_Num)     //��Ʒ���Ե��Ӳ�����Ʒ����ĿΪ1��ʱ��
			{
				*this + *iter;
				m_Bag.m_BagContainer.erase(iter);
				m_Bag.m_Size--;
				iter = m_Bag.m_BagContainer.begin();                          //��������λ
				gotoXY(_x + 4, _y); cout << "��  ҩ";
				if (_getch())
				{
					gotoXY(_x + 4, _y); cout << "                    ";
					m_Bag.printBag(x, y);														//���´�ӡ��������
					tubePrint(SP_PlayerTubeX, SP_PlayerTubeY);
				}
				break;
			}
			//------------------------------------------------------------

			//--------------------------------------------------ʹ��װ��
			else if(0 == iter->m_Overly)
			{
				gotoXY(_x + 4, _y); cout << "ר�Ĵ��";
				if (_getch())
				{
					gotoXY(_x + 4, _y); cout << "                  ";
					m_Bag.printBag(x, y);
				}
				break;
			}
			//------------------------------------------------------------

		}break;//===============================

		case 27:
		case 'b':                            //�رձ���
		case 'B':m_Bag.cleanBagInfo(x, y); return;
		}
	}
}

//���ƣ���װ�����У�  ����Ϊ����ʼλ��
void CRole::ctrlOfEquip(int x, int y)
{
	{
		int _x = x + 8;
		int _y = y;
		map<int, CItem>::iterator iter = m_Equip.m_EquipContainer.begin();
		char key = 0;

		while (true)
		{
			if (m_Equip.m_EquipContainer.empty())
			{
				if (_getch())
				{
					m_Equip.cleanEquipUI(x, y);
					return;
				}
			}

			key = _getch();

			switch (key)
			{
				case 's':
				case 'S':
				{
					iter++;
					if (iter == m_Equip.m_EquipContainer.end())
					{
						iter--;                                      //���������ͻأ�����Խ�磡������
						break;
					}
					m_Equip.cleanEquipInfo(_x, _y);
					m_Equip.printEquipInfo(_x, _y, iter);

				}break;

				case 'w':
				case 'W':
				{
					if (iter == m_Equip.m_EquipContainer.begin())
						break;
					iter--;
					m_Equip.cleanEquipInfo(_x, _y);
					m_Equip.printEquipInfo(_x, _y, iter);
				}break;

				case 'p':
				case 'P':m_Equip.cleanEquipUI(x, y); return;

				//==========================��װ��
				case ' ':
				{
					m_Bag.addItem(iter->second);       //�����������һ��װ��
					*this - iter->second;						//����ֵ����

					m_Equip.m_EquipContainer.erase(iter);       //װ����װ�����

					iter = m_Equip.m_EquipContainer.begin();      //��������λ

					m_Equip.cleanEquipUI(x, y);
					m_Equip.printUI(x, y);

				}break;
				//==============================
			}
		}
	}
}

//�������ֵ����
void CRole::maxInfoProtect()
{
	if (m_MaxHP < m_HP)
		m_HP = m_MaxHP;

	if (m_MaxMP < m_MP)
		m_MP = m_MaxMP;
}

//������Ϊ      ����Ϊ�����Ĺ���     ����ֵΪ�˺���ֵ
int CRole::atkAction(CMonster &_monster)
{
	int hurt = m_Atk - _monster.getDef();

	if (hurt < 0)				//�ж��˺��Ƿ�δ������ǿ���Ƽ�
		hurt = 1;

	_monster.beenAtkAction(hurt);

	return hurt;
}

//������    ����Ϊ�˺�ֵ
void CRole::beenAtkAction(int _hurt)
{
	m_HP -= _hurt;
}

//��ӡ����Ѫ�����������ڿ���̨��λ�ã�
void CRole::tubePrint(int _x, int _y)
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
		default:
			break;
		}
	}
	color(15); cout << "  " << m_MP << "      ";

}

//��ֹվ������ͼƬ(����:ͼƬ���Ͻǿ���̨����)
void CRole::printStaticPicture(int _PositionX, int _PositionY)
{
	int PlayerStatic[14][16] = {
		0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 5, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0,    //1ǳ��ɫ   2��ɫ  3��ɫ  4��ɫ
		0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5,    //5���ɫ   6����ɫ   7���ɫ
		0, 0, 0, 0, 2, 2, 3, 2, 3, 2, 2, 2, 1, 1, 1, 5,    //0��ɫ
		0, 0, 0, 0, 2, 2, 3, 2, 3, 2, 2, 2, 1, 1, 1, 5,
		0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 5,
		0, 0, 0, 4, 7, 0, 1, 1, 1, 1, 1, 2, 2, 6, 0, 0,
		0, 0, 4, 4, 7, 1, 1, 1, 1, 1, 1, 2, 2, 1, 5, 0,
		0, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4, 4, 7,
		0, 0, 4, 4, 7, 1, 1, 1, 2, 2, 2, 1, 1, 5, 0, 0,
		0, 0, 0, 4, 7, 0, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 5, 0, 0, 1, 1, 5, 0,
		0, 0, 0, 0, 0, 1, 1, 1, 1, 5, 1, 1, 1, 1, 5, 0
	};

	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			gotoXY(_PositionX + i, _PositionY + j);
			switch (PlayerStatic[i][j])
			{
			case 0:cout << "  "; break;
			case 1:color(7); cout << "��"; break;
			case 2:color(9); cout << "��"; break;
			case 3:color(0); cout << "��"; break;
			case 4:color(12); cout << "��"; break;
			case 5:color(8); cout << "��"; break;
			case 6:color(1); cout << "��"; break;
			case 7:color(4); cout << "��"; break; color(15);
			}
		}
		cout << endl;
	}

}

//ƽa����ͼƬ     ����Ϊ����̨����ʼλ��
void CRole::printAttackPicture(int _x, int _y)
{
	int PlayerFight[14][16] = {
		0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 5, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0,    //1ǳ��ɫ   2��ɫ  3��ɫ  4��ɫ
		0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5,    //5���ɫ   6����ɫ   7���ɫ
		0, 0, 0, 0, 2, 2, 3, 2, 3, 2, 2, 2, 1, 1, 1, 5,    //0��ɫ
		0, 0, 0, 0, 2, 2, 3, 2, 3, 2, 2, 2, 1, 1, 1, 5,
		0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 5,
		0, 0, 4, 7, 0, 0, 1, 1, 1, 1, 1, 2, 2, 6, 0, 0,
		0, 4, 4, 7, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 5, 0,
		4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4, 4, 7, 0,
		0, 4, 4, 7, 0, 1, 1, 2, 2, 2, 1, 1, 1, 5, 0, 0,
		0, 0, 4, 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 5, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 5, 0, 0, 1, 1, 5, 0,
		0, 0, 0, 0, 0, 1, 1, 1, 1, 5, 1, 1, 1, 1, 5, 0
	};

	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			gotoXY(_x + i, _y + j);
			switch (PlayerFight[i][j])
			{
			case 0:cout << "  "; break;
			case 1:color(7); cout << "��"; break;
			case 2:color(9); cout << "��"; break;
			case 3:color(0); cout << "��"; break;
			case 4:color(12); cout << "��"; break;
			case 5:color(8); cout << "��"; break;
			case 6:color(1); cout << "��"; break;
			case 7:color(4); cout << "��"; break; color(15);
			}
		}
		cout << endl;
	}

}

//�������ͼƬ(����:ͼƬ���Ͻǿ���̨����)
void CRole::cleanPixelPicture(int _x, int _y)
{
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			gotoXY(_x + i, _y + j);
			cout << "  ";
		}
		cout << endl;
	}
}

//����
void CRole::upLevel()
{
	if (m_Experience < m_UpExperience)				//����ݹ��˳�����
		return;

	m_Experience -= m_UpExperience;				//���ȼ�ȥ�������辭��
	m_Level++;													//�ȼ�����
	upInfo();														//������������
	m_UpExperience = m_UpExperience + 125 * m_Level;		//�����������辭�飬ԭ���ݼ���125������ȼ�

	upLevel();			//�ݹ飬������������
}

//���ݵȼ���������
void CRole::upInfo()
{
	if (1 == m_Level)			//1��ʱ�˳�
		return;

	m_MaxHP = m_MaxHP + 200 * m_Level;
	m_MaxMP = m_MaxMP + 90 * m_Level;
	m_Atk = m_Atk + 15 * m_Level;
	m_Def = m_Def + 5 * m_Level;
}

//����+�����  ���Ӿ���ͽ�Ǯ
CRole& operator+(CRole &_role, CMonster &_monster)
{
	_role.m_Experience += _monster.getExperienceNum();
	_role.m_Golden += _monster.getGolden();

	return _role;
}

//����1
int CRole::skill1(CMonster &_monster)
{
	int hurt = m_Atk*3 - _monster.getDef();
	m_MP -= 150;

	if (hurt < 0)				//�ж��˺��Ƿ�δ������ǿ���Ƽ�
		hurt = 1;

	_monster.beenAtkAction(hurt);

	return hurt;
}

//��ӡ����1��ͼƬ     ����Ϊ����̨����ʼλ��
void CRole::printSkill1Picture(int x, int y)
{
	int Skill1Arr[9][10] = {
		0, 0, 1, 1, 1, 1, 2, 2, 0, 0,//0��ɫ   1��ɫ   2��ɫ
		0, 2, 2, 1, 1, 1, 2, 2, 2, 0,
		2, 2, 2, 1, 1, 1, 1, 2, 2, 1,
		1, 1, 1, 1, 2, 2, 1, 1, 1, 1,
		2, 1, 1, 1, 2, 2, 1, 1, 1, 1,
		2, 1, 1, 1, 1, 1, 1, 2, 2, 1,
		2, 1, 3, 4, 3, 3, 4, 3, 2, 1,//3�ǰ�ɫ    4�Ǻ�ɫ
		0, 0, 3, 4, 3, 3, 4, 3, 0, 0,
		0, 0, 3, 3, 3, 3, 3, 3, 0, 0
	};

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gotoXY(x + i, y + j);
			switch (Skill1Arr[i][j])
			{
			case 0:color(0); cout << "  "; break;
			case 1:color(14); cout << "��"; break;
			case 2:color(12); cout << "��"; break;
			case 3:color(15); cout << "��"; break;
			case 4:color(0); cout << "��"; break;
			}
		}
		cout << endl; color(15);
	}
}

//�������ͼƬ     ����Ϊ����̨����ʼλ��
void CRole::cleanSkill1Picture(int x, int y)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gotoXY(x + i, y + j);
			cout << "  ";
		}
	}
}