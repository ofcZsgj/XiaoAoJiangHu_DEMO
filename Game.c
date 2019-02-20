//
// Created by 左手工匠 on 2019/2/16.
//

#include "Game.h"
#include "GameLib.h"

int X = 0;
int Y = 0;

//#define SEP "------------------------------------------------------------------------------"
#define COL 78                //游戏的界面的总宽度
#define MAXGIN_X 20           //游戏界面与控制台的左边距
#define ENDINFO 78            //各个框架结束'|'的列数
#define MAPSART_START_Y 3     //游戏地图开始的行
#define MAPSART_END_Y 11      //游戏地图结束行
#define INFORMATION_START_Y 12//游戏信息开始行
#define INFORMATION_END_Y 19  //游戏信息结束行
#define MAINMENUE_START_Y 20  //游戏主菜单开始行
#define MAINMENUE_END_Y 28  //游戏主菜单结束行
#define SEP "*******************************************************************************"

Player playArray[] = {//测试玩家列表
    {"左手工匠", "95001", "0115", 100, 99999, 99999, 99999, 999999, .coord.X = 0, .coord.Y = 3},
    {"ofcZsgj", "95002", "0115", 100, 99999, 99999, 99999, 999999, .coord.X = 0, .coord.Y = 0},
};

Monster monsterArray[] = {//怪物列表
    {1, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=0},
    {2, "鬼子", 4, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=1},
    {3, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=2},
    {4, "鬼子", 3, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=3},
    {5, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=4},
    {6, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=5},
    {7, "鬼子", 4, 100, 5, 5, 1, 3, 10, 1, .coord.X=3, .coord.Y=0},
    {8, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=3, .coord.Y=5},
    {9, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=0, .coord.Y=0},
    {10, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=0, .coord.Y=1},
    {11, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=0, .coord.Y=2},
    {12, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=2, .coord.Y=3},
    {13, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=2, .coord.Y=4},
    {14, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=2, .coord.Y=5},
    {15, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=4, .coord.Y=4},
    {16, "汉奸", 4, 200, 8, 12, 1, 8, 11, 1, .coord.X=1, .coord.Y=7},
    {17, "浪人", 3, 300, 10, 10, 3, 8, 20, 1, .coord.X=0, .coord.Y=0},
    {18, "浪人", 3, 300, 10, 10, 3, 8, 20, 1, .coord.X=0, .coord.Y=1},
    {19, "浪人", 3, 300, 10, 10, 3, 8, 20, 1, .coord.X=4, .coord.Y=2},
    {20, "浪人", 3, 300, 10, 10, 3, 8, 20, 1, .coord.X=3, .coord.Y=3},
    {21, "浪人", 3, 300, 10, 10, 3, 8, 20, 1, .coord.X=0, .coord.Y=4},
    {22, "浪人", 4, 300, 50, 10, 3, 8, 20, 1, .coord.X=0, .coord.Y=5},
    {23, "浪人", 4, 300, 50, 10, 3, 8, 20, 1, .coord.X=5, .coord.Y=6},
    {24, "浪人", 5, 1000, 70, 30, 3, 8, 20, 1, .coord.X=2, .coord.Y=2},
    {25, "浪人", 6, 1500, 100, 40, 3, 8, 20, 1, .coord.X=0, .coord.Y=4},
    {26, "浪人", 7, 2000, 300, 70, 3, 8, 20, 1, .coord.X=6, .coord.Y=2},
    {27, "浪人", 8, 2500, 350, 80, 3, 8, 20, 1, .coord.X=0, .coord.Y=3},
    {28, "浪人", 9, 3000, 400, 100, 3, 8, 20, 1, .coord.X=4, .coord.Y=1},
    {29, "浪人", 9, 3000, 400, 100, 3, 8, 20, 1, .coord.X=3, .coord.Y=2},
    {30, "浪人", 9, 3000, 400, 100, 3, 8, 20, 1, .coord.X=0, .coord.Y=5},
    {31, "浪人", 9, 3000, 400, 100, 3, 8, 20, 1, .coord.X=0, .coord.Y=6},
    {32, "浪人", 5, 2000, 700, 30, 3, 8, 20, 1, .coord.X=0, .coord.Y=6},
    {33, "浪人", 4, 1000, 170, 30, 3, 8, 20, 1, .coord.X=0, .coord.Y=6},
    {34, "浪人", 8, 3000, 370, 300, 3, 8, 20, 1, .coord.X=0, .coord.Y=6},
    {35, "鬼子", 7, 4200, 250, 250, 1, 3, 10, 1, .coord.X=0, .coord.Y=6},
    {36, "鬼子", 5, 1500, 205, 150, 1, 3, 10, 1, .coord.X=0, .coord.Y=6},
    {37, "鬼子", 7, 2000, 365, 350, 1, 3, 10, 1, .coord.X=0, .coord.Y=6},
    {38, "浪人", 8, 3000, 400, 100, 3, 8, 20, 1, .coord.X=0, .coord.Y=6},
    {39, "浪人", 6, 3000, 400, 100, 3, 8, 20, 1, .coord.X=0, .coord.Y=6},
};

