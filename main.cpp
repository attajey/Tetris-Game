#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<windows.h>
#include <cstdlib>
#include <time.h>




const int BOARD_MAX_WIDTH=40;
const int BOARD_MAX_HEIGHT=20;



using namespace std;


bool Shapes[4][4][4][4]
    {

        {//I
            {
            {0,0,0,1},
            {0,0,0,1},
            {0,0,0,1},
            {0,0,0,1}
            },
            {
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0}
            },
            {
            {0,0,0,1},
            {0,0,0,1},
            {0,0,0,1},
            {0,0,0,1}
            },
            {
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0}
            }
        },
        {//L
            {
            {0,0,1,0},
            {0,0,1,0},
            {0,0,1,1},
            {0,0,0,0}
            },
            {
            {0,0,0,0},
            {0,1,1,1},
            {0,1,0,0},
            {0,0,0,0}
            },
            {
            {0,0,0,0},
            {0,0,1,1},
            {0,0,0,1},
            {0,0,0,1}
            },
            {
            {0,0,0,0},
            {0,0,0,1},
            {0,1,1,1},
            {0,0,0,0}
            }
        },
        {//N
            {
            {0,0,0,0},
            {0,1,1,0},
            {0,0,1,1},
            {0,0,0,0}
            },
            {
            {0,0,0,1},
            {0,0,1,1},
            {0,0,1,0},
            {0,0,0,0}
            },
            {
            {0,0,0,0},
            {0,1,1,0},
            {0,0,1,1},
            {0,0,0,0}
            },
            {
            {0,0,0,1},
            {0,0,1,1},
            {0,0,1,0},
            {0,0,0,0}
            },

        },
        {//Square
          {
            {0,0,0,0},
            {0,0,1,1},
            {0,0,1,1},
            {0,0,0,0}
          },
          {
            {0,0,0,0},
            {0,0,1,1},
            {0,0,1,1},
            {0,0,0,0}
          },
          {
            {0,0,0,0},
            {0,0,1,1},
            {0,0,1,1},
            {0,0,0,0}
          },
          {
            {0,0,0,0},
            {0,0,1,1},
            {0,0,1,1},
            {0,0,0,0}
          },
        }
};


