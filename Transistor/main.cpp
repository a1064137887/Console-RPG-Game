/*
TODO : ��ʱ����Լ�������ϵͳ

*/

#include "CUISceneSys.h"
#include "CBagSys.h"
#include <windows.h>
#include <mmsyscom.h>
#pragma comment(lib,"winmm.lib")

void main()
{
	srand(time(NULL));
	HideCursor();//���ع��
	system("mode con cols=160 lines=37");//��������̨����ߴ�

	//����̨���ű�������
	WCHAR mciCmd[] = TEXT("open audio\\WaterWall.mp3 alias BGM");
	mciSendString(mciCmd, 0, 0, 0);
	mciSendString(TEXT("play BGM"), 0, 0, 0);

	CUISceneSys *pUISceneSys = CUISceneSys::getInstance();//��ó�������ϵͳ�ĵ���ָ��
	pUISceneSys->init();//����ϵͳ��ʼ��
	CBagSys::getInstance()->init("init\\Item.xml");//��Ϸ���߳�ʼ��

	int flag = CBeginScene::getInstance()->ctrlOfScene();		//����ֵΪ���ѡ����
	CBeginScene::getInstance()->action(flag);				//�������ѡ��������Ϊ
}