Map mapArray[8][8] = {//游戏地图列表
        {
            {1, "天山",   1, {0, 0}, "据《穆天子传》记载，3000年前的周朝穆王曾乘坐\"八骏马车\"西行天山，西王母在天池接见了他。穆王赠送大批锦绸美绢等中原特产，西王母则回赠了天山的奇珍瑰宝，并邀请穆王游览天山名胜。穆王亲书\"西王母之山\"，留作纪念。临别时，西王母劝饮再三，即席歌曰:\"祝君长寿，愿君再来。\""},
            {2, "楼兰",   1, {1, 0}, "东通敦煌，西北到焉耆、尉犁，西南到若羌、且末。古代“丝绸之路”的南、北两道从楼兰分道。"},
            {3, "白驼山", 1, {2, 0}, "这可是当年大魔头欧阳锋的发家之地。今天的白驼山却很安静。。。"},
            {4, "野猪林", 1, {3, 0}, "野猪林里到处都是野猪。。。嗖！嗖！嗖！搜！。。。四只小野猪围了过来。喝过8个巨无霸后，领头的野猪朗声道：俗套！"},
            {5, "水晶洞", 1, {4, 0}, "走进一个洞中，洞中的景色马上呈现在眼前，这里真是太美了。一低头，发现脚边有一块石碑，上面写着：水晶洞。"},
            {6, "天蚕洞", 1, {5, 0}, "天蚕洞满地蚕茧，满地飞蛾。噗噜噜！噗噜噜！拨开飞蛾，踢开蚕蛹。。。但见一绝色女尼正坐在你的面前@！@！闭眼闭眼！"},
            {7, "黑风寨", 1, {6, 0}, "黑风寨只有狂风在不停地吹。突然，一条东瀛狼狗疯狂地扑了上来，一阵乱咬。"},
            {8, "冰火岛", 1, {7, 0}, "冰火岛上只有火球、冰块。快跑，轰隆隆----火山爆发了！咦，怎么只有烟，没有火？"}
        },
        {
            {9, "迷宫",    1, {0, 1}, "这里是高昌迷宫，也是一个十分神秘的地方，连江湖阅历及其丰富的老侠客都不知道这会发生什么事情。"},
            {10, "凌霄城", 1, {1, 1}, "凌霄城只有哆嗦，没人。"},
            {11, "轩辕岭", 1, {2, 1}, "一条山岭，绿油油的，不过从远处看去，岭上透出一层杀气，问过路人才知道，这里就是早有耳闻的轩辕岭！"},
            {12, "华山",   1, {3, 1}, "自古华山一条路，只许上，不许撤。如同风景介绍一般，五岳派总舵岂是邪魔歪道们随便来去之地？不过如果是君子，那就大可放心了。"},
            {13, "嵩山",   1, {4, 1}, "在雄伟的嵩山上，有一个江湖上名声响亮的寺庙：少林寺。如果说桂林山水甲天下，那么少林武功甲天下并不为过。"},
            {14, "紫禁城", 1, {5, 1}, "大内高手云集的地方。谁要赶来这里闹事，得罪的不光是大内锦衣卫，还有当今的皇上。"},
            {15, "快活林", 1, {6, 1}, "快活林快活林，有钱才能快乐！"},
            {16, "神龙岛", 1, {7, 1}, "这一上岛来，就能听到不知是韦小宝还是周星驰发出的笑声：啊哈哈哈哈哈哈哈！！这就是神龙教的总舵：神龙岛了。"},
        },
        {
            {17, "西域",   1, {0, 2}, "西域大漠的风沙吹得人和牲畜都睁不开眼睛。这里没有水，没有树，没有草，死一般的像个地狱。"},
            {18, "葫芦谷", 1, {1, 2}, "葫芦峪里似乎只有葫芦。远看还真像只大葫芦。"},
            {19, "唐门",   1, {2, 2}, "这里是唐家堡，从外面看这只是一个大宅院，与其他的富家宅院没有什么两样，但却是藏龙卧虎之地。"},
            {20, "终南山", 1, {3, 2}, "这里是终南山，全真教总舵。两旁丛丛耸耸的长满了各种树木，大道的尽头出现一座道观，几个小道士边聊天边请扫道观。"},
            {21, "石窟",   1, {4, 2}, "这里是龙门石窟，一个个的石窟自有一种神秘感。"},
            {22, "客栈",   1, {5, 2}, "地处交通要道的龙门客栈可是名扬四海，老帮娘金香玉的名头也是世人皆知，今天她在店里吗？"},
            {23, "玉皇顶", 1, {6, 2}, "一个永远不会安定的地方：泰山玉皇顶。这里是一个充满着厮杀的地方，无时无刻不充斥着暴力、仇杀的地方。"},
            {24, "灵蛇岛", 1, {7, 2}, "到处都是蛇的岛，这就是灵蛇岛。在这里，恐怖的故事层出不穷，令人毛骨悚然。不过要是喜欢吃蛇的人来到这里，可是该高兴死了。"},
        },
        {
            {25, "光明顶", 1, {0, 3}, "所谓三十六峰者，骈列舒张，横绝天表，众岫叠岭，效奇献秀，尽在一览。"},
            {26, "摩天崖", 1, {1, 3}, "这里是摩天崖，陡峭的石壁，就连猿猴上下都不可能，真是太险了。真难以想象当年谢烟客是如何在上面生存而又可以叱咤风云的。"},
            {27, "聚贤庄", 1, {2, 3}, "聚贤庄大家今日都很忙。虽然现在没人，不过无所谓！"},
            {28, "后山",   1, {3, 3}, "终终南后山的景色就是不一般，到处盛开着叫不上名字的各色小花，几只蜜蜂在花间飞舞，沿着一条花间小路来到一个古墓前，上面写着：活死人墓。"},
            {29, "武当山", 1, {4, 3}, "武当山只有火工道人在打盹。红卫兵刚刚来过！道士全都拉走批斗了！"},
            {30, "开封府", 1, {5, 3}, "宋朝时的都城，因有包青天而世人皆知。同时也是武林人士活动的要地。"},
            {31, "二十四桥", 1, {6, 3}, "今天没人乐意走二十四桥，不如坐下来喝点茶，寂寞高手嘛！"},
            {32, "蓬莱仙境", 1, {7, 3}, "云雾缭绕的蓬莱仙境自古以来都似乎隐藏着天大的秘密，谁能真正揭开这里的迷呢？也许你可以，也许他额可以。"},
        },
        {
            {33, "擂鼓山", 1, {0, 4}, "这里是擂鼓山，一点也想不到这座山为什么要起这个名字，看到的是这么美丽的景致，听到的却是个并不美丽的名字。"},
            {34, "峨眉山", 1, {1, 4}, "峨眉金顶只有几个扫山尼姑。尼姑当然寂寞！寂寞的人当然想说话！说了乱七八糟后，并没有提供什么有用的信息。"},
            {35, "迷踪林", 1, {2, 4}, "这里是迷踪林，人们总说这片树林不要轻易走进，因为它十分危险，据说有不少人走进去就再也没有出来过。"},
            {36, "五虎岭", 1, {3, 3}, "五虎岭素以五条猛虎闻名，每年都有许多不自量力的捕虎人成群进入，但从来都是一去无回，五虎真的如此厉害？"},
            {37, "天宁寺", 1, {4, 4}, "佛家地天宁寺，每天前来进香之人络绎不绝。可从进香之人求愿灵验的程度上让人不得不产生怀疑。"},
            {38, "积善堂", 1, {5, 4}, "积善堂今天没卖出一张彩票。此时已是深夜，不如早些睡了吧！"},
            {39, "镇江府", 1, {6, 4}, "从两百里以外就可以闻到一股酸味，这就是镇江府，盛产镇江醋。"},
            {40, "桃花岛", 1, {7, 4}, "桃花岛今天没人来偷桃，愉快的花工正躺在花下。"},
        },
        {
            {41, "恶人谷",     1, {0, 5}, "恶人善人都不在谷里。只有小鱼儿在睡觉！这家伙，抗倭一点都不积极。"},
            {42, "大理",       1, {1, 5}, "大理城里只有大理平民，平民最好打交道!"},
            {43, "百花谷",     1, {2, 5}, "哇，这里太美了，这里的很多花都叫不上名字！"},
            {44, "孔雀山庄",   1, {3, 5}, "这里金湖碧波荡漾，典型的傣式建筑掩映在茂密的森林之中，孔雀争相开屏、鸵鸟欢唱迎宾，梅花鹿湖畔戏水，人与自然和谐相融。"},
            {45, "五霸岗",     1, {4, 5}, "如果有人问：哪里能交上武林朋友？那答案肯定是五霸岗。此地虽怪石嶙峋、寸草不生，但却是天下英雄汇聚的地方。"},
            {46, "万仞堂",     1, {5, 5}, "万仞堂，顾名思义，十八般兵刃样样俱全。最近该堂还搞了点副业，外卖防具、药丸，有意者敬请光顾。"},
            {47, "栖霞古刹",   1, {6, 5}, "栖霞古刹今天没人来拜佛，倭寇究竟在哪里呢？不仅仰天长叹。"},
            {48, "六合塔",     1, {7, 5}, "六合塔里阴森森的。空调可够足的！"},
        },
        {
            {49, "玩偶山庄", 1, {0, 6}, "来到了玩偶山庄，这里好像什么东西都与其他地方有些不同，这是一个十分特别的地方，不知进庄之后还能有什么与众不同的东西。"},
            {50, "黑木崖", 1, {1, 6}, "黑木崖今天没人来会任我行。突然间，飞来一只黑鸽，徐徐盘旋而下。"},
            {51, "蝴蝶谷", 1, {2, 6}, "为何蝴蝶谷中会有如此众多的蝴蝶？是不是因为发生了什么不可告人的事情？看来只有有缘人才能知道了。"},
            {52, "铁花堡", 1, {3, 6}, "神秘的铁花堡，曾经是飞龙帮在三百年前的总舵。自从飞龙帮最后一任帮主争夺武林盟主失败自杀后，如今已是一片凋零。如今的铁花堡，多的是制造铁工艺品的工匠。"},
            {53, "霹雳堂", 1, {4, 6}, "江湖雷家曾把这里建立成唯一可以与唐门暗器抗衡的雷家火器大本营。"},
            {54, "关帝庙", 1, {5, 6}, "一到关帝庙，就会看到无数乞丐。他们虽乞讨，但真实的任务却是习武练功，除暴安良。"},
            {55, "麒麟庄", 1, {6, 6}, "麒麟庄的人都被麒麟给吓跑了。"},
            {56, "销魂宫", 1, {7, 6}, "销魂宫现在没人消化灵魂。不如跟小姐们聊聊！群中的眼睛是雪亮的！头牌秦可卿柔声道：大兄弟做个大保健吧！"},
        },
        {
            {57, "石府",   1, {0, 7}, "天机石府里只有石头。石头当然不会是乱放的。可惜，石头太多怎么办？"},
            {58, "金三角", 1, {1, 7}, "金三角里看来没有别人。只有只老狗悻悻的靠在罂粟田头吸着什么。。。"},
            {59, "忏悔崖", 1, {2, 7}, "忏悔崖上没人在忏悔，却有人在宣传倭寇！"},
            {60, "通吃岛", 1, {3, 7}, "通吃岛上只有“此岛危险！当心被吃”几个字。"},
            {61, "通天观", 1, {4, 7}, "一个普普通通、其貌不扬的小小通天观，有意者都可以进来玩玩。观内有一颗很高的大树，从来没有人能够爬到树顶。据说它是通天的。"},
            {62, "紫霞亭", 1, {5, 7}, "紫霞亭现在空着，亭中有一盘棋。棋子不合棋法，但对你却有用！"},
            {63, "天弃庵", 1, {6, 7}, "天弃庵是空空荡荡的小尼姑庵。我想进去，但人家不让。"},
            {64, "侠客岛", 1, {7, 7}, "侠客岛没人钻研侠客神功。卖门票的女子百无聊赖。"},
        },
};//八个一维数组分别使用{}的原因为编译器对维度产生了混淆, 导致打印地图只有第一个一维数组!!!

