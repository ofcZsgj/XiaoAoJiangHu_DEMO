//
// Created by ���ֹ��� on 2019/2/17.
//

#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

#include <windows.h>
#include <stdlib.h>

/********************************************************************
 *  Project:Ц������֮���ұ���Demo
 *  Function:����������Ϸ�е�windowsϵͳ����
 *  Description:����������ɫ, ������
 *  Author:���ֹ���
 ********************************************************************
 *  Copyright 2019 by ���ֹ���
 ********************************************************************/

/** ���Ŀ���̨�ı��� */
void SetTitle(char *title);

/** ���Ŀ���̨��������ɫ */
void SetColor(int ForeColor, int BackColor);

/** ���ù��λ�� */
void SetPosition(int x, int y);

#endif // GAMELIB_H_INCLUDED
