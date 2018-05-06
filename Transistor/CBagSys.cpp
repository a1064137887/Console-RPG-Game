#include "CBagSys.h"
#include "comment.h"

//��Ϸ���е�������
void CBagSys::init(char *_FileName)
{
	TiXmlDocument doc;
	if (false == doc.LoadFile(_FileName))
	{
		return;
	}

	TiXmlElement *pItem = doc.FirstChildElement();

	while (nullptr != pItem)
	{
		CItem item;
		item.m_Name = pItem->Attribute("Name");
		item.m_Describe = pItem->Attribute("Describe");
		pItem->Attribute("HP", &item.m_HP);
		pItem->Attribute("MP", &item.m_MP);
		pItem->Attribute("Atk", &item.m_Atk);
		pItem->Attribute("Def", &item.m_Def);
		pItem->Attribute("Overly", &item.m_Overly);
		pItem->Attribute("Price", &item.m_Price);
		pItem->Attribute("ID", &item.m_ID);
		pItem->Attribute("Type", &item.m_Type);
		pItem->Attribute("Num", &item.m_Num);
		//��Itemװ������
		m_ItemContainer.insert(make_pair(item.m_ID, item));
		//ƫ����һ����ǩ
		pItem = pItem->NextSiblingElement();
	}
}

//չʾ��Ʒ    ����Ϊ����̨����������Ʒ����ö��
void CBagSys::showItem(int x, int y, ItemType _type)
{
	int _x = x;
	int _y = y;

	int count = 0;
	map<int, CItem>::iterator iter = m_ItemContainer.begin();
	map<int, CItem>::iterator iter_end = m_ItemContainer.end();


	for (int i = 0; i < 20; i++)
	{
		if (0 == count % 5 && 0 != count)
		{
			gotoXY(x++, _y);
			y = _y;
		}
		gotoXY(x, y++); color(15); cout << "��"; count++;
	}

	x = _x;
	y = _y;
	count = 0;
	for (; iter != m_ItemContainer.end() && count < 20; iter++)
	{
		if (0 == count % 5 && 0 != count)
		{
			gotoXY(x++, _y);
			y = _y;
		}
		switch (_type)
		{
		case IN_Medicine:
		{
			if (IN_Medicine == iter->second.m_Type)
			{
				switch (iter->second.m_ID)
				{
					case 10000:gotoXY(x, y++); color(12); cout << "ҩ"; count++; break;
					case 15000:gotoXY(x, y++); color(9); cout << "ҩ"; count++; break;
					case 20000:gotoXY(x, y++); color(10); cout << "A"; count++; break;
					case 20100:gotoXY(x, y++); color(10); cout << "B"; count++; break;
					case 30000:gotoXY(x, y++); color(13); cout << "T"; count++; break;
					default:
						break;
				}
			}
		}break;

		case IN_Weapon:
		{
			if (IN_Weapon == iter->second.m_Type)
			{
				switch (iter->second.m_ID)
				{
				case 10000:gotoXY(x, y++); color(12); cout << "ҩ"; count++; break;
				case 15000:gotoXY(x, y++); color(9); cout << "ҩ"; count++; break;
				case 20000:gotoXY(x, y++); color(10); cout << "A"; count++; break;
				case 20100:gotoXY(x, y++); color(10); cout << "B"; count++; break;
				case 30000:gotoXY(x, y++); color(13); cout << "T"; count++; break;
				default:
					break;
				}
			}
		}break;

		case IN_Corselet:
		{
			if (IN_Corselet == iter->second.m_Type)
			{
				switch (iter->second.m_ID)
				{
					case 10000:gotoXY(x, y++); color(12); cout << "ҩ"; count++; break;
					case 15000:gotoXY(x, y++); color(9); cout << "ҩ"; count++; break;
					case 20000:gotoXY(x, y++); color(10); cout << "A"; count++; break;
					case 20100:gotoXY(x, y++); color(10); cout << "B"; count++; break;
					case 30000:gotoXY(x, y++); color(13); cout << "T"; count++; break;
					default:
						break;
				}
			}
		}break;
		}
	}

	ctrlOfShop(_x, _y,_type);
}