Prop propArray[] = {//游戏道具列表
        {1, "嵩阳古剑" ,1000, 1, Weapon, 50, .minAttack = 16, .maxAttack = 22, "剑是老了点，可砍起人来一点都不含糊。实在不想用，当古董卖好了!"},
        {2, "形意六合棍", 2000, 2, Weapon, 40, .minAttack = 30, .maxAttack = 38, "虽然名为“六合”，可传说中的高手却能用它使出八种猛兽的形态，你呢？"},
        {3, "暴雨梨花针", 5000, 3, Weapon, 35, .minAttack = 55, .maxAttack = 78, "出必见血，空回不祥，急中之急，暗器之王！气死人了，这暴风骤雨般的梨花针怎么躲得开嘛！难道非逼人穿“防弹背心”不成？"},
        {4, "踏月襟", 20000, 7, Armor, 10, .minDefence = 28, .maxDefence = 34, "举头望月, 看到了吗, 那就是月亮的力量啊, 化月光之力为我挡伤害!"},
        {5, "斩霜金轮", 50000, 9, Armor, 3, .minDefence = 200, .maxDefence = 300, "神秘的光晕, 一圈圈的涟漪在金轮荡漾, 谁也不知道它从何而来, 但它的光辉无人能侵!"},
        {6, "金创药", 2000, 3, Con, 50, .minPower = 500, .maxPower = 600, "金创药，俗称刀尖药，其实是一种药的商用名，比如，跌打药，专治跌打损伤, 少侠可要来一份"},
        {7, "真气丸", 2500, 4, Con, 50, .minPower = 500, .maxPower = 600, "燃烧内力, 迅速补充全身能量, 打开你的三万六千个毛孔, 以汲取天地日月精华!"},
        {8, "穿云裂石戟", 45000, 8, Weapon, 5, .minAttack = 300, .maxAttack = 600, "在海中呆了一万年的它，很可能并非地球之物。劝你小心保管，说不定哪天外星人从天而降，把此戟收回可就太不划算了！"},
        {9, "八宝玲珑枪", 50000, 9, Weapon, 3, .minAttack = 400, .maxAttack = 700, "枪身镶有八种宝物。拥有此枪之人，可以说拥有了一笔不小的财富！"},
};

