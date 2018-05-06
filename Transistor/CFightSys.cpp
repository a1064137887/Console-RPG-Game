#include "CFightSys.h"
#include "comment.h"
#include "CMonster.h"
#include "CRole.h"
#include "CProcess.h"
#include "CCamerata.h"
#include "CBoss.h"
#include <mmstream.h>
#pragma comment(lib,"winmm.lib")

//��ӡս������
void CFightSys::printFightUI()
{
	system("cls");
	int x = 2, y = 2;
	color(12);
	gotoXY(x++, y); cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[";
	gotoXY(x++, y); cout << "�U                                                          �U";
	gotoXY(x++, y); cout << "�U                                                          �U";
	gotoXY(x++, y); cout << "�U                                                          �U";
	gotoXY(x++, y); cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a";
	color(15);

	x = 3, y = 3;
	gotoXY(x++, y); cout << "";
	gotoXY(x++, y); cout << "HP:";
	gotoXY(x++, y); cout << "MP:";

	x = 2, y = 47;
	color(11);
	gotoXY(x++, y); cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[";
	gotoXY(x++, y); cout << "�U                                                          �U";
	gotoXY(x++, y); cout << "�U                                                          �U";
	gotoXY(x++, y); cout << "�U                                                          �U";
	gotoXY(x++, y); cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a";
	color(15);

	x = 3, y = 48;
	gotoXY(x++, y); cout << "";
	gotoXY(x++, y); cout << "HP:";
	gotoXY(x++, y); cout << "MP:";

	x = 2, y = 35;
	color(8);
	gotoXY(x++, y); cout << "��������������������";
	gotoXY(x++, y); cout << "��  ��  ����      ��";
	gotoXY(x++, y); cout << "�ǩ�����������������";
	gotoXY(x++, y); cout << "��      ����      ��";
	gotoXY(x++, y); cout << "�ǩ�����������������";
	gotoXY(x++, y); cout << "��      ����      ��";
	gotoXY(x++, y); cout << "�ǩ�����������������";
	gotoXY(x++, y); cout << "��      ����      ��";
	gotoXY(x++, y); cout << "��������������������";
	color(15);

}

//���ƣ���ս���У�      ����Ϊ��������ö��
bool CFightSys::ctrlOfFight(MonsterType _MonsterType)
{
	if (0 == m_Player->getHP())
		return false;

	printFightUI();

	CMonster *pMonster = nullptr;	//����һ���������ָ���������������������Ķ�ս
	switch (_MonsterType)					//���ݹ���������������
	{
		case MT_Process:pMonster = new CProcess; break;
		case MT_Camerata:pMonster = new CCamerata; break;
		case MT_Boss:pMonster = new CBoss;break;
		default:
			break;
	}

	upMonsterInfo(pMonster);

	gotoXY(SP_RnamePrintX, SP_RnamePrintY); color(14); cout << m_Player->getName(); color(15);
	m_Player->tubePrint(SP_PlayerTubeX, SP_PlayerTubeY);
	gotoXY(SP_MnamePrintX, SP_MnamePrintY); color(14); cout << pMonster->getName(); color(15);
	pMonster->tubePrint(SP_MonsterTubeX, SP_MonsterTubeY);
	pMonster->printStaticPicture(pMonster->m_MonsterPictureX, pMonster->m_MonsterPictureY);
	m_Player->printStaticPicture(m_Player->m_PlayerPictureX, m_Player->m_PlayerPictureY);

	int cursor = 3;
	char key = 0;
	//=======================ս���е�ѡ��
	while (true)
	{
		key = _getch();

		switch (key)
		{
			case 's':
			case 'S':
			{
				gotoXY(cursor, 37); cout << "  ";
				cursor += 2;
				if (9 < cursor)
					cursor = 3;
				color(8); gotoXY(cursor, 37); cout << "��"; color(15);
			}break;

			case 'w':
			case 'W':
			{
				gotoXY(cursor, 37); cout << "  ";
				cursor -= 2;
				if (3 > cursor)
					cursor = 9;
				color(8); gotoXY(cursor, 37); cout << "��"; color(15);
			}break;

			//--------------------------------------ս������
			case ' ':
			{
				switch (cursor)
				{
					case FC_Atack://ѡ�񹥻�
					{
						PaMvideo(pMonster);
						gotoXY(pMonster->m_MinfoPut_X, pMonster->m_MinfoPut_Y);
						color(12); cout << "-" << m_Player->atkAction(*pMonster); color(15);        //��ҹ���������ֵ����
						_sleep(300);
						gotoXY(pMonster->m_MinfoPut_X, pMonster->m_MinfoPut_Y);
						cout << "            ";

						pMonster->tubePrint(SP_MonsterTubeX, SP_MonsterTubeY);		//����Ѫ����ӡ

						if (isMonsterDead(pMonster))		//��������
						{
							color(12);
							gotoXY(pMonster->m_MinfoPut_X, pMonster->m_MinfoPut_Y);
							cout << "��  ��";
							color(15);

							*m_Player + *pMonster;				//���Ӿ���
							m_Player->upLevel();					//�ж��Ƿ�����

							if (nullptr != pMonster)
								delete pMonster;							//�ͷ��ڴ�
							_getch();
							return true;							//���ʤ������true
						}

						_sleep(500);							//****************************�����ķָ���

						MaPvideo(pMonster, _MonsterType);
						gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
						color(12); cout << "-" << pMonster->atkAction(*m_Player); color(15);		 //���﹥�������ֵ����
						_sleep(300);
						gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
						cout << "            ";

						m_Player->tubePrint(SP_PlayerTubeX, SP_PlayerTubeY);		//���Ѫ����ӡ

						if (isPlayerDead())			//�������
						{
							color(12);
							gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
							cout << "��  ��";
							color(15);
							if (nullptr != pMonster)
								delete pMonster;							//�ͷ��ڴ�
							_getch();
							return false;						//��ʤ������false
						}

					}break;

					case FC_Skill://ѡ����
					{
						int x = pMonster->m_MonsterPictureX - 3;
						int y = pMonster->m_MonsterPictureY;
						gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y - 1);
						color(14); cout << "�� �� �� ��"; color(15);
						PlaySound(TEXT("audio\\�콵����.wav"), NULL, SND_ASYNC);
						_sleep(500);
						gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y - 2);
						cout << "                    ";

						//���ܶ���
						m_Player->printSkill1Picture(x, y);
						_sleep(300);
						m_Player->cleanSkill1Picture(x, y);
						_sleep(300);
						m_Player->printSkill1Picture(x + 4, y);
						_sleep(300);
						m_Player->cleanSkill1Picture(x + 4, y);
						_sleep(300);
						m_Player->printSkill1Picture(x + 8, y);
						_sleep(300);
						m_Player->cleanSkill1Picture(x + 8, y);
						pMonster->printStaticPicture(pMonster->m_MonsterPictureX, pMonster->m_MonsterPictureY);		//����ͼƬ��ԭ

						gotoXY(pMonster->m_MinfoPut_X, pMonster->m_MinfoPut_Y); 
						color(12); cout << m_Player->skill1(*pMonster); color(15);
						_sleep(300);
						gotoXY(pMonster->m_MinfoPut_X, pMonster->m_MinfoPut_Y);
						cout << "            ";
						
						pMonster->tubePrint(SP_MonsterTubeX, SP_MonsterTubeY);		//����Ѫ����ӡ

						if (isMonsterDead(pMonster))		//��������
						{
							color(12);
							gotoXY(pMonster->m_MinfoPut_X, pMonster->m_MinfoPut_Y);
							cout << "��  ��";
							color(15);

							*m_Player + *pMonster;				//���Ӿ���
							m_Player->upLevel();					//�ж��Ƿ�����

							if (nullptr != pMonster)
								delete pMonster;							//�ͷ��ڴ�
							_getch();
							return true;							//���ʤ������true
						}

						_sleep(500);							//****************************�����ķָ���

						MaPvideo(pMonster, _MonsterType);
						gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
						color(12); cout << "-" << pMonster->atkAction(*m_Player); color(15);		 //���﹥�������ֵ����
						_sleep(300);
						gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
						cout << "            ";

						m_Player->tubePrint(SP_PlayerTubeX, SP_PlayerTubeY);		//���Ѫ����ӡ

						if (isPlayerDead())			//�������
						{
							color(12);
							gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
							cout << "��  ��";
							color(15);
							if (nullptr != pMonster)
								delete pMonster;							//�ͷ��ڴ�
							_getch();
							return false;						//��ʤ������false
						}
					}break;

					case FC_Item://ѡ�񱳰�
					{
						m_Player->m_Bag.printBag(SP_FightBagPrintX, SP_FightBagPrintY);
						m_Player->ctrlOfBagInFight(SP_FightBagPrintX, SP_FightBagPrintY);
					}break;

					case FC_Run://ѡ������
					{
						int r = rand() % 100;
						if (60 >	r)						//60%��������
						{
							delete pMonster;							//�ͷ��ڴ�
							system("cls");
							return false;
						}

						MaPvideo(pMonster, _MonsterType);
						gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
						color(12); cout << "-" << pMonster->atkAction(*m_Player); color(15);		 //���﹥�������ֵ����
						_sleep(300);
						gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
						cout << "            ";

						m_Player->tubePrint(SP_PlayerTubeX, SP_PlayerTubeY);		//���Ѫ����ӡ

						if (isPlayerDead())			//�������
						{
							color(12);
							gotoXY(m_Player->m_RinfoPut_X, m_Player->m_RinfoPut_Y);
							cout << "��  ��";
							color(15);
							if (nullptr != pMonster)
								delete pMonster;							//�ͷ��ڴ�
							_getch();
							return false;						//��ʤ������false
						}


					}break;
				}

			}break;
			//----------------------------------------------
		}
	}
	//===============================
}

