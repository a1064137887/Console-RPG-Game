//#include "CItemFactory.h"
//
//
//CItem * CItemFactory::create(ItemName _ID)
//{
//	CItem* pItemTemp = nullptr;
//
//	switch (_ID)
//	{
//		case IN_Blood:
//		{
//			pItemTemp = new CItem;
//			//pItemTemp->m_ID = _ID;
//			pItemTemp->m_Name = "��ҩ";
//			pItemTemp->m_Describe = "�ָ�����ֵ 500 ��";
//			pItemTemp->m_HP = 500;
//		}break;
//
//		case IN_Blue:
//		{
//			pItemTemp = new CItem;
//			//pItemTemp->m_ID = _ID;
//			pItemTemp->m_Name = "��ҩ";
//			pItemTemp->m_Describe = "�ָ�����ֵ 500 ��";
//			pItemTemp->m_MP = 300;
//		}break;
//	}
//
//	return pItemTemp;
//}