#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "GameLib.h"

int main() {
    SetColor(2,0);
    SetConsoleTitle("笑傲江湖之精忠报国 C语言实现 BY 左手工匠");
    ShowWelcome();
    ShowMap();
    ShowInformation();
    ShowMainMenu();
    return 0;
}
