#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Game.h"
#include "GameLib.h"

extern int X,Y;

int main() {//���ͨ��һ����Ϸ���̺�����main������ߵĸ��ַ�����װ, ͨ����ͬ״ִ̬�в�ͬ����
    char key;           //�����û�����
    SetColor(2,0);      //���ÿ���̨�ı���ɫ(front colorΪ��ɫ, background colorΪ��ɫ)
    SetConsoleTitle("Ц������֮���ұ��� C����ʵ�� BY ���ֹ���");    //���ÿ���̨����
    PropInit();         //��ʼ����������
    ShowWelcome();      //��ʾ��ӭ��
    ShowMap();          //��ʾ��ͼ
    ShowInformation();  //��ʾ��Ϣ��
    ShowMainMenu();     //��ʾ�˵���
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
        printf("�Ź��Ұ�, ��û��������!!!\n");
    }
    else if(key == '7') {
        break;
    }
    else if(key == VK_UP || key == 72) {
        Y--;            //������
    }
    else if(key == VK_RIGHT || key == 77) {
        X++;            //������
    }
    else if(key == VK_DOWN || key == 80) {
        Y++;            //������
    }
    else if(key == VK_LEFT || key == 75) {
        X--;            //������
    }
    if(X > 7) {//�ƶ�����ߵĻ����»ص�0, ��̰ʳ�ߴ�����ͼ��Ե
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
