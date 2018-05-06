#include "CItem.h"
#include "CRole.h"

CItem::CItem()
{
	m_Name = "";
	m_ID = 0;
	m_Describe = "";

	m_HP = 0;
	m_MP = 0;

	m_Atk = 0;
	m_Def = 0;

	m_Num = 1;
	m_Overly = -1;
	m_Price = 0;
	m_Type = IN_None;
}

//���� + �����������ֵ����
CRole& operator+(CRole &_role, CItem &_item)
{
	_role.setAtk(_role.getAtk() + _item.m_Atk);
	_role.setHP(_role.getHP() + _item.m_HP);
	_role.setMP(_role.getMP() + _item.m_MP);
	_role.setDef(_role.getDef() + _item.m_Def);

	return _role;
}

//���� - �����������ֵ����
CRole& operator-(CRole &_role, CItem &_item)
{
	_role.setAtk(_role.getAtk() - _item.m_Atk);
	_role.setHP(_role.getHP() - _item.m_HP);
	_role.setMP(_role.getMP() - _item.m_MP);

	_role.setDef(_role.getDef() - _item.m_Def);

	return _role;
}