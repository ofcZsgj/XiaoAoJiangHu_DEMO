//
// Created by ���ֹ��� on 2019/2/16.
//

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/********************************************************************
 *  Project:Ц������֮���ұ���Demo
 *  Function:ʵ����Ϸ�ĺ��Ľṹ������
 *  Description:��Ϸ�����ݽṹ������
 *  Author:���ֹ���
 ********************************************************************
 *  Copyright 2019 by ���ֹ���
 ********************************************************************/

//���, ��ͼ, ����, ����

/****************** ��Ϸ�Ľṹ���Ͷ��� ****************/

/** ��ͼ�������� */
typedef struct _map {
    int id;                 //��ͼ���
    char name[20];          //��ͼ����
    int minLevel;           //��ҽ����ͼ����͵ȼ�
    COORD coord;            //����ṹ, windows.h �Դ�, ��(x, y)
    char desc[500];         //��ͼ����
} Map;

/** ������������ */

//��Ϸ��������ö�� - ����, ����, ����Ʒ, ��Ƭ
typedef enum _propType {
    Weapon,                 //����
    Armor,                  //����
    Con,                    //����Ʒ
    Frag,                   //��Ƭ
} PropType;

typedef  struct _prop {
    int id;                 //���߱��
    char name[20];          //��������
    double price;           //���߼۸�
    int level;              //���ߵȼ�
    PropType type;    //�������
    int stock;              //���߿��
    union {//���� - ��ѡһ
        int minAttack;      //������������, ���Ӧ��͹�����
        int minDefence;     //����Ƿ������, ���Ӧ��ͷ�����
        int minPower;       //���������Ʒ���, ���Ӧ��ͻظ�ֵ
    };
    union {//���� - ��ѡһ
        int maxAttack;      //������������, ���Ӧ��߹�����
        int maxDefence;     //����Ƿ������, ���Ӧ��߷�����
        int maxPower;       //���������Ʒ���, ���Ӧ��߻ظ�ֵ
    };
    char desc[200];         //��������
} Prop;

/** ��ʼ����Ϸ���� */
void PropInit();

/** ��ʾ��Ϸȫ������ */
void Show();

/** ��ʾ��ӭ��Ϣ */
void ShowWelcome();

/** ��ʾ��Ϸ��ͼ */
void ShowMap();

/** ��ʾ��ͼ��Ϣ */
void ShowMapInfo();

/** �����Ϣ������������(�������꼰���������) */
void Clear(int x, int y, int rowCount);

/** ��ʾ��Ϸ�·�����Ϣ��� */
void ShowInformation();

/** ��ʾ��Ϸ�����˵� */
void ShowMainMenu();

#endif // GAME_H_INCLUDED
