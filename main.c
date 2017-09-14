#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
int checkwin();
void board();
char square[10]={'0','1','2','3','4','5','6','7','8','9'};
COORD coord ={0,0}; //sets coordinates to (0,0).
void gotoxy(int x, int y) //function used to manipulate the user prompt on the screen.
{
    coord.X=x; coord.Y=y; //x and y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    int player=1,choice,i;
    char mark;
    do
    {
        board();
        if(player%2==0)
            player=2;
            else
            player=1;
            gotoxy(30,17);
            printf("Player %d enter your choice: ",player);
            if(player==1)
                mark='0';
            else
                mark='X';
            gotoxy(60,17);
            scanf("%d",&choice);

             if(choice==1 && square[1]=='1')
                square[1]=mark;
            else if(choice==2 && square[2]=='2')
                square[2]=mark;
            else if(choice==3 && square[3]=='3')
                square[3]=mark;
            else if(choice==4 && square[4]=='4')
                square[4]=mark;
            else if(choice==5 && square[5]=='5')
                square[5]=mark;
            else if(choice==6 && square[6]=='6')
                square[6]=mark;
            else if(choice==7 && square[7]=='7')
                square[7]=mark;
            else if(choice==8 && square[8]=='8')
                square[8]=mark;
            else if (choice==9 && square[9]=='9')
                square[9]=mark;
            else
                {
                    gotoxy(30,18);
                    printf("Invalid Move\n\n");
                    player++;
                    continue;
                }

            i=checkwin();
            player++;
        }while(i==-1);
        board();
    if(i==1)
        {gotoxy(30,20);
        printf("Player %d wins !!\n \n \n",--player);}
    if(i==0)
        {gotoxy(30,20);
        printf("Game Draw\n\n");}
        choice=IGNORE;
        return 0;
}
void board()
{
    system("cls");
    gotoxy(30,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TIC TAC TOE GAME \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30,5);
    printf("Player 1 = 0        Player 2 = X");
    gotoxy(38,6);
    printf("-------------------");
    gotoxy(38,7);
    printf("|     |     |     |");
    gotoxy(38,8);
    printf("|  %c  |  %c  |  %c  |",square[1],square[2],square[3]);
    gotoxy(38,9);
    printf("|_____|_____|_____|");

    gotoxy(38,10);
    printf("|     |     |     |");
    gotoxy(38,11);
    printf("|  %c  |  %c  |  %c  |",square[4],square[5],square[6]);
    gotoxy(38,12);
    printf("|_____|_____|_____|");

    gotoxy(38,13);
    printf("|     |     |     |");
    gotoxy(38,14);
    printf("|  %c  |  %c  |  %c  |",square[7],square[8],square[9]);
    gotoxy(38,15);
    printf("|     |     |     |");
    gotoxy(38,16);
    printf("-------------------");
}
int checkwin()
{
    if(square[1]==square[2] && square[2]==square[3])
        return 1;
    else if(square[4]==square[5] && square[5]==square[6])
        return 1;
    else if(square[7]==square[8] && square[8]==square[9])
        return 1;
    else if(square[1]==square[4] && square[4]==square[7])
        return 1;
    else if(square[2]==square[5] && square[5]==square[8])
        return 1;
    else if(square[3]==square[6] && square[6]==square[9])
        return 1;
    else if(square[1]==square[5] && square[5]==square[9])
        return 1;
    else if(square[3]==square[5] && square[5]==square[7])
        return 1;
    else if(square[1]!='1'&&square[2]!='2'&&square[3]!='3'
            &&square[4]!='4'&&square[5]!='5'&&square[6]!='6'
            &&square[7]!='7'&&square[8]!='8'&&square[9]!='9')
        return 0;
    else
        return -1;
}