Player *currPlayer;
void PropInit() {
    currPlayer = &playArray[0];
    currPlayer->weapon = propArray[8];
    currPlayer->armor = propArray[4];
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
        printf("*    ");
        for(int j = 0; j < (MAPSART_END_Y - MAPSART_START_Y); j++) {
            if(j == X && i == Y) {       //高亮显示光标所对应的地图
                SetColor(4, 7);
            }
            printf("%-9s", mapArray[j][i].name);
            SetColor(2,0);              //恢复文字颜色
            if(j == MAPSART_END_Y - MAPSART_START_Y - 1) {
                printf(" *");    //调节光标使每一行尾打印'|'字符
            }
        }
        SetPosition(MAXGIN_X, MAPSART_END_Y);
        printf("%s", SEP);
    }
    ShowMapInfo();
}

/** 显示地图信息 */
void ShowMapInfo() {
    Clear(MAXGIN_X, INFORMATION_START_Y,  7);       //对信息区域进行清屏
    SetPosition(MAXGIN_X + 24, INFORMATION_START_Y);
    printf("当前地图为: %s", mapArray[X][Y].name);       //打印当前地图名称
    SetPosition(MAXGIN_X + 7, INFORMATION_START_Y + 1);
    char *desc;      //指向要打印的地图的描述信息的字符指针
    desc = mapArray[X][Y].desc;
    int descLen = strlen(desc);
    for(int i = 0; i < descLen; i++) {
        if(i != 0 && i % 66 == 0) {     //控制每行打印66个字符长度换行
            SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 1 + i / 66);
        }
        printf("%c", desc[i]);      //逐个打印字符
    }
}

