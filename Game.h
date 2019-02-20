//
// Created by 左手工匠 on 2019/2/16.
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
 *  Project:笑傲江湖之精忠报国Demo
 *  Function:实现游戏的核心结构及函数
 *  Description:游戏的数据结构及函数
 *  Author:左手工匠
 ********************************************************************
 *  Copyright 2019 by 左手工匠
 ********************************************************************/

//玩家, 地图, 道具, 怪兽

/****************** 游戏的结构类型定义 ****************/

/** 地图数据类型 */
typedef struct _map {
    int id;                 //地图编号
    char name[20];          //地图名称
    int minLevel;           //玩家进入地图的最低等级
    COORD coord;            //坐标结构, windows.h 自带, 即(x, y)
    char desc[500];         //地图描述
} Map;

/** 道具数据类型 */

//游戏道具类型枚举 - 武器, 防具, 消耗品, 碎片
typedef enum _propType {
    Weapon,                 //武器
    Armor,                  //防具
    Con,                    //消耗品
    Frag,                   //碎片
} PropType;

typedef  struct _prop {
    int id;                 //道具编号
    char name[20];          //道具名称
    double price;           //道具价格
    int level;              //道具等级
    PropType type;    //道具类别
    int stock;              //道具库存
    union {//联合 - 多选一
        int minAttack;      //如果是武器类别, 则对应最低攻击力
        int minDefence;     //如果是防具类别, 则对应最低防御力
        int minPower;       //如果是消耗品类别, 则对应最低回复值
    };
    union {//联合 - 多选一
        int maxAttack;      //如果是武器类别, 则对应最高攻击力
        int maxDefence;     //如果是防具类别, 则对应最高防御力
        int maxPower;       //如果是消耗品类别, 则对应最高回复值
    };
    char desc[200];         //道具描述
} Prop;

/* 门派 */
typedef struct _martial{
    int id;         //门派编号
    char name[20];  //门派名称
    char type[10];  //门派类型：正派、邪派、亦正亦邪
    COORD hqCoord;  //总部坐标（X-行，Y-列），与正常坐标轴相反
    int isOpen;     //是否开放(人民币玩家更多门派, 后期再开发)
    char description[1000];//门派描述
}Martial;

/** 玩家数据类型 */
typedef struct  _play {
    char name[30];          //玩家名称
    char id[10];            //玩家编号
    char passwd[30];        //玩家密码
    int level;              //玩家等级
    int exp;                //经验值
    int hp;                 //血量
    int mp;                 //内力
    int gold;               //金币
    Martial martial;        //所属门派
    Prop weapon;            //装备的武器
    Prop armor;             //装备的防具
    COORD coord;            //玩家当前坐标 (X, Y)
    // 玩家背包 (尚未定义背包)

} Player;

/** 怪物数据类型 */
typedef struct _monster {
    int id;
    char name[20];           //怪物名称
    int level;               //怪物等级
    int hp;                  //血量
    int attact;              //攻击力
    int defence;             //防御力
    int minMoney;            //掉落的最小金钱
    int maxMoney;            //掉落的最大金钱
    int exp;                 //玩家能获取的经验值
    int state;               //怪物的状态 (0 为死亡, 1 为存活)
    COORD coord;             //怪物的坐标
    // 怪物死亡后的掉落装备列表

} Monster;

/** 初始化游戏数据 */
void PropInit();

/** 显示游戏全局数据 */
void Show();

/** 显示欢迎信息 */
void ShowWelcome();

/** 显示游戏地图 */
void ShowMap();

/** 显示地图信息 */
void ShowMapInfo();

/** 显示游戏的主菜单 */
void ShowMainMenu();

/** 清除信息区内所有内容(给定坐标及清理的行数) */
void Clear(int x, int y, int rowCount);

/** 显示游戏下方的信息面板 */
void ShowInformation();

/** 显示玩家当前信息 */
void ShowPlayerInfo();

/** 显示当前地图的怪物 */
void ShowMonster();

/** 执行游戏主菜单功能 */
void GameProcess(char key);

/** 选定怪物进行对战 */
void MonsterFight(Monster *monster);

/** 移动坐标 */
void Move(int x, int y);

#endif // GAME_H_INCLUDED