//���ƣ����̵���棩
void CBagSys::ctrlOfShop(int x, int y,ItemType _type)
{
	int _x = x + 8;
	int _y = y;
	int index = 0;//��¼��ҹ�������±�
	int maxIndex = m_ItemContainer.size();//��¼��������±�

	map<int, CItem>::iterator iter = m_ItemContainer.begin();
	
	char key = 0;
	//=============��ӡ������Ʒ�ĵ�һ��Item��
	switch (_type)				
	{
		case IN_Medicine:
		{
			while(IN_Medicine != iter->second.m_Type)
			{
				iter++;
			}
			printItemInfo(_x, _y, iter);
		}break;

		case IN_Corselet:
		{
			while (IN_Corselet != iter->second.m_Type)
			{
				iter++;
			}
			printItemInfo(_x, _y, iter);
		}break;

		case IN_Weapon:
		{
			while (IN_Weapon != iter->second.m_Type)
			{
				iter++;
			}
			printItemInfo(_x, _y, iter);
		}break;
	}
	//=============================
	while (true)
	{
		key = _getch();
		switch (key)
		{
			case 'd':
			case 'D':
			{
				iter++;
				if (iter == m_ItemContainer.end())
				{
					iter--;                                      //��������λ�������  CRASH    !!!!!!!
					break;
				}
				if (_type != iter->second.m_Type)
					iter--;
				cleanItemInfo(_x, _y);
				printItemInfo(_x, _y, iter);
			}break;

			case 'a':
			case 'A':
			{
				if (iter == m_ItemContainer.begin())
					break;
				iter--;
				if (_type != iter->second.m_Type)
					iter++;
				cleanItemInfo(_x, _y);
				printItemInfo(_x, _y, iter);
			}break;

			//==========================��װ��
			case ' ':					//���ո���ѡ�е���Ʒ
			{

				if (0 > m_Player->getGolden() - iter->second.m_Price)		//�жϽ�Ǯ�Ƿ��㹻
				{
					color(14); gotoXY(_x + 6, y); cout << "ľǮ�ˣ�"; color(15);
					if (_getch())
						gotoXY(_x + 6, y); cout << "                      ";
					break;
				}

				if (m_Player->m_Bag.m_MaxSize == m_Player->m_Bag.m_Size)   //�жϱ����Ƿ��㹻
				{
					color(14); gotoXY(_x + 6, y); cout << "�ò������ˣ�"; color(15);
					if (_getch())
						gotoXY(_x + 6, y); cout << "                      ";
					break;
				}
					
				m_Player->m_Bag.addItem(iter->second);
				m_Player->setGolden(m_Player->getGolden() - iter->second.m_Price);

				color(14); gotoXY(_x + 6, y); cout << "ŵ�����ţ�"; color(15);
				if (_getch())
					gotoXY(_x + 6, y); cout << "                     ";
			}break;
			//=============================

			case 27:
				cleanShopInfo(x, y); return;
		}
	}
}

//�����Ʒ��ϸ��Ϣ     ����Ϊ����ʼλ�úͱ����±�
void CBagSys::printItemInfo(int x, int y, const map<int, CItem>::iterator _iter)
{
	color(14);
	gotoXY(x, y); cout << _iter->second.m_Name;
	gotoXY(x + 1, y); cout << _iter->second.m_Describe;
	gotoXY(x + 3, y); cout <<"�۸�"<< _iter->second.m_Price;
	gotoXY(x + 4, y); cout << "���ո������";
	color(15);
}

//�������̨��Ʒ��ϸ��Ϣ     ����Ϊ����ʼλ��
void CBagSys::cleanItemInfo(int x, int y)
{
	gotoXY(x++, y); cout << "                                                                  ";
	gotoXY(x, y); cout << "                                                                         ";
}

//�������̨��Ʒ��ϸ��Ϣ      ����Ϊ����ʼλ��
void CBagSys::cleanShopInfo(int x, int y)
{
	for (int i = x; i < 30; i++)
	{
		for (int j = y; j < 50; j++)
		{
			gotoXY(i, j); cout << "  ";
		}
	}
}