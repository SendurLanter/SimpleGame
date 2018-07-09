#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <string>
using namespace std;
char board[40][20];                //initialize
int posx=20,posy=10;
int scene=0;
int posgx=7,posgy=7;
int cou=0;
char row1[]="  > 1 : 逃            2 : 逃          ";
char row2[]="    3 : 逃            4 : 裝死        ";

void nextroom(){
    for(int i=0;i<40;i++){
        for(int j=0;j<20;j++){
            if(j==0||j==19)
                board[i][j]='#';
            else if(posgx==i&&posgy==j ){
                board[i][j]='G';
            }
            else if((i==18||i==22)&&j>0&&j<4){
                board[i][j]='|';
            }
            else
                board[i][j]=' ';
            if(i==0||i==39)
                board[i][j]='#';
        }
    }
}

void iniroom(){
    for(int i=0;i<40;i++){
        for(int j=0;j<20;j++){
            if(j==0||j==19)
                board[i][j]='@';
            else
                board[i][j]=' ';
            if(i==0||i==39)
                board[i][j]='@';
            if((i==38||i==37||i==36||i==35) && (j==8||j==11))
                board[i][j]='=';
        }
    }

}

void showboard( int posx,int posy ){

    for(int y=0;y<20;y++){
        for(int x=0;x<40;x++){
            if(posgx==posx&&y==posgy-1&&x==posgx){
                    board[x][y]='!';
                    cout<<board[x][y];
                    board[x][y]=' ';
                }
            if(posx==x&&posy==y&&(scene==1||scene==0)){
                board[x][y]='A';
                cout<<board[x][y];
                board[x][y]=' ';
            }
            else
                cout<<board[x][y];

        }
        cout<<endl;
    }

}

void animate1(int posx, int posy){
    for(int i=17;i<22;i++){
        for(int j=1;j<19;j++){
            board[i][j]='>';
        }
    }
    system("CLS");
    showboard(posx,posy);
    getch();
}
void animate2(int posx,int posy){
    for(int i=12;i<27;i++){
        for(int j=1;j<19;j++){
            board[i][j]='<';
        }
    }
    system("CLS");
    showboard(posx,posy);
    getch();
}
void animate3(int posx,int posy){
    for(int i=7;i<32;i++){
        for(int j=1;j<19;j++){
            board[i][j]='>';
        }
    }
    system("CLS");
    showboard(posx,posy);
    getch();
}
void animate4(int posx,int posy){
    for(int i=1;i<39;i++){
        for(int j=1;j<19;j++){
            board[i][j]='<';
        }
    }
    system("CLS");
    showboard(posx,posy);
    getch();
}
                                            //顯示選項介面
void option(){

    for(int i=0;i<40;i++){
        for(int j=0;j<20;j++){
            if(j==19 || j==13)
                board[i][j]='-';
            else if(j<19&&j>13){
                if(j==15){
                    board[i][j]=row1[i];
                }

                else if(j==18){
                    board[i][j]=row2[i];
                }
                else
                    board[i][j]=' ';

                if(i==0||i==39)
                    board[i][j]='|';
            }
            else
                board[i][j]==' ';
        }
    }
}

void fightscene(int scene){

    for(int i=0;i<40;i++){
        for(int j=0;j<20;j++){
            if(j==19 || j==13)
                board[i][j]='-';
            else if(j<19&&j>13){

                if(i==0||i==39)
                    board[i][j]='|';
                else
                    board[i][j]=' ';
                if(j==15){
                    if(scene==5){
                        char note[]="    主人翁使用裝死 ！ 效果十分不顯著。  ";
                        board[i][j]=note[i];
                }
                    else if(scene==3){
                        char note[]="    草叢出現了野生的信號與系統！！      ";
                        board[i][j]=note[i];
                    }
                }
            }

            else
                board[i][j]=' ';

            if(i>25&&i<35){                      //敵
                if(j>1&&j<6)
                    board[i][j]='%';
            }
            if(i>2&&i<8){                        //玩家
                if(j>7&&j<11)
                    board[i][j]='$';
            }
        }
    }

}
void fightoption(int control){
    if(control==32){
        scene=5;
        fightscene(scene);
        system("CLS");
        showboard(posx,posy);
        getch();
        scene=1;
    }
    else if(control==122){
        row1[2]=' ';
        row1[20]='>';
    }
    else if(control==120){
        row1[20]=' ';
        row2[2]='>';
    }
    else if(control==99){
        row2[2]=' ';
        row2[20]='>';
    }

}


void up(){
    posy--;
}
void down(){
    posy++;
}
void left(){
    posx--;
}
void right(){
    posx++;
}

int main()
{
    unsigned seed;
    seed = (unsigned)time(NULL); // 取得時間序列
    srand(seed); // 以時間序列當亂數種子
    iniroom();
    showboard(13,20);
    while(1){
        int a=getch();
        switch(a){
            case 119:
                up();
                break;
            case 115:
                down();
                break;
            case 97:
                left();
                break;
            case 100:
                right();
                break;
            default:
                ;

        }
                                                //if 撞牆等
        if(posx==0){
            if(posy==10||posy==9){
                scene=0;
                posx=38;
            }
            else
                posx=1;
        }
        if(posx==39){
            if(posy==10 || posy==9){
                scene=1;
                posx=1;}
            else
                posx=38;
        }

        if(posy==19)
            posy=18;
        if(posy==0)
            posy=1;
                                                 //場景
        if(scene==1)
            nextroom();
        else if(scene==0)
            iniroom();
        else if(scene==2){
            animate1(posx,posy);
            animate2(posx,posy);
            animate3(posx,posy);
            animate4(posx,posy);
            scene=3;
        }
        else if(scene==3){
            fightscene(scene);
            scene=4;
        }
        else if(scene==4){
            fightoption(a);
            if(scene==1)
                continue;
            option();
        }

        system("CLS");
        showboard(posx,posy);
        if(posgx==posx)
            scene=2;

    }


    return 0;
}