/** 清除信息区内所有内容(给定坐标及清理的行数) */
void Clear(int x, int y, int rowCount) {
    for(int i = 0; i < rowCount; i ++) {
        SetPosition(x + 1, y + i);
        for(int j = 0; j < COL - 1; j ++)  {    //使用' '替换指定区域
            printf(" ");
        }
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
    for(int i = 0; i < MAINMENUE_END_Y - MAINMENUE_START_Y; i++) {
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
    printf("7: 退出游戏");
    SetPosition(MAXGIN_X, MAINMENUE_END_Y);
    printf("%s", SEP);
}

/** 显示玩家当前信息 */
void ShowPlayerInfo() {
    Clear(MAXGIN_X, INFORMATION_START_Y, 7);
    SetPosition(MAXGIN_X + 26, INFORMATION_START_Y);
    printf("大侠 %s 的装备属性如下: ", currPlayer->name);
    SetPosition(MAXGIN_X + 10, INFORMATION_START_Y + 1);
    printf("等级: %d\t 金币: %d\t  气血值: %d\t  内力值: %d\t", currPlayer->level, currPlayer->gold, currPlayer->hp, currPlayer->mp);
    SetPosition(MAXGIN_X + 10, INFORMATION_START_Y + 2);
    printf("当前武器:");
    SetColor(5,0);
    printf("%s(%d-%d) ", currPlayer->weapon.name, currPlayer->weapon.minAttack,currPlayer->weapon.maxAttack);
    SetColor(2,0);
    printf("当前防具:");
    SetColor(5,0);
    printf("%s(%d-%d)", currPlayer->armor.name, currPlayer->armor.minDefence,currPlayer->armor.maxAttack);
    SetColor(2,0);
}

/** 执行游戏主菜单功能 */
void GameProcess(char key) {
    switch (key) {
        case '1': ShowPlayerInfo();//显示玩家个人信息
            break;
        case '2': ShowMonster();//显示当前地图的怪物
            break;
        case '3':
            break;
        case '4':
            break;
        default : printf("少侠究竟想要作甚?");
    }
}

/** 显示当前地图的怪物********(功能略复杂些)*************/
void ShowMonster() {
    //给怪物各个等级对应相应称号
    //例如：3级怪物，那么就显示这个怪物的描述为粗通皮毛
    char *monsterlevelNames[] = {"乳臭未干", "初出茅庐", "粗通皮毛", "青年才俊", "略有小成", "心领神会", "出类拔萃", "所向无敌", "天人合一"};
    Clear(MAXGIN_X,  INFORMATION_START_Y, 7);   //清空信息区的所有内容
    int monsterCount;
    // 记录整个游戏的怪物总数
    monsterCount = sizeof(monsterArray) / sizeof(Monster);
    //记录当前地图的怪数量 记得变量定义时赋初值!!! debug了好久...
    int currMapMonsterCount = 0;
    // 定义一个只有九个空间的一维数组, 用以记录怪物在怪物列表里的下标
    int monsterIndex[9];
    for(int i = 0; i < monsterCount; i++) {
        // 关键!!! 满足怪物坐标与当前地图坐标相等 并且 该怪物的状态为存活的条件, 将怪物与怪物数组的下标记录并且当前地图怪物数量自增
        if(monsterArray[i].coord.X == X && monsterArray[i].coord.Y == Y && monsterArray[i].state == 1) {
            // 记录下标
            monsterIndex[currMapMonsterCount] = i;
            currMapMonsterCount++;
            // 设定每个地图最多显示 9 个怪物
            if(currMapMonsterCount == 9) {
                break;
            }
        }
    }
    // 打印怪物
    SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 1);
    if(currMapMonsterCount == 0) {
        printf("这里冷冷清清的什么也没有, 少侠还是到别处看看吧, 呆着也没银子给你!");
        return;
    }

/*********以下语句为判定用户输入的编号来返回地图信息或进行打怪操作*******/
    int pkMonsterId = 0;// 接收玩家输入的怪物编号, 定义在循环外部是因为循环外仍需使用进行判断是否打印地图信息
    while(1){
        pkMonsterId = -1;
        Clear(MAXGIN_X,  INFORMATION_START_Y, 7);   //清空信息区的所有内容
        SetPosition(MAXGIN_X + 20, INFORMATION_START_Y + 0);
        printf("少侠, 这儿有怪物! 要为百姓除暴安良吗?" );
        SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 2);
        for(int i = 0; i < currMapMonsterCount; i++) {
            if(i % 3 == 0 && i != 0){//每行打印三个怪物
                SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 2 + i / 3);
            }
            //打印怪物, 较为繁琐
            //monsterIndex[i]即为该怪物列表中的怪物编号
            printf("%d.%s(%s)\t  ", i + 1, monsterArray[monsterIndex[i]].name, monsterlevelNames[monsterArray[monsterIndex[i]].level - 1]);
        }
        SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
        printf("少侠想攻击几号怪物呢? (按0返回)");
        scanf("%d", &pkMonsterId);
        if(pkMonsterId == 0) {//输入0, 退出循环来返回显示地图信息
            break;
        }
        else if(pkMonsterId < 0 || pkMonsterId > currMapMonsterCount) {
            //输入的怪物标号在当前地图不存在
            SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
            //简易清屏
            printf("                                                             ");
            SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
            printf("少侠选错了吧, 怪物不存在呢!(按任意键重新输入)");
            char recoverKey = getchar();
            if(!recoverKey){//停顿直到接收任意键后重新显示怪物
                continue;
            }
        }
        else {//编号对应地图所有的怪物时, 将怪物地址传入打怪方法
            MonsterFight(&monsterArray[monsterIndex[pkMonsterId - 1]]);
            break;
        }
    }
    if(pkMonsterId == 0) {//输入0, 返回显示地图信息
        ShowMapInfo();
    }
}

