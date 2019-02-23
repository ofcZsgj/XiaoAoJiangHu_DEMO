//
// Created by 左手工匠 on 2019/2/16.
//

#include "Game.h"
#include "GameLib.h"

int X = 0;      //坐标轴
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
#define MAINMENUE_END_Y 28    //游戏主菜单结束行
#define SEP "*******************************************************************************"

Player playArray[] = {//测试玩家列表
    {"左手工匠", "95001", "0115", 100, 99999, 99999, 99999, 999999, .coord.X = 0, .coord.Y = 3},
    {"ofcZsgj", "95002", "0115", 100, 99999, 99999, 99999, 999999, .coord.X = 0, .coord.Y = 0},
};

Monster monsterArray[] = {//怪物列表
    {1, "鬼子", 8, 2500, 350, 150, 100, 30, 10, 1, .coord.X=0, .coord.Y=0},
    {2, "鬼子", 4, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=1},
    {3, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=2},
    {4, "鬼子", 3, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=3},
    {5, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=4},
    {6, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=0, .coord.Y=5},
    {7, "鬼子", 4, 100, 5, 5, 1, 3, 10, 1, .coord.X=3, .coord.Y=0},
    {8, "鬼子", 1, 100, 5, 5, 1, 3, 10, 1, .coord.X=3, .coord.Y=5},
    {9, "汉奸", 7, 2000, 280, 120, 70, 80, 11, 1, .coord.X=0, .coord.Y=0},
    {10, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=0, .coord.Y=1},
    {11, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=0, .coord.Y=2},
    {12, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=2, .coord.Y=3},
    {13, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=2, .coord.Y=4},
    {14, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=2, .coord.Y=5},
    {15, "汉奸", 2, 200, 8, 12, 1, 8, 11, 1, .coord.X=4, .coord.Y=4},
    {16, "汉奸", 4, 200, 8, 12, 1, 8, 11, 1, .coord.X=1, .coord.Y=7},
    {17, "浪人", 9, 3000, 410, 110, 30, 80, 20, 1, .coord.X=0, .coord.Y=0},
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
    {40, "浪人", 9, 3000, 410, 110, 30, 80, 20, 1, .coord.X=0, .coord.Y=0},
    {41, "浪人", 5, 2000, 180, 50, 10, 30, 20, 1, .coord.X=0, .coord.Y=0},
    {42, "浪人", 6, 2200, 210, 60, 20, 40, 20, 1, .coord.X=0, .coord.Y=0},
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

/* 江湖门派 */
Martial martials[] ={
    {1, "少林派",   "正派", .hqCoord.X=1, .hqCoord.Y=4, 1, "中华武学的泰斗，明末，少林众多的人才中，以悟空和箭神二人排为一等。其中，悟空出家为僧，箭神乃俗家弟子。当时江湖人称少林双绝。少林寺中众僧在两大长老的带领下参加了江浙沿海抗击倭寇的战斗，在各路应募兵马中表现得最为骁勇。但正因抗倭之事，也使江湖中的众多门派产生了矛盾，其中首推少林和日月神教。悟空、箭神曾几度带领江湖同仁攻上光明顶，但由于日月神教和血河两派结为同盟，更何况邪派中高手如云，所以几次围剿未果而终，黑白两道都损失惨重"},
    {2, "武当派",   "正派", .hqCoord.X=3, .hqCoord.Y=4, 1, "武当在江湖上与少林齐名，有‘北崇少林’‘南尊武当’之说。 武当新一代的首领人物，是一位谦谦君子，一张轮廓分明的脸上总是带着爽朗的笑容，就连他的仇敌都不能不承认他是条少见的男子汉。凡人从十八岁崛起江湖，身经大小三十三战，至今从未败过一次。凡人一生中最不能忍受的两件事就是失败和错误。 "},
    {3, "丐帮",     "正派", .hqCoord.X=2, .hqCoord.Y=6, 1, "丐帮是中原武林中人数最为众多的一个门派，也是天下第一大帮派，以遍布天下乞丐的乞丐组成，分为污衣帮和净衣帮。丐帮中人大多都是社会地位比较低的人，但他们各个铮铮硬骨，品格高尚，很少出现卑劣之人。丐帮新一代众多弟子以天葵为首，除暴安良、行侠丈义、抑强扶弱，所作所为为天下人所津津乐道。"},
    {4, "全真教",   "正派", .hqCoord.X=2, .hqCoord.Y=3, 1, "全真属于道教的分支之一。现今全真教中最有权威的人是一个瘦瘦小小的人，长着一双冷冷淡淡好象永远不会有什么变化的眼睛，看起来仿佛是灰色的。但他又是一个非常讲究的人，他喜欢紫色，喜欢名马佳人华衣美酒，喜欢享受。对每一件事情他都非常的挑剔，做的每一件事都经过精密计划，绝不肯多浪费一分力气，也不会有一点疏忽。这就是全真海雅。"},
    {5, "五岳剑派", "正派", .hqCoord.X=1, .hqCoord.Y=3, 1, "泰山派，恒山派，衡山派，华山派，嵩山派结为同气枝连的的五岳剑派，在江湖上扬名立万。五派中人一向面和心不和，所以五派的式微不是由于外敌入侵，而纯粹是内部矛盾激化走向内耗的结果，内部的勾心斗角虽然常常以抗倭为借口出现，实则是为了掌握五岳生杀大权。"},
    {6, "四川唐门", "正派", .hqCoord.X=2, .hqCoord.Y=2, 1, "唐门在江湖上以暗器闻名。但自从唐门的唐老太太过世后唐家堡一度家道中落，加之唐甜为称霸武林挑起纷争，又使唐门陷入了再度的浩劫，几乎一蹶不振。在这种危难的时刻唐门出现了一群新生力量：唐纾、唐斩、唐缺、唐玉。他们整顿内务，肃清奸佞，打出了匡复武林正义的旗帜，并且在江湖上行侠仗义，挽回了唐门的声誉，使唐门成为了江湖上的名门正派。"},
    {7, "大理段氏", "正派", .hqCoord.X=5, .hqCoord.Y=1, 1, "大理段氏人丁众多，高手如云。其中有一位名扬江湖顶尖女侠——香雪儿。香雪儿面相灵秀，肤色白皙，但微显瘦弱，看上去弱不禁风却身怀绝世武功，已深得大理武功心得。"},
    {8, "天山派",   "正派", .hqCoord.X=0, .hqCoord.Y=0, 1, "天山派是名门正派，也是目前江湖中最为团结的一个门派。天山派也是江湖中女弟子最为众多的一个门派，且各个武功造诣不凡，相貌清秀。"},
    {9, "古墓派",   "正派", .hqCoord.X=3, .hqCoord.Y=3, 1, "古墓派这一代的传人名叫暄雯，是一女子，来历不明。暄雯生性娴静，长相俊美，举止飘逸，但做事情却不似师祖小龙女，倒颇有一点杨过的风格，武功修为深不可测，同样喜穿白衣。此派轻功卓越，剑法、拳法灵动妙绝，更是全真教的克星。古墓传人的处世原则是“事不关己，高高挂起”，过着与世无争的日子，但是如果有人冒犯了古墓传人，那他一定会死得很惨。"},
    {10, "名捕门",  "正派", .hqCoord.X=1, .hqCoord.Y=1, 1, "名捕门历属与官府，但其中也不乏在江湖上闯出名堂的武林高手。名捕门一等一的人才中有一位绰号叫‘惊天泣鬼’的，此人从不以真面目视人，总是在幕后策划一些事情。"},
    {11, "日月神教","邪派", .hqCoord.X=6, .hqCoord.Y=1, 1, "由于该教高手众多，并彼此互不相服，所以教务混杂。教中弟子多为邪恶之徒，专与名门正派作对，杀人良多，罪恶昭彰，故被江湖正派之人贬为魔教。"},
    {12, "权力帮",  "邪派", .hqCoord.X=4, .hqCoord.Y=0, 1, "邪派之一，目前派中最高首脑为一叫阿飞的年轻人。阿飞，一个表面上异常忧悒的人。没有与其交过手的武林高手，无法想象他那弱不禁风的身躯隐藏着那么大的潜力，更不能想象他是如何用支撑起权利帮的担子的。"},
    {13, "五毒教",  "邪派", .hqCoord.X=2, .hqCoord.Y=0, 1, "一个以使毒为专长的门派，派中人各个都是用毒高手。此派高手人称梦魇，其人使毒已入化境，令人难以琢磨，江湖同道对其莫不绕道而行。此人品行时好时坏，但坚韧卓绝，嗜武成痴。"},
    {14, "神龙教",  "邪派", .hqCoord.X=2, .hqCoord.Y=7, 1, "神龙教是江湖邪派，由于教址远离中原，所以不大干预中原武林的血腥杀戮。目前神龙教有两位高手一为刀神，此人武功高深莫测，性格孤僻冷傲，不喜与人接近。二为恶龙，武功高强但脾气暴躁，做事没有耐性。"},
    {15, "青龙会",  "邪派", .hqCoord.X=5, .hqCoord.Y=6, 1, "江湖上绵延数百年的一个神秘组织。青龙会下分十二堂，分别以月为代号。"},
    {16, "桃花岛",  "亦正亦邪", .hqCoord.X=4, .hqCoord.Y=7, 1, "自从东邪黄药师扬名立万于此后，他的传人就在这里绵延不绝，竟将桃花岛建成了门派的总舵。桃花岛黄药师的关门弟子程英一生未嫁，在岛上收了几个徒弟，桃花岛的武功因此得到延续和发扬。"},
    {17, "锦衣卫",  "亦正亦邪", .hqCoord.X=1, .hqCoord.Y=5, 1, "大内锦衣卫中人才济济，尤其是雷神，此人野心勃勃，自幼练得一身大力金刚功，号称刀枪不入，武功实是深不可测。而且为人机智，精通兵法，行兵时能将千军万马人使得如同数十万般威力十足。"},
    {18, "血河派",  "亦正亦邪", .hqCoord.X=5, .hqCoord.Y=0, 1, "自从血河派的掌门一代大侠方歌吟飘然而去后，血河派日益衰落。血河派活动的范围也越来越少，基本上只限与龙门石窟。而江湖上的九大门派已经把血河派视为邪魔歪道。并已传出英雄令，只要九大门派的门人遇上血河派的人，一律格杀无论。在江湖上已经没有什么血河派的人在行走。除了无恨！没有人知道他来自何方，人们只知道他来自血河派。没有人知道他的武功有多高，因为看见他的剑的人都已经......无恨是武林中的一个谜，现隐居在天山，相传是为了一名叫若寒的女子。相传血河弟子花无缺已深得无恨真传，在无恨隐居江湖期间代理血河的一切帮中事务。花无缺为人善良真诚，在江湖上人缘甚好，并将血河派内外事务打理得井井有条。"},
    {19, "通通吃",  "亦正亦邪", .hqCoord.X=7, .hqCoord.Y=3, 1, "江湖上一个神秘的门派，创始人，武功不祥。总舵设在通吃岛，教中首领人物——辉翰。此人手段严酷，以威服人。平常不轻易踏足中原武林，潜心修炼武功。"},
    {20, "玩偶山庄","亦正亦邪", .hqCoord.X=0, .hqCoord.Y=6, 1, "江湖上一个神秘的门派，创始人，武功不祥。总舵就在玩偶山庄，教中首领人物——阳光。玩偶山庄门人众多，但大都绝迹江湖，只有阳光经常独自浪迹江湖并闯出了名堂，所以武林中人才知有这么一个门派存在。"}
};

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
void PropInit() {//初始化游戏数据 (测试用数据)
    currPlayer = &playArray[0];
    currPlayer->weapon = propArray[8];
    currPlayer->armor = propArray[4];
    currPlayer->martial = martials[4];
    Bag bag = {95001, 0, 8};
    currPlayer->bag = bag;
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
    ShowMapInfo();//显示地图信息
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
    //以下用于展示玩家当前属性以及装备
    printf("大侠 ", currPlayer->name);
    SetColor(1, 0);//玩家名字黑底, 蓝色字
    printf("%s: ", currPlayer->name);
    SetColor(2, 0);
    printf(" 的装备属性如下: ");
    SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 1);
    printf("等级: %d  金币: %d  帮派:%s  气血值: %d  内力值: %d", currPlayer->level, currPlayer->gold, currPlayer->martial.name, currPlayer->hp, currPlayer->mp);
    SetPosition(MAXGIN_X + 10, INFORMATION_START_Y + 2);
    printf("当前武器:");
    //频繁设置颜色为了仅仅突出武器的颜色
    SetColor(5,0);
    printf("%s(%d-%d) ", currPlayer->weapon.name, currPlayer->weapon.minAttack,currPlayer->weapon.maxAttack);
    SetColor(2,0);
    printf("当前防具:");
    SetColor(5,0);
    printf("%s(%d-%d)", currPlayer->armor.name, currPlayer->armor.minDefence,currPlayer->armor.maxAttack);
    SetColor(2,0);
    SetPosition(MAXGIN_X + 4, INFORMATION_START_Y + 3);
    printf("-----------------------------------------------------------------------");
    //以下用于展示背包信息
    if(currPlayer->bag.propsCount == 0) {
        //若玩家背包内无物品, 给予提示
        SetPosition(MAXGIN_X + 16, INFORMATION_START_Y + 4);
        SetColor(4,  0);//红字黑底
        printf("背包空荡荡的什么也没有, 行走江湖可得多加小心啊");
    }
    else {
        //背包不为空打印背包道具
        SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 4);
        for(int i = 0; i < currPlayer->bag.propsCount; i++) {//最多打印九个道具
            if(i % 3 == 0 && i != 0){
                //设置每行打印三个道具
                SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 4 + i / 3);
            }
            SetColor(6, 0);
            printf("%-12s(%d)\t  ", currPlayer->bag.props[i].name, currPlayer->bag.props[i].stock);
        }
    }
    SetColor(2, 0);
}

