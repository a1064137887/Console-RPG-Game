#include"comment.h"



/*******************************************************************************
Function: void color();��ɫ���ƺ���
Description: �ı������������ı���ɫ
Calls:	#include<windows.h>
Input: const unsigned short COLor1������;0-15�ı�������ɫ������15�ı䣨�������ı���ɫ
Output: ������ı���ɫ�ı�
Return: ��
Others:
������ɫ��Ӧֵ��
0=��ɫ	1=��ɫ	2=��ɫ	3=����ɫ	4=��ɫ	5=��ɫ	6=��ɫ	7=��ɫ	8=��ɫ
9=����ɫ	10=����ɫ	11=��ǳ��ɫ	12=ǳ��ɫ	13=ǳ��ɫ	14=ǳ��ɫ	15=����ɫ
��ɫ��Ӧֵ��
0*16=��ɫ	16*1=��ɫ	16*2=��ɫ	16*3=����ɫ	16*4=��ɫ	16*5=��ɫ
16*6=��ɫ	16*7=��ɫ	16*8=��ɫ	16*9=����ɫ	16*10=����ɫ	16*11=��ǳ��ɫ
16*12=ǳ��ɫ	16*13=ǳ��ɫ	16*14=ǳ��ɫ	16*15=����ɫ
������ɫֵ����ɫ+������ɫ
*******************************************************************************/
/*-------------------------��ɫ���ƺ���begin----------------------------------*/
void color(const unsigned short COLor1)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLor1);
}





/*******************************************************************************
Function: void gotoxy();����ƶ�����
Description: ���ƹ���λ��
Calls: #include<windows.h>
Input: int ROW��, int COL��
Output: �ѿ���̨�Ĺ�����õ�ROW��COL��λ�ã�ROW�����У�COL������
Return: ��
Others: ����COL�����˴�����������ƶ��ĵ�λ��2���ֽ�
*******************************************************************************/
void gotoXY(int goRow, int goCol)
{
	COORD pos = { 2 * goCol, goRow };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



//==================Ӱ�ع�꺯��
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}