void gotoxy(int x,int y)
 {
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

 }


 void setColor(int ForgC)
{
     WORD wColor;
                          //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                     //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


void printMargin(bool **board)
{
    setColor(0);
    char bl=219;
     for(int i=0;i<=BOARD_MAX_WIDTH;i++)
    {
        gotoxy(i,0);
        cout<<bl;
        gotoxy(i,21);
        cout<<bl;
        board[0][i]=bl;
        board[21][i]=bl;
    }
    for(int j=0;j<=BOARD_MAX_HEIGHT+1;j++)
    {
        gotoxy(41,j);
        cout<<bl;
        board[j][41]=bl;
    }

}


void printShape(bool a[4][4][4][4],int kind ,int rotation,int x,int y,bool **board)
 {
     int temp=x;
     int temp2=y;
     char bl=254;
     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {
             if(a[kind][rotation][i][j]==1)
             {
                cout<<bl;
                board[y][x]=1;


             }
            x+=1;
            gotoxy(x,y);
         }
        y++;
        x=temp;
        gotoxy(x,y);
     }
     y=temp2;
 }


 void deleteShape(bool a[4][4][4][4],int kind ,int rotation,int x,int y,bool **board)
 {
     int temp=x;
     int temp2=y;
     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {
             if(a[kind][rotation][i][j]==1)
             {
                cout<<" ";
                board[y][x]=0;
             }
            x+=1;
            gotoxy(x,y);
         }
        y++;
        x=temp;
        gotoxy(x,y);
     }
    y=temp2;

 }


 void gameExit()
{
    system("cls");
    gotoxy(10,10);
    cout<<"********** OUCH !!  **********" ;
    Sleep( 1500);
    system("cls");
    char sound=7;
    setColor(0);//rand()%15);
    for(int i=0,j=0;j<20,i<40;i++,j++)
    {
        gotoxy(i,j);
        cout<<"**********LOSER***********";
        gotoxy(i,j+2);
        cout<<"*******Game is Over*******";
        setColor(0);
        Sleep(50);
        system("cls");

    }
    gotoxy(20,20);
    cout<<"**********LOSER***********";
    gotoxy(20,22);
    cout<<"*******Game is Over*******";

    /*gotoxy(20,10);
    cout<<"**********LOSER***********";
    gotoxy(20,12);
    cout<<"*******Game is Over*******";
    Sleep(800);
    system("cls");
    gotoxy(2,1);
    cout<<"**********LOSER***********";
    gotoxy(2,3);
    cout<<"*******Game is Over*******";
    Sleep(800);
    system("cls");
    gotoxy(20,20);
    cout<<"**********LOSER***********";
    gotoxy(20,22);
    cout<<"*******Game is Over*******";
    cout<<sound<<sound;
    Sleep(500);
    cout<<sound; */
    getch();
    exit(1);
}


 bool checkFree(bool a[4][4][4][4],int kind , int rotation , int x , int y , bool **board)
 {
     if(kind==0)
     {
         if((rotation==0)||(rotation==2))
         {
             if((board[y][x+4]==0)&&(board[y+1][x+4]==0)&&(board[y+2][x+4]==0)&&(board[y+3][x+4]==0))
                return true;
             else
                return false;
         }
         if((rotation==1)||(rotation==3))
         {
             if(board[y+1][x+4]==0)
                return true;
             else
                return false;
         }

     }
     if(kind==1)
     {
         if(rotation==0)
         {
            if(board[y+2][x+4]==0)
            {
                if((board[y][x+3]==0)&&(board[y+1][x+3]==0))
                    return true;
             else
                return false;
            }
            else
                return false;
         }
         if(rotation==1)
         {
             if(board[y+1][x+4]==0)
             {
                 if(board[y+2][x+3]==0)
                 {
                    // if(board[y+2][x+2]==0)
                       return true;
                 }
             else
                return false;
                 }

             else
                return false;
         }
         if(rotation==2)
         {
             if((board[y+1][x+4]==0)&&(board[y+2][x+4]==0)&&(board[y+3][x+4]==0))
                return true;
             else
                return false;
         }
         if(rotation==3)
         {
             if((board[y+1][x+4]==0)&&(board[y+2][x+4]==0))
                return true;
             else
                return false;
         }
     }
     if(kind==2)
     {
         if((rotation==0)||(rotation==2))
         {
            if(board[y+2][x+4]==0)
            {
                if(board[y+1][x+3]==0)
                    return true;
             else
                return false;
            }
            else
                return false;
        }
        if((rotation==1)||(rotation==3))
        {
            if((board[y][x+4]==0)&&(board[y+1][x+4]==0))
            {
                if(board[y+2][x+3]==0)
                    return true;
             else
                return false;
            }
            else
                return false;
        }
      }
     if(kind==3)
     {
         if((rotation==0)||(rotation==1)||(rotation==2)||(rotation==3))
         {
             if((board[y+1][x+4]==0)&&(board[y+2][x+4]==0))
                return true;
             else if((board[y][1]==1)||(board[y][2]==1)|(board[y][3]==1)||(board[y][4]==1))
             {
              //  Sleep(5000);
                gameExit();
             }
             else
                return false;
         }
     }


}


void gameHeadStart( )
{
    setColor(6);
    char sound=7;
    char pointer=175;
    gotoxy(20,10);
    cout<<" ---------->  WELCOME  <----------";
    Sleep(2000);
    system("cls");
    gotoxy(0,0);
    cout<<pointer<<"  This is the Tetris game made by -> ATTA JIROFTY <- "<<endl;
    Sleep(1000);
    gotoxy(0,3);
    cout<<pointer<<"  This game is protected by ** Copyright ( C ) **"<<endl;
    Sleep(1000);
    gotoxy(0,6);
    cout<<pointer<<"  Please press a key to start the game."<<endl;
    getch();
    gotoxy(0,8);
    cout<<"************************GET READY************************"<<endl;
    gotoxy(10,10);
    cout<<'1'<<sound<<endl;
    Sleep(1000);
    gotoxy(10,12);
    cout<<'2'<<sound<<endl;
    Sleep(1000);
    gotoxy(10,14);
    cout<<'3'<<sound<<endl;
    Sleep(1000);
    cout<<sound<<sound<<sound;
    system("cls");
    gotoxy(20,10);
    cout<<"***************   -> GO GO GO <-   ***************";
    Sleep(1000);
}


void gameHelp()
{
    char pointer=175;
    char design=178;
     gotoxy(43,0);
    cout<<pointer<<"  Use 'W' key for up";
    gotoxy(43,1);
    cout<<pointer<<"  Use 'S' key for down";
    gotoxy(43,2);
    cout<<pointer<<"  Use 'D' key for fast-forward";
    gotoxy(43,3);
    cout<<pointer<<"  Use 'Enter' for Ending the game";
    gotoxy(43,4);
    cout<<pointer<<"  Use 'Space' for rotation " ;
    gotoxy(43,7);
    cout<<design<<"  ENJOY THE GAME  "<<design;
    gotoxy(0,23);
    cout<<"Made in Yazd University - Computer Engineering Faculty ";
}



void nextShape(int kind , int rotation,bool **board )
{
    gotoxy(43,10);
    int x=43;
    int y=10;
    printShape(Shapes,kind,rotation,x,y,board);
}


void nextShapeDelete(int kind , int rotation,bool **board )
{
    gotoxy(43,10);
    int x=43;
    int y=10;
    deleteShape(Shapes,kind,rotation,x,y,board);
}


bool gameIsOver(int x,int y,bool **board)
{
   return false;
  /* int count_bl;
    for(int i=1;i<=BOARD_MAX_HEIGHT;i++)
    {
        for(int j=0;j<=BOARD_MAX_WIDTH;j++)
        {
            if(board[i][j]==1)
                count_bl++;
            if(count_bl==20)
                return true;
            else
            {
                 count_bl=0;
                continue;
            }

        }
    }
    return false; */
}



void levelPrint ( int score )
{
    char sound=7;
    if(score<200)
    {
        gotoxy(43,12);
        cout<<"LEVEL 1";
    }
    if(score>200)
    {
        gotoxy(43 ,12);
        cout<<"LEVEL 2   ";
    }
     if (score>500)
    {
        gotoxy(43,12);
        cout<<"LEVEL 3   ";
    }
     if (score>800)
    {
        gotoxy(43,12);
        cout<<"LEVEL 4    BRAVO!! ";
    }

}