/** 选定怪物进行对战 */
void MonsterFight(Monster *monster) {
    SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
    printf("                                                             ");//简易清屏(偷懒)
    SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
    srand(time(NULL));//以当前时间为种子
    /* random函数的用法(只能0 - 32767之间)
    * 随机一个a ~ b的数字, 即 rand() % (b - a + 1) + a; 例如0 ~ 5, 即rand() % 6;
    */
    int playerAttact = 0;
    // 玩家的实际攻击力
    playerAttact = rand() % (currPlayer->weapon.maxAttack - currPlayer->weapon.minAttack + 1) + currPlayer->weapon.minAttack;
    int playerDeffence =0;
    //玩家实际防御力
    playerDeffence = rand() % (currPlayer->armor.maxDefence - currPlayer->armor.minDefence + 1) + currPlayer->armor.minDefence;
    //怪物实际掉落的金钱
    int monsterGold = 0;
    monsterGold = rand() % (monster->maxMoney - monster->minMoney + 1) + monster->minMoney;
    int pkRound = 0;    //记录战斗的轮次
    while(1){//打斗循环, 任意一方死亡退出
        //玩家血量变化
        currPlayer->hp -= monster->attact - playerDeffence;
        //怪物的血量变化
        monster->hp -= playerAttact - monster->defence;
        if(monster->hp <= 0) {//怪物的血量少于等于0时退出
            break;
        }
        if(currPlayer->hp <= 0) {//玩家血量小于等于0时退出
            break;
        }
        //以下为打印战斗详情
        SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
        printf("                                                                         ");//简易清屏(偷懒)
        SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
        pkRound++;
        //战斗详情使用白底红字
        SetColor(4,7);
        //该语句较长......
        printf("第 %d 轮战斗详情:%s 对 %s 造成了 %d 伤害且受到 %s %d 的伤害", pkRound, currPlayer->name, monster->name, playerAttact - monster->defence, monster->name, monster->attact - playerDeffence);
        //放慢过程
        usleep(1000 * 800);//1000毫秒*800
        SetColor(2, 0);
    }
    SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
    printf("                                                                   ");//简易清屏(偷懒)
    SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
    if(currPlayer->hp <= 0) {
        //玩家死亡输入完任意键后返回
        printf("江湖快讯: 大侠 %s 在与 %s 的对决中壮烈牺牲! (请按任意键返回)", currPlayer->name, monster->name);
        //重置人物的金币与血量
        currPlayer->hp = 100;
        currPlayer->gold = 100;
        getch();
        return;
    }
    //以下即为怪物死亡的情况
    printf("%s 轻而易举的便被 %s 大侠收拾了, 同时掉落了 ", monster->name, currPlayer->name);
    //将怪物的状态调整至死亡
    monster->state = 0;
    //设置金币的front color为黄色, background color为亮白色
    SetColor(6, 15);
    printf("%d 金币   ", monsterGold);
    // 设置经验的front color为黄色, background color为亮白色
    SetColor(1, 15);
    printf("%d 经验  ", monster->exp);
    SetColor(2, 0); //颜色恢复
    //玩家获得金币与经验值的加成
    currPlayer->gold += monsterGold;
    currPlayer->exp += monster->exp;
    getch();
    ShowMonster();
}
