//
// Created by ���ֹ��� on 2019/2/17.
//

#include "GameLib.h"

/** ���ÿ���̨�ı��� */
void SetTitle(char *title) {
    SetConsoleTitle(title);
}

/* ���ÿ���̨����ɫ
 * 0-��ɫ,   1-��ɫ,   2-��ɫ,    3-ǳ��ɫ,  4-��ɫ,
 * 5-��ɫ,   6-��ɫ,   7-��ɫ,    8-��ɫ,   9-����ɫ,
 * 10-����ɫ,  11-��ǳ��ɫ   12-����ɫ   13-����ɫ
 * 14-����ɫ   15-����ɫ
 */
 void SetColor(int ForeColor, int BackColor) {
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);              //��ȡ��ǰ���ھ��
     SetConsoleTextAttribute(handle, ForeColor + BackColor * 0x10);//������ɫ
 }

 /** ���ù��λ�� */
 void SetPosition(int x, int y) {
     HANDLE winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos = {x, y};
     SetConsoleCursorPosition(winHandle, pos);      //���ù��λ��
 }