//��������ȼ������ֵ�����
void CFightSys::upMonsterInfo(CMonster *_pMonster)
{
	int _level = m_Player->getLevel();
	if (1 == _level)
		return;

	_pMonster->setAtk(_pMonster->getAtk() + 20 * _level);
	_pMonster->setDef(_pMonster->getDef() + 5 * _level);
	_pMonster->setHP(_pMonster->getHP() + 300 * _level);
	_pMonster->setMP(_pMonster->getMP() + 50 * _level);
}

//�жϹ��Ƿ�����			��������true
bool CFightSys::isMonsterDead(const CMonster *_monster)
{
	if (0 >= _monster->getHP())
		return true;

	return false;
}

//�ж������Ƿ�����        ��������true
bool CFightSys::isPlayerDead()
{
	if (0 >= m_Player->getHP())
		return true;

	return false;
}

//��ɫ�����ֶ���
void CFightSys::PaMvideo(CMonster *pMonster)
{
	m_Player->cleanPixelPicture(m_Player->m_PlayerPictureX, m_Player->m_PlayerPictureY);    //�����ͼƬ
	m_Player->printStaticPicture(pMonster->m_PattackM_X, pMonster->m_PattackM_Y);	//������Ų��ȥ
	_sleep(150);
	m_Player->printAttackPicture(pMonster->m_PattackM_X, pMonster->m_PattackM_Y);		//��ӡ����ͼ��
	PlaySound(TEXT("audio\\���.wav"), NULL, SND_ASYNC);
	_sleep(200);
	m_Player->cleanPixelPicture(pMonster->m_PattackM_X, pMonster->m_PattackM_Y);		//���ͼƬ
	_sleep(150);
	m_Player->printStaticPicture(m_Player->m_PlayerPictureX, m_Player->m_PlayerPictureY);		//�����λ
	pMonster->printStaticPicture(pMonster->m_MonsterPictureX, pMonster->m_MonsterPictureY);		//����ͼƬ��ԭ
}

