#include "CRoleBag.h"

CRoleBag::CRoleBag()
{
	m_Size = 0;
}

//�����Ʒ���뱳��
void CRoleBag::addItem(CItem &_Item)
{
	if (m_MaxSize <= m_Size)
		return;
	int index = searchItem(_Item.m_ID);
	if (-1 != index&&_Item.m_Overly == 1)
	{
		m_BagContainer[index].m_Num++;
		return;
	}
	//��������в�������Ʒ������Ʒ�޷����ӣ����һ�����뱳��
	m_BagContainer.push_back(_Item);
	m_Size++;
}

//�ӱ����в�����Ʒ������ֵΪ�±�
int CRoleBag::searchItem(int _ID)
{
	vector<CItem>::iterator i;
	int index = 0;
	//����������Item
	for (vector<CItem>::iterator i = m_BagContainer.begin(); i != m_BagContainer.end(); i++,index++)
	{
		if (i->m_ID == _ID)
			return index;//�ҵ������±�
	}
	return -1;//δ�ҵ�����-1
}

//�����鿴������Ϊ�������Ͻǿ���̨λ�ã�
void CRoleBag::printBag(int x, int y)
{
	int _x = x;//��һ��������x�ĳ�ʼλ��
	int _y = y;

	int count = 0;
	vector<CItem>::iterator iter = m_BagContainer.begin();

	for (int i = 0; i < m_MaxSize; i++)
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
	for (; iter != m_BagContainer.end() && count <= m_MaxSize; iter++)
	{
		if (0 == count % 5 && 0 != count)
		{
			gotoXY(x++, _y);
			y = _y;
		}
		switch (iter->m_ID)
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
	
	x = _x + 8;
	y = _y;

	iter = m_BagContainer. begin();
	if (m_BagContainer.empty())      //����������ǿ�   Ĭ�ϴ�ӡ��һ��Item����Ϣ
	{
		cleanItemInfo(x, y);
		return;
	}
	else
	{
		cleanBagInfo(x, y);
		printItemInfo(x, y, iter);
	}

}

//���ñ�����С
void CRoleBag::setBagSize(int _size)
{
	m_MaxSize = _size;
}

//�������̨������Ϣ
void CRoleBag::cleanBagInfo(int x, int y)
{
	for (int i = x; i < x + 11; i++)
	{
		for (int j = y; j < y + 9; j++)
		{
			gotoXY(i, j); cout << "  ";
		}
	}
}

//�����Ʒ��ϸ��Ϣ     ����Ϊ����ʼλ�ú͵�����
void CRoleBag::printItemInfo(int x, int y, const vector<CItem>::iterator _iter)
{
	color(14);
	gotoXY(x, y); cout << _iter->m_Name << "  ��" << _iter->m_Num;
	gotoXY(x + 1, y); cout << _iter->m_Describe;
	color(15);
}

//�������̨��Ʒ��ϸ��Ϣ     ����Ϊ����ʼλ��
void CRoleBag::cleanItemInfo(int x, int y)
{
	gotoXY(x++, y); cout << "                     ";
	gotoXY(x, y); cout << "                          ";
}