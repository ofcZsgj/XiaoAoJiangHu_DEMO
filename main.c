#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "GameLib.h"

int main() {
    SetColor(2,0);
    SetConsoleTitle("Ц������֮���ұ��� C����ʵ�� BY ���ֹ���");
    ShowWelcome();
    ShowMap();
    ShowInformation();
    ShowMainMenu();
    return 0;
}
