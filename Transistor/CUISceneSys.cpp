#include "CUISceneSys.h"

//��ʼ��
void CUISceneSys::init()
{
	m_pGameMap = nullptr;
	m_MapName = MN_None;

	loadAllMap();
}

//�������е�ͼ
void CUISceneSys::loadAllMap()
{
	CMap *pM = nullptr;

	pM = new CMap;
	pM->setMapFromFile("map\\map1.txt");
	m_MapContainer.insert(make_pair(MN_Map1, pM));

	pM = new CMap;
	pM->setMapFromFile("map\\map2.txt");
	m_MapContainer.insert(make_pair(MN_Map2, pM));

	pM = new CMap;
	pM->setMapFromFile("map\\map3.txt");
	m_MapContainer.insert(make_pair(MN_Map3, pM));

	pM = new CMap;
	pM->setMapFromFile("map\\shop.txt");
	m_MapContainer.insert(make_pair(MN_Shop, pM));

	pM = new CMap;
	pM->setMapFromFile("map\\map4.txt");
	m_MapContainer.insert(make_pair(MN_Map4, pM));

	pM = new CMap;
	pM->setMapFromFile("map\\map5.txt");
	m_MapContainer.insert(make_pair(MN_Map5, pM));

	pM = new CMap;
	pM->setMapFromFile("map\\Boss.txt");
	m_MapContainer.insert(make_pair(MN_Boss, pM));
}

//��õ�ͼ
CMap* CUISceneSys::getMap(int _MapName)
{
	return m_MapContainer.at(_MapName);
}

//����ҷ����ͼ
void CUISceneSys::changeInMap(int _name, CRole* _player)
{
	CMap* pMap = m_MapContainer.at(_name);
	_player->setInMapName(_name);		
	pMap->setPlayer(_player);

	//�жϵ�ͼ�Ƿ�������ù���
	if (_name != MN_Map1 && _name != MN_Shop && _name != MN_Boss && _name != MN_None && _name != MN_Map2)
		setMonster(*pMap);
	
	pMap->ctrlOfMap();
}

//����ͼɢ�����
void CUISceneSys::setMonster(CMap &_map)
{
	//ȥ����ͼ�е����й�    ������������
	for (int i = 0; i < _map.getRow(); i++)
	{
		for (int j = 0; j < _map.getCol(); j++)
		{
			if (MT_Process == _map.m_pMap[i][j] || MT_Camerata == _map.m_pMap[i][j])
			{
				_map.m_pMap[i][j] = Road;
			}
		}
	}

	int monster_N = rand() % 4 + 9;		//��ͨ�ֵ�����
	int monster_P = rand() % 3 + 2;		//��Ӣ�ֵ�����

	int i, j;//�ֵ�����

	while (0 != monster_N)     //������ͨ��
	{
		i = rand() % 30;
		j = rand() % 30;

		if (Road == _map.m_pMap[i][j])
		{
			_map.m_pMap[i][j] = MT_Process;
			monster_N--;
		}
	}

	while (0 != monster_P)
	{
		i = rand() % 30;
		j = rand() % 30;

		if (Road == _map.m_pMap[i][j])
		{
			_map.m_pMap[i][j] = MT_Camerata;
			monster_P--;
		}
	}
}

//�ͷ����е�ͼ
void CUISceneSys::freeAllMap()
{
	map<int, CMap*>::iterator iter = m_MapContainer.begin();

	while (iter != m_MapContainer.end())
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
			iter->second = nullptr;
		}
		iter++;
	}
}