/** 执行游戏主菜单功能 */
void GameProcess(char key) {
    switch (key) {
        case '1': ShowPlayerInfo();//显示玩家个人信息
            break;
        case '2': ShowMonster();//显示当前地图的怪物(内有打怪)
            break;
        case '3': Move(currPlayer->martial.hqCoord.X, currPlayer->martial.hqCoord.Y);//移动到玩家的帮派地图中
            break;
        case '4': ShowProps();//展示游戏商品
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
        SetColor(7, 0);//白字黑底
        printf("这里冷冷清清的什么也没有, 少侠还是到别处看看吧, 呆着也没银子给你!");
        SetColor(2, 0);//恢复颜色
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
            SetColor(4, 0);//红字怪物
            printf("%d.%s(%s)\t  ", i + 1, monsterArray[monsterIndex[i]].name, monsterlevelNames[monsterArray[monsterIndex[i]].level - 1]);
        }
        SetColor(2, 0);//恢复颜色
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
            char recoverKey = getch();
            if(recoverKey){//停顿直到接收任意键后重新显示怪物
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

/** 移动坐标 */
void Move(int x, int y) {
    Y = y;
    X = x;
    ShowMap();
}

/** 展示游戏商品 */
void ShowProps() {
    Clear(MAXGIN_X, INFORMATION_START_Y, 7);
    SetPosition(MAXGIN_X + 5, INFORMATION_START_Y);
    SetColor(8, 0);     //灰字黑底
    printf("欢迎大侠 %s 来到 %s 童叟无欺的杂货铺, 瞧一瞧看一看可有需要的?", currPlayer->name, mapArray[X][Y].name);
    SetColor(6, 0);     //黄字黑底
    SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 2);
    int propCount = sizeof(propArray) / sizeof(Prop) >= 9 ? 9 : sizeof(propArray) / sizeof(Prop);
    for(int i = 0; i < propCount; i++) {
        if(i % 3 == 0) {//打印商品, 每行 3 个, 且只打印最多 9 个
            SetPosition(MAXGIN_X + 5, INFORMATION_START_Y + 2 + i / 3);
        }
        printf("%-3d.%-10s(%-2d)%-4c", propArray[i].id, propArray[i].name, propArray[i].stock, ' ');
    }
    SetColor(2, 0);//恢复颜色

    int tradeId;//接收用户输入的商品编号
    while(1) {
        //用于判断输入编号是否正确(此判断未包括检验玩家金币及商品库存及玩家背包是否已满等状态)
        Clear(MAXGIN_X, INFORMATION_END_Y - 1, 1);
        SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
        printf("大侠需要什么, 请输入编号立即购买(按 0 退出)");
        scanf("%d", &tradeId);
        if(tradeId == 0) {//输入0返回显示地图信息
            ShowMapInfo();
            break;
        }
        else if(tradeId < 0 || tradeId > 9) {//输入的商品编号错误的情况, 重新输入
            Clear(MAXGIN_X, INFORMATION_END_Y - 1, 1);
            SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
            printf("少侠选错了吧, 商品不存在呢!(按任意键重新输入)");
            char recoverKey = getch();
            if(recoverKey){//停顿直到接收任意键后重新显示怪物
                continue;
            }
        }
        else {//输入在1 - 9的情况, 将编号传入交易函数
            showTrade(Trade(currPlayer, tradeId), tradeId);
            }
        }
}

/** 交易
  * 参数1: 玩家的地址
  * 参数2: 商品的编号
  * 返回交易是否成功, 0 失败, 1 成功
  */
int Trade(Player *player, int propsId) {
    Prop *tradeProp = NULL;     //定义一个用于指向及交易商品的指针
    for(int i = 0; i < sizeof(propArray) / sizeof(Prop); i++) {
        if(propsId == propArray[i].id) {//找到该商品, 并让tradeProp指向它
            tradeProp = propArray + i;  //即tradeProp = &propArray[i]
            break;
        }
    }
    //判断商品是否有库存
    if(tradeProp->stock <= 0) {
        Clear(MAXGIN_X, INFORMATION_END_Y - 1, 1);
        SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
        printf("地主家都没有余粮！商店都被买空啦！");
        return 0;
    }
    //判断玩家是否金币足够支付
    if(currPlayer->gold < tradeProp->price) {
        Clear(MAXGIN_X, INFORMATION_END_Y - 1, 1);
        SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
        printf("钱包都是瘪的，这可是个看钱的江湖！！!");
        return 0;
    }
    //判断玩家背包容量是否充足
    if(currPlayer->bag.propsCount > currPlayer->bag.maxCount && currPlayer->bag.propsCount != 0) {
        //玩家的背包道具数量大于最大容量并且背包道具数不为0则判定为失败
        Clear(MAXGIN_X, INFORMATION_END_Y - 1, 1);
        SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
        printf("背包已满，交易失败！");
        return 0;
    }
    //满足交易条件，执行交易的业务操作
    //1、商品库存-1
    tradeProp->stock--;
    //2、玩家金币-商品单价
    player->gold -= tradeProp->price;

    //*****************************玩家背包道具增加*******************************//
    //判断玩家背包中是否已有该商品 !!!
    int i;
    for(i = 0; i < currPlayer->bag.propsCount; i++) {
        if(propsId == currPlayer->bag.props[i].id) {
            currPlayer->bag.props[i].stock++;
            break;
        }
    }
    //若为循环正常结束, i = currPlayer->bag.propsCount, 即为背包无此商品, 需要给背包添加该商品!!!
    if(i == currPlayer->bag.propsCount) {
        //向背包中创建一个商品-复制一份要交易的商品信息到背包中
        currPlayer->bag.props[currPlayer->bag.propsCount].id = tradeProp->id;
        currPlayer->bag.props[currPlayer->bag.propsCount].price = tradeProp->price;
        currPlayer->bag.props[currPlayer->bag.propsCount].stock = 1;
        strcpy(currPlayer->bag.props[currPlayer->bag.propsCount].name, tradeProp->name);
        strcpy(currPlayer->bag.props[currPlayer->bag.propsCount].desc, tradeProp->desc);
        currPlayer->bag.propsCount++;
    }
    //交易成功
    return 1;
}

/** 接收Trade()返回的值, 判断交易是否成功 */
void showTrade(int flag, int propId) {
    if(flag == 0) {
        ShowMapInfo();
        return;
    }
    if(flag == 1) {
        Clear(MAXGIN_X, INFORMATION_END_Y - 1, 1);
        SetPosition(MAXGIN_X + 5, INFORMATION_END_Y - 1);
        printf("交易成功, ");
        SetColor(6, 0);     //打印装备为黑底黄字
        printf("%s", propArray[propId - 1].name);
        SetColor(2, 0);     //恢复黑底绿字
        printf(" 已经加入你的背包, 赶紧瞧一瞧吧!(按任意键继续)");
        getch();            //暂停
    }
}
