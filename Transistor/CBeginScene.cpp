#include "CBeginScene.h"
#include "comment.h"
#include "Game.h"
#include "CRole.h"
#include "CUISceneSys.h"
#include "BackGround.h"

//��ӡ����
void CBeginScene::print()
{
	int x = 5, y = 3;
	color(11);
	gotoXY(x++, y); cout << "    .7vj0PLkBkuFLjuv:                                                              :5MB:                     ;i.                                   " << endl; _sleep(75);
	gotoXY(x++, y); cout << "    FB@B@BM2GOGM@B@B@B.                                                            Y5B@X                    .u@B                                   " << endl; _sleep(75);
	gotoXY(x++, y); cout << "     rri. .iU@:   .,7v                                                              vXY                     :7B@ .                                 " << endl; _sleep(75);
	gotoXY(x++, y); cout << "           iFB.              ::      ...,         ,     ,i,             ...                     ...         ii0P8B@v       .:,               .i.   " << endl; _sleep(75);
	gotoXY(x++, y); cout << "           75@:       r0  7k8@B@  .LU8B@B@O.     j@@  7PM@B@B7      :50@@@@@Ou      :r.     .uP@B@B@MS,  :0MEYSGOON,    :JG@@@BMr     .uF ,YPOB@B  " << endl; _sleep(75);
	gotoXY(x++, y); cout << "          .rkB:      2XB8ikB@kkG  uX@BEiiJZB@:   ik@,:jB@rvu@B.    JGMkr:,i70B@     2M@i   rEOZvi,:rSB@.  7Ekr@2      iuZB@kv508@Bk  .FG@Jr0@MSNE  " << endl; _sleep(75);
	gotoXY(x++, y); cout << "           r2@r      r7@LjBG    ,2Y@B     :UBv   iU@Y:B@   ;7@B   iEB@       ;     :rPBv  .X@@:      i.     .vBr     rvOBF     .ij@M  7uBrP@Y      " << endl; _sleep(75);
	gotoXY(x++, y); cout << "          .rFBu       vLSBG     7v@B     .iX@.   :j@iu@r    rU@i   vFG@BOE8L       ,rP@:   ;Fq@BMZ8F.       :u@:    7v0Bv        :M@  :7uP@7       " << endl; _sleep(75);
	gotoXY(x++, y); cout << "          .rX@:       riM@.     rJBP    :YuMB    :LOr@X     :7@B     ,LLYXO@O@O:   ;iMB.      7JvFZ@MBBv    i2B:    7LBG        i7@@   7r@B        " << endl; _sleep(75);
	gotoXY(x++, y); cout << "          .rS@i       :;X@r     L5@:   :LNMj@ir. :LSBM      :;BB    :.      i7MBj  77B@     :.      :rqBB   ;2@.    7L@E      ,v1@@.   irM@        " << endl; _sleep(75);
	gotoXY(x++, y); cout << "           72@7        7Y@X     .2BO,.vkB@LrOBO@ ,7qB;      :rM@  .XB@:     7vq@7  v7@B    uB@J     ivU@O   ;5BY.i: .u8@L..iY2SMB@     :rqBi       " << endl; _sleep(75);
	gotoXY(x++, y); cout << "           r5BO        v1@@      .jB@G@BO  vuB@r :JO@:      iu@@   JEM@B@B@BMB@v   v2@@    7qO@B@B@BMB@X    :UEB@B@   iF@B@OBB@Bi       jX@S       " << endl; _sleep(75);
	gotoXY(x++, y); cout << "            ;Er         7P,        rL1L.    vOi   iZM        :Yi     ,i7vuLL7:      75       .:77JYL7i       ,r2ji      :vuuju.         .U5        " << endl; _sleep(75);
	color(15);
	x = 25; y = 32;
	gotoXY(x++, y); cout << "��                              ��";
	gotoXY(x++, y); cout << "            �� ʼ �� Ϸ           ";
	gotoXY(x++, y); cout << "            �� �� �� ��           ";
	gotoXY(x++, y); cout << "            �� Ϸ ˵ ��           ";
	gotoXY(x++, y); cout << "            �� �� �� Ϸ           ";
	gotoXY(x++, y); cout << "��                              ��";
}

