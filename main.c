#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Game.h"
#include "GameLib.h"

extern int X,Y;

int main() {//最好通过一个游戏进程函数将main方法里边的各种方法封装, 通过不同状态执行不同方法
    char key;           //接收用户输入
    SetColor(2,0);      //设置控制台文本颜色(front color为绿色, background color为黑色)
    SetConsoleTitle("笑傲江湖之精忠报国 C语言实现 BY 左手工匠");    //设置控制台标题
    PropInit();         //初始化测试人物
    ShowWelcome();      //显示欢迎栏
    ShowMap();          //显示地图
    ShowInformation();  //显示信息栏
    ShowMainMenu();     //显示菜单栏
while (1) {
    fflush(stdin);
    key = getch();
    fflush(stdin);
    if(key == '1' || key == '2' || key == '3' || key == '4'){
        GameProcess(key);
        continue;
    }
    else if(key == '5' || key == '6' ){
        SetPosition(20, 12);
        Clear(20 , 12, 7);
        SetPosition(20 + 5, 12 + 2);
        printf("放过我吧, 还没开发完呐!!!\n");
    }
    else if(key == '7') {
        break;
    }
    else if(key == VK_UP || key == 72) {
        Y--;            //输入上
    }
    else if(key == VK_RIGHT || key == 77) {
        X++;            //输入右
    }
    else if(key == VK_DOWN || key == 80) {
        Y++;            //输入下
    }
    else if(key == VK_LEFT || key == 75) {
        X--;            //输入左
    }
    if(X > 7) {//移动到最边的话重新回到0, 如贪食蛇穿过地图边缘
        X = 0;
    }
    if(X < 0) {
        X = 7;
    }
    if(Y > 7) {
        Y = 0;
    }
    if(Y < 0) {
        Y = 7;
    }
    ShowMap();
}
    return 0;
}
