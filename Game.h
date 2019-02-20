//
// Created by ���ֹ��� on 2019/2/16.
//

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>

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

/* ���� */
typedef struct _martial{
    int id;         //���ɱ��
    char name[20];  //��������
    char type[10];  //�������ͣ����ɡ�а�ɡ�������а
    COORD hqCoord;  //�ܲ����꣨X-�У�Y-�У����������������෴
    int isOpen;     //�Ƿ񿪷�(�������Ҹ�������, �����ٿ���)
    char description[1000];//��������
}Martial;

/** ����������� */
typedef struct  _play {
    char name[30];          //�������
    char id[10];            //��ұ��
    char passwd[30];        //�������
    int level;              //��ҵȼ�
    int exp;                //����ֵ
    int hp;                 //Ѫ��
    int mp;                 //����
    int gold;               //���
    Martial martial;        //��������
    Prop weapon;            //װ��������
    Prop armor;             //װ���ķ���
    COORD coord;            //��ҵ�ǰ���� (X, Y)
    // ��ұ��� (��δ���屳��)

} Player;

/** ������������ */
typedef struct _monster {
    int id;
    char name[20];           //��������
    int level;               //����ȼ�
    int hp;                  //Ѫ��
    int attact;              //������
    int defence;             //������
    int minMoney;            //�������С��Ǯ
    int maxMoney;            //���������Ǯ
    int exp;                 //����ܻ�ȡ�ľ���ֵ
    int state;               //�����״̬ (0 Ϊ����, 1 Ϊ���)
    COORD coord;             //���������
    // ����������ĵ���װ���б�

} Monster;

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

/** ��ʾ��Ϸ�����˵� */
void ShowMainMenu();

/** �����Ϣ������������(�������꼰���������) */
void Clear(int x, int y, int rowCount);

/** ��ʾ��Ϸ�·�����Ϣ��� */
void ShowInformation();

/** ��ʾ��ҵ�ǰ��Ϣ */
void ShowPlayerInfo();

/** ��ʾ��ǰ��ͼ�Ĺ��� */
void ShowMonster();

/** ִ����Ϸ���˵����� */
void GameProcess(char key);

/** ѡ��������ж�ս */
void MonsterFight(Monster *monster);

/** �ƶ����� */
void Move(int x, int y);

#endif // GAME_H_INCLUDED