int main()
{
    char ch1=0;
     gameHeadStart();
    bool is_free=true;
    bool is_over=false;
    int score=0;
    int sleep_time=100;
    int fst=10;
    system("cls");
    bool **board=new bool *[BOARD_MAX_HEIGHT+1];
    for(int i=0;i<=BOARD_MAX_WIDTH+1;i++)
       board[i]=new bool[BOARD_MAX_WIDTH+1];
    for(int i=0;i<=BOARD_MAX_HEIGHT+1;i++)
    {
        for(int j=0;j<=BOARD_MAX_WIDTH+1;j++)
            board[i][j]=0;
    }
    printMargin(board);
    gameHelp();
    system ("color 5e");


    while(true)
    {
        int srand(100);
        gotoxy(43,10);
        cout<<"SCORE :  "<<score;
        if(score>200)
            sleep_time=  70;
        if (score>500)
            sleep_time=  40;
        if (score>800)
            sleep_time=  30;
        levelPrint(score);
        setColor(rand()%15);
        int x=0,y=rand()%20;
        if(y==16)
            y--;
        if(y==17)
            y-=2;
        if(y==18)
            y-=3;
        if(y==19)
            y-=4;
        else
            y++;
        int kind=rand()%4;
        int rotation=rand()%4;
        printShape(Shapes,kind,rotation,x,y,board);
        while(x<BOARD_MAX_WIDTH)
        {
            Sleep(sleep_time) ;
            deleteShape (Shapes , kind , rotation , x , y,board) ;
            is_free=checkFree(Shapes,kind,rotation,x,y,board) ;
            is_over=gameIsOver(x,y,board);
            if(is_over==true)
                gameExit();
            if((is_free==true)&&(x!=BOARD_MAX_WIDTH))
                {
                    x ++ ;
                    printShape (Shapes , kind , rotation , x , y,board) ;
                    score++;
                }
                else
                {
                    printShape (Shapes , kind , rotation , x , y,board) ;
                    break;
                }
            if (ch1==13)//'enter' key for exit
                gameExit();

            if (_kbhit())
            {
                ch1 =_getch() ;
                if (ch1 == 32)// 'space'  key for rotation
                {
                    Sleep(sleep_time) ;
                    deleteShape (Shapes , kind , rotation , x , y,board) ;
                    if (rotation == 3 )
                        rotation = 0 ;
                    else
                        rotation++ ;
                    is_free=checkFree(Shapes,kind,rotation,x,y,board);
                    is_over=gameIsOver(x,y,board);
                    if(is_over==true)
                        gameExit();
                    if((is_free==true)&&(x!=BOARD_MAX_WIDTH))
                    {
                        x ++ ;
                        printShape (Shapes , kind , rotation , x , y,board) ;
                        score++;
                    }
                    else
                    {
                        printShape (Shapes , kind , rotation , x , y,board) ;
                        break;
                    }
                }
                if (ch1==13)// 'enter'  key for exit
                    gameExit();
                if (ch1==119)//  'w' key for up
                {
                    if(y==0)
                        continue;
                    if(((kind==1)&&(rotation==0))||((kind==0)&&(rotation==0))||((kind==0)&&(rotation==2))||((kind==2)&&(rotation==1))||((kind==2)&&(rotation==3)))
                    {
                        if(y==1)
                            continue;
                    }
                    Sleep(sleep_time);
                    deleteShape(Shapes,kind,rotation,x,y,board);
                    is_free=checkFree(Shapes,kind,rotation,x,y,board);
                    is_over=gameIsOver(x,y,board);
                    if(is_over==true)
                        gameExit();
                    if((is_free==true)&&(x!=BOARD_MAX_WIDTH))
                    {
                        y--;
                        x++;
                        printShape(Shapes,kind,rotation,x,y,board);
                        score++;
                    }
                    else
                    {
                        printShape (Shapes , kind , rotation , x , y,board) ;
                        break;
                    }
                }
                if(ch1==115)// 's' key for down
                {
                    if(y==18)
                        continue;
                    if(((kind==1)&&(rotation==2))||((kind==0)&&(rotation==0))||((kind==0)&&(rotation==2)))
                    {
                        if(y==17)
                            continue;
                    }
                    Sleep(sleep_time);
                    deleteShape(Shapes,kind,rotation,x,y,board);
                    is_free=checkFree(Shapes,kind,rotation,x,y,board);
                    is_over=gameIsOver(x,y,board);
                    if(is_over==true)
                        gameExit();
                    if(is_free==true)
                    {
                        y++;
                        x++;
                        printShape(Shapes,kind,rotation,x,y,board);
                        score++;
                    }
                    else
                    {
                        printShape (Shapes , kind , rotation , x , y,board) ;
                        break;
                    }
                }
                if(ch1==100)// 'd' key for right
                {
                    while(is_free==true)
                    {
                        Sleep(fst);
                        deleteShape(Shapes,kind,rotation,x,y,board);
                        is_free=checkFree(Shapes,kind,rotation,x,y,board);
                        is_over=gameIsOver(x,y,board);
                        if(is_over==true)
                            gameExit();
                        if((is_free==true)&&(x!=BOARD_MAX_WIDTH))
                        {
                            Sleep(fst) ;
                            deleteShape (Shapes , kind , rotation , x , y,board) ;
                            is_free=checkFree(Shapes,kind,rotation,x,y,board);
                            is_over=gameIsOver(x,y,board);
                            if(is_over==true)
                                gameExit();
                            if((is_free==true)&&(x!=BOARD_MAX_WIDTH))
                            {
                                x ++ ;
                                printShape (Shapes , kind , rotation , x , y,board) ;
                                score++;
                            }
                            else
                            {
                            printShape (Shapes , kind , rotation , x , y,board) ;
                                break;
                            }
                        }
                    }
                }
            }
        }

    }
  return 0;

}

