//
// Created by 左手工匠 on 2019/2/17.
//

#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

#include <windows.h>
#include <stdlib.h>

/********************************************************************
 *  Project:笑傲江湖之精忠报国Demo
 *  Function:用来定义游戏中的windows系统操作
 *  Description:更改字体颜色, 清屏等
 *  Author:左手工匠
 ********************************************************************
 *  Copyright 2019 by 左手工匠
 ********************************************************************/

/** 更改控制台的标题 */
void SetTitle(char *title);

/** 更改控制台的文字颜色 */
void SetColor(int ForeColor, int BackColor);

/** 设置光标位置 */
void SetPosition(int x, int y);

#endif // GAMELIB_H_INCLUDED
