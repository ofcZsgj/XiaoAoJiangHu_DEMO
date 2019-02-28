# XiaoAoJiangHu_DEMO

This is a console game demo that uses C to imitate XiaoAoJiangHu

这个demo简单的实现了用户输入方向键, 数字键达到在不同地图切换, 购买商品, 打怪升级等功能, 希望在后期能够实现更加丰富的功能并且能连接网络对战, 
开发环境为Atom,CodeBlocks,MinGW

![](https://i.imgur.com/k6UyqCP.png)

## 数据类型
1. 道具
2. 地图
3. 背包(背包包括道具类型)
4. 门派
5. 玩家(玩家包含背包以及门派数据类型)
6. 怪物

### 道具 (Prop)

**属性字段**

|属性|定义|
|:-:|:-:|
|编号|int id|
|名称|char name[30]|
|价格|double price|
|等级|int level|
|库存|int stock|
|类别|propType type(使用枚举)|
|最小属性|union(使用联合体)|
|最大属性|union(使用联合体)|
|描述|char desc[200]|


枚举代码
~~~
typedef enum _propType {
    Weapon,     //武器
    Armor,      //防具
    Con,        //消耗品
    Frag,       //碎片
} Type;
~~~
联合体代码  (不同类别拥有不同属性类别)
~~~
union {
    int minAttack;     //如果是武器类别, 则最 低/高 攻击力为
    int minDefence;    //如果是防具类别, 则最 低/高 防御力为
    int minPower;      //如果是消耗品类别, 则最 低/高 回复值为
}
~~~
~~~
要注意若定义枚举中使用 ; 分隔开, 则报错如下(这是我自己踩过的一个坑)
Expected '= constant-expression' or end of enumerator definition
~~~


### 地图(Map)
- 该DEMO的地图大小为8 * 8
- 后期增加地图进入的等级限制

**属性字段** 
|属性|定义|
|:-:|:-:|
|编号|int id|
|名称|char name[20]|
|进入地图的最低等级|minLevel|
|坐标结构|COORD coord|
|地图描述|desc[500]|
~~~
地图的坐标使用window.h头文件下的COORD结构, 使用方式为coord.X = 0, coord.Y = 0
~~~

### 背包 (Bag)
- 背包类型是玩家的一个属性
- 后期改进实现人民币玩家可以提升背包容量上限

**属性字段**
|属性|定义|
|:-:|:-:|
|所属玩家ID|int playId|
|当前的道具数量|int propsCount|
|背包最大容量|maxCount|
|道具数组|Prop props|

### 门派 (Martial)
- 门派为玩家的一个属性
- 后期改进实现人名币玩家解锁更多帮派功能

**属性字段**
|属性|定义|
|:-:|:-:|
|编号|int id|
|名称|char name[20]|
|门派类型|char type[10]|
|门派总部坐标结构|COORD hqCoord|
|是否对玩家开放|int isOpen|
|门派描述|char desc[1000]|

### 玩家 (Player)

**属性字段**
|属性|定义|
|:-:|:-:|
|名称|char name[30]|
|编号|id[10]|
|密码|char passwd[30]|
|等级|int level|
|经验值|int exp|
|血量|int hp|
|内力|int mp|
|金币|int gold|
|门派结构|Martial martial|
|武器道具|Prop weapon|
|防具道具|Prop armor|
|玩家当前坐标|COORD coord|
|背包结构|Bag bag|

### 怪物 (Monster)
- 后期加入怪物掉落装备功能

**属性字段**
|属性|定义|
|:-:|:-:|
|编号|int id|
|名称|char name[20]|
|等级|int level|
|血量|int hp|
|攻击力|int attact|
|防御力|int defence|
|掉落的最小金币|int minMoney|
|掉落的最大金币|int maxMoney|
|玩家能够获取的最大经验|int exp|
|怪物的状态(0死1活)|int state|
|怪物的坐标|COORD coord|
***
## 功能实现

**通过系统函数辅助实现的方法, 以下方法在GameLib源文件中**
1. 更改控制台标题(SetTitle)
2. 更改控制台内字体(SetColor)
3. 设置控制台内光标的位置(SetPosition)
  
### 更改控制台标题(SetTitle)
~~~
/** 设置控制台的标题 */
void SetTitle(char *title) {
    SetConsoleTitle(title);     //调用windows.h头文件下的系统函数
}
~~~
### 更改控制台内字体(SetColor)
~~~
/* 设置控制台的颜色
 * 0-黑色,   1-蓝色,   2-绿色,    3-浅绿色,  4-红色,
 * 5-紫色,   6-黄色,   7-白色,    8-灰色,   9-淡蓝色,
 * 10-淡绿色,  11-淡浅绿色   12-淡红色   13-淡紫色
 * 14-淡黄色   15-亮白色
 */
void SetColor(int ForeColor, int BackColor) {//分别设置前景色与背景色
     //HANDLE: 句柄, GetStdHandle(STD_OUTPUT_HANDLE)获得标准输出流的句柄, 均为windows.h下的系统函数
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);       //获取当前窗口句柄
     SetConsoleTextAttribute(handle, ForeColor + BackColor * 0x10);//设置颜色
   
    //句柄(HANDLE)补充:
    //WINDOWS程序中并不是用物理地址来标识一个内存块，文件，任务或动态装入模块的。
    //相反，WINDOWS API给这些项目分配确定的句柄并将句柄返回给应用程序，
    //然后通过句柄来进行操作(句柄不是指针, 是32或64位的无符号整型)
 }
~~~
### 设置控制台内光标的位置(SetPosition)
~~~
void SetPosition(int x, int y) {
     HANDLE winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos = {x, y};
     //SetConsoleCursorPosition()为windows.h下系统函数
     SetConsoleCursorPosition(winHandle, pos);      //设置光标位置
 }
~~~
***
**以下方法为自己定义实现游戏主要逻辑功能中比较重要的几个, 在Game源文件中**
1. **GameProcess():** 接收并判断用户的输入, 返回游戏的各个功能(例如用户输入方向键将会移动玩家的所在地图,输入1会显示玩家的个人信息窗口等等)这是游戏最重要的一个方法, 决定了游戏的逻辑实现, 本人水平较差, 当初没有想到将所有的操作均封装到此方法来, 因此使得判断用户输入包括方向键的接收为一个方法并且放入于main()中, 导致了维护困难, 代码不清晰等等问题 
2. **Clear():** 这是一个我使用的非常多的一个方法, 功能为清理指定区域内的所有字符, 用'\0'替代, 达到刷新屏幕的功能
3. **ShowMonster():** 该方法为显示
4. **MonsterFight():**
5. **PropInit():** 
6. **Trade():**
7. **ShowProps():**
8. **showTrade():**
9. **Login():**)