//���ƣ��ڳ����У�
int CBeginScene::ctrlOfScene()
{
	system("cls");

	print();
	
	int x = 26, y = 38;
	gotoXY(x, y); color(16 * 15 + 0); cout << "�� ʼ �� Ϸ"; color(15);
	char key = 0;
	while (true)
	{
		key = _getch();
		switch (key)
		{
		case 'w':
		case 'W':
			switch (x)//����������������ж�ѡ��
			{
			case 26:
				gotoXY(x, y); color(15); cout << "�� ʼ �� Ϸ";
				x = 29;
				gotoXY(x, y); color(16 * 15 + 0); cout << "�� �� �� Ϸ"; color(15);
				break;
			case 27:
				gotoXY(x, y); color(15); cout << "�� �� �� ��";
				x = 26;
				gotoXY(x, y); color(16 * 15 + 0); cout << "�� ʼ �� Ϸ"; color(15);
				break;
			case 28:
				gotoXY(x, y); color(15); cout << "�� Ϸ ˵ ��";
				x = 27;
				gotoXY(x, y); color(16 * 15 + 0); cout << "�� �� �� ��"; color(15);
				break;
			case 29:
				gotoXY(x, y); color(15); cout << "�� �� �� Ϸ";
				x = 28;
				gotoXY(x, y); color(16 * 15 + 0); cout << "�� Ϸ ˵ ��"; color(15);
				break;
			}
			break;

		case 's':
		case 'S':
			switch (x)//����������������ж�ѡ��
			{
			case 26:
				gotoXY(x, y); color(15); cout << "�� ʼ �� Ϸ";
				x = 27;
				gotoXY(x, y); color(16 * 15 + 0); cout << "�� �� �� ��"; color(15);
				break;
			case 27:
				gotoXY(x, y); color(15); cout << "�� �� �� ��";
				x = 28;
				gotoXY(x, y); color(16 * 15 + 0); cout << "�� Ϸ ˵ ��"; color(15);
				break;
			case 28:
				gotoXY(x, y); color(15); cout << "�� Ϸ ˵ ��";
				x = 29;
				gotoXY(x, y); color(16 * 15 + 0); cout << "�� �� �� Ϸ"; color(15);
				break;
			case 29:
				gotoXY(x, y); color(15); cout << "�� �� �� Ϸ";
				x = 26;
				gotoXY(x, y); color(16 * 15 + 0); cout << "�� ʼ �� Ϸ"; color(15);
				break;
			}
			break;

		case '\r':
		case ' ':
			switch (x)//����������������ж�ѡ��
			{
				case BeginGame: return BeginGame; break;
				case LoadGame: return LoadGame; break;
				case GameExplain: return GameExplain; break;
				case Exit: return Exit; break;
			}
			break;

		default:break;
		}
	}

}


void CBeginScene::action(int _flag)
{
	switch (_flag)
	{
	case BeginGame:
	{
		printBackGround();
		CRole *pPlayer = new CRole;//�½�һ�����
		pPlayer->setPlayerInfoFromXML("init\\NPC.xml");
		pPlayer->m_Bag.setBagSize(pPlayer->getBagSize());
		pPlayer->setPosition(2, 2);
		CUISceneSys::getInstance()->changeInMap(MN_Map1, pPlayer);//����Ҷ����ͼ
	}break;

	case LoadGame:
	{
		CRole *pPlayer = new CRole;//�½�һ�����
		pPlayer->setPlayerInfoFromXML("save\\Role.xml");
		CUISceneSys::getInstance()->changeInMap(pPlayer->getInMapName(), pPlayer);//����Ҷ����ͼ
	}break;
		
	case GameExplain:
	{
		printGameExplain();
		if (_getch())
		{
			action(ctrlOfScene());
		}
	}break;

	case Exit:
	{
		CUISceneSys::getInstance()->freeAllMap();
		exit(NULL);
	}break;

	default:
		break;

	}

}

//��ӡ��Ϸ��ʾ
void CBeginScene::printGameExplain()
{
	system("cls");

	int x = 15;
	int y = 30;

	color(15);
	gotoXY(x++, y); cout << "��                              ��";
	gotoXY(x++, y); cout << "                                       ";
	gotoXY(x++, y); cout << "			                            ";
	gotoXY(x++, y); cout << "                                       ";
	gotoXY(x++, y); cout << "                                       ";
	gotoXY(x++, y); cout << "��                              ��";

	x = 16;
	y = 34;
	
	color(14);
	gotoXY(x++, y); cout << "w,a,s,d ���Ʒ���";
	gotoXY(x++, y); cout << "b       �򿪱���";
	gotoXY(x++, y); cout << "p       �鿴װ��";
	gotoXY(x++, y); cout << "i	    �鿴��ɫ��Ϣ";
	color(15);
}