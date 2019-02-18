//
// Created by 左手工匠 on 2019/2/16.
//

#include "Game.h"
#include "GameLib.h"

//#define SEP "------------------------------------------------------------------------------"
#define COL 78                //游戏的界面的总宽度
#define MAXGIN_X 20           //游戏界面与控制台的左边距
#define ENDINFO 77            //各个框架结束'|'的列数
#define MAPSART_START_Y 3     //游戏地图开始的行
#define MAPSART_END_Y 11      //游戏地图结束行
#define INFORMATION_START_Y 12//游戏信息开始行
#define INFORMATION_END_Y 19  //游戏信息结束行
#define MAINMENUE_START_Y 20  //游戏主菜单开始行
#define MAINMENUE_END_Y 28  //游戏主菜单结束行
#define SEP "******************************************************************************"
Map mapArray[8][8] = {
        {
                {1, "天山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {2, "楼兰", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {3, "白驼山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {4, "野猪林", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {5, "水晶洞", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {6, "天蚕洞", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {7, "黑风寨", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {8, "冰火岛", 20, {0, 0}, "举目眺望, 尽是飞雪"},
        },
        {
                {9, "迷宫", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {10, "凌霄城", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {11, "轩辕岭", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {12, "华山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {13, "嵩山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {14, "紫禁城", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {15, "快活林", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {16, "神龙岛", 20, {0, 0}, "举目眺望, 尽是飞雪"},
        },
        {
                {17, "西域", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {18, "葫芦谷", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {19, "唐门", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {20, "终南山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {21, "石窟", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {22, "客栈", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {23, "玉皇顶", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {24, "灵蛇岛", 20, {0, 0}, "举目眺望, 尽是飞雪"},
        },
        {
                {25, "光明顶", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {26, "摩天崖", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {27, "聚贤庄", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {28, "后山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {29, "武当山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {30, "开封府", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {31, "二十四桥", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {32, "蓬莱仙境", 20, {0, 0}, "举目眺望, 尽是飞雪"},
        },
        {
                {33, "擂鼓山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {34, "峨眉山", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {35, "迷踪林", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {36, "五虎岭", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {37, "天宁寺", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {38, "积善堂", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {39, "镇江府", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {40, "桃花岛", 20, {0, 0}, "举目眺望, 尽是飞雪"},
        },
        {
                {41, "恶人谷", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {42, "大理", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {43, "百花谷", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {55, "孔雀山庄", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {45, "五霸岗", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {46, "万仞堂", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {47, "千年古刹", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {48, "六合塔", 20, {0, 0}, "举目眺望, 尽是飞雪"},
        },
        {
                {49, "玩偶庄", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {50, "黑木崖", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {51, "蝴蝶谷", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {52, "铁花堡", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {53, "霹雳堂", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {54, "关帝庙", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {55, "麒麟庄", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {56, "销魂宫", 20, {0, 0}, "举目眺望, 尽是飞雪"},
        },
        {
                {57, "石府", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {58, "金三角", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {59, "忏悔崖", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {60, "通吃岛", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {61, "通天观", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {62, "紫霞亭", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {63, "天弃庵", 20, {0, 0}, "举目眺望, 尽是飞雪"},
                {64, "侠客岛", 20, {0, 0}, "举目眺望, 尽是飞雪"},
        },
};//八个一维数组分别使用{}的原因为编译器对维度产生了混淆, 导致打印地图只有第一个一维数组!!!

Prop propArray[] = {
        {1, "嵩阳古剑" ,1000, 1, Weapon, 50, .minAttack = 16, .maxAttack = 22, "剑是老了点，可砍起人来一点都不含糊。实在不想用，当古董卖好了!"},
        {2, "形意六合棍", 2000, 2, Weapon, 40, .minAttack = 30, .maxAttack = 38, "虽然名为“六合”，可传说中的高手却能用它使出八种猛兽的形态，你呢？"},
        {3, "暴雨梨花针", 5000, 3, Weapon, 35, .minAttack = 55, .maxAttack = 78, "出必见血，空回不祥，急中之急，暗器之王！气死人了，这暴风骤雨般的梨花针怎么躲得开嘛！难道非逼人穿“防弹背心”不成？"},
        {4, "踏月襟", 20000, 7, Armor, 10, .minDefence = 28, .maxDefence = 34, "举头望月, 看到了吗, 那就是月亮的力量啊, 化月光之力为我挡伤害!"},
        {5, "斩霜金轮", 50000, 9, Armor, 3, .minDefence = 1688, .maxDefence = 1982, "神秘的光晕, 一圈圈的涟漪在金轮荡漾, 谁也不知道它从何而来, 但它的光辉无人能侵!"},
        {6, "金创药", 2000, 3, Con, 50, .minPower = 500, .maxPower = 600, "金创药，俗称刀尖药，其实是一种药的商用名，比如，跌打药，专治跌打损伤, 少侠可要来一份"},
        {7, "真气丸", 2500, 4, Con, 50, .minPower = 500, .maxPower = 600, "燃烧内力, 迅速补充全身能量, 打开你的三万六千个毛孔, 以汲取天地日月精华!"},
        {8, "穿云裂石戟", 45000, 8, Weapon, 5, .minAttack = 1500, .maxAttack = 1800, "在海中呆了一万年的它，很可能并非地球之物。劝你小心保管，说不定哪天外星人从天而降，把此戟收回可就太不划算了！"},
        {9, "八宝玲珑枪", 50000, 9, Weapon, 3, .minAttack = 2488, .maxAttack = 3244, "枪身镶有八种宝物。拥有此枪之人，可以说拥有了一笔不小的财富！"},
};

void PropInit() {

}

/** 打印道具类数据 */
void Show() {

}
    /** 显示欢迎信息 */
void ShowWelcome() {
    SetPosition(MAXGIN_X, 0);                   //通过'|,'-'字符画出欢迎框架 3 * 77
    printf("%s", SEP);
    SetPosition(MAXGIN_X, 1);
    printf("*");
    SetPosition(MAXGIN_X + 27, 1);
    printf("欢迎来到笑傲江湖的世界");
    SetPosition(MAXGIN_X + ENDINFO, 1);
    printf("*");
    SetPosition(MAXGIN_X, 2);
    printf("%s", SEP);
}

/** 显示游戏地图 */
void ShowMap() {                                //8 * 8 地图, 8 * 77 区域
    printf("\n");
    SetPosition(MAXGIN_X, MAPSART_START_Y);              //调节光标使得地图对齐标题
    printf("*");
    for(int i = 0; i < (MAPSART_END_Y - MAPSART_START_Y); i++) {
        SetPosition(MAXGIN_X, i + MAPSART_START_Y);      //调节光标使每一行首打印'*'字符
        for(int j = 0; j < (MAPSART_END_Y - MAPSART_START_Y); j++) {
            if(j == 0) {
                printf("*    ");
            }
            printf("%-9s", mapArray[j][i].name);
            if(j == MAPSART_END_Y - MAPSART_START_Y - 1) {
                printf("*");    //调节光标使每一行尾打印'|'字符
            }
        }
        SetPosition(MAXGIN_X, MAPSART_END_Y);
        printf("%s", SEP);
    }
}

/** 显示游戏下方的信息面板 */
void ShowInformation() {
    for(int i = 0; i < (INFORMATION_END_Y - INFORMATION_START_Y); i++) {
        SetPosition(MAXGIN_X, INFORMATION_START_Y + i); //打印信息面板框架, 7 * 77
        printf("*");
        SetPosition(MAXGIN_X + ENDINFO, INFORMATION_START_Y + i);
        printf("*");
    }
    SetPosition(MAXGIN_X, INFORMATION_END_Y);
    printf("%s", SEP);
}

/** 显示游戏的主菜单 */
void ShowMainMenu() {
    for(int i =  0; i < MAINMENUE_END_Y - MAINMENUE_START_Y; i++) {
        SetPosition(MAXGIN_X, MAINMENUE_START_Y + i);
        printf("*");
        SetPosition(MAXGIN_X + ENDINFO, MAINMENUE_START_Y + i);
        printf("*");
    }

    SetPosition(MAXGIN_X + 34, MAINMENUE_START_Y);
    printf("游戏菜单:");
    SetPosition(MAXGIN_X +31, MAINMENUE_START_Y + 1);
    printf("1: 查看装备");
    SetPosition(MAXGIN_X + 31, MAINMENUE_START_Y + 2);
    printf("2: 查看怪物");
    SetPosition(MAXGIN_X + 31, MAINMENUE_START_Y + 3);
    printf("3: 返回帮派");
    SetPosition(MAXGIN_X + 31, MAINMENUE_START_Y + 4);
    printf("4: 购买道具");
    SetPosition(MAXGIN_X + 31, MAINMENUE_START_Y + 5);
    printf("5: 拔剑四顾(敬请期待)");
    SetPosition(MAXGIN_X + 31, MAINMENUE_START_Y + 6);
    printf("6: 到此一游(敬请期待)");
    SetPosition(MAXGIN_X + 31, MAINMENUE_START_Y + 7);
    printf("7: 充值元宝(敬请期待)");
    SetPosition(MAXGIN_X, MAINMENUE_END_Y);
    printf("%s", SEP);
}