//�ֹ�����ɫ����		����Ϊ����ָ��
void CFightSys::MaPvideo(CMonster *pMonster,MonsterType _MonsterType)
{
	pMonster->cleanPixelPicture(pMonster->m_MonsterPictureX, pMonster->m_MonsterPictureY);		//�����ͼƬ
	pMonster->printStaticPicture(pMonster->m_MattackP_X, pMonster->m_MattackP_Y);		//������Ų��ȥ
	_sleep(150);
	pMonster->printAttackPicture(pMonster->m_MattackP_X, pMonster->m_MattackP_Y);		//��ӡ����ͼ��
	if (MT_Boss == _MonsterType)
		PlaySound(TEXT("audio\\���.wav"), NULL, SND_ASYNC);
	else
		PlaySound(TEXT("audio\\���.wav"), NULL, SND_ASYNC);
	_sleep(200);
	pMonster->cleanPixelPicture(pMonster->m_MattackP_X, pMonster->m_MattackP_Y);		//	���ͼƬ
	_sleep(150);
	pMonster->printStaticPicture(pMonster->m_MonsterPictureX, pMonster->m_MonsterPictureY);		//�����Ϊ
	m_Player->printStaticPicture(m_Player->m_PlayerPictureX, m_Player->m_PlayerPictureY);		//����ͼƬ��ԭ
}