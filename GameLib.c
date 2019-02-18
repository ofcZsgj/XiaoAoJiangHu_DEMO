//
// Created by 左手工匠 on 2019/2/17.
//

#include "GameLib.h"

/** 设置控制台的标题 */
void SetTitle(char *title) {
    SetConsoleTitle(title);
}

/* 设置控制台的颜色
 * 0-黑色,   1-蓝色,   2-绿色,    3-浅绿色,  4-红色,
 * 5-紫色,   6-黄色,   7-白色,    8-灰色,   9-淡蓝色,
 * 10-淡绿色,  11-淡浅绿色   12-淡红色   13-淡紫色
 * 14-淡黄色   15-亮白色
 */
 void SetColor(int ForeColor, int BackColor) {
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);              //获取当前窗口句柄
     SetConsoleTextAttribute(handle, ForeColor + BackColor * 0x10);//设置颜色
 }

 /** 设置光标位置 */
 void SetPosition(int x, int y) {
     HANDLE winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos = {x, y};
     SetConsoleCursorPosition(winHandle, pos);      //设置光标位置
 }
