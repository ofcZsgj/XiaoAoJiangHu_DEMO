//
// Created by 左手工匠 on 2019/2/16.
//

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

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

/** 清除信息区内所有内容(给定坐标及清理的行数) */
void Clear(int x, int y, int rowCount);

/** 显示游戏下方的信息面板 */
void ShowInformation();

/** 显示游戏的主菜单 */
void ShowMainMenu();

#endif // GAME_H_INCLUDED
