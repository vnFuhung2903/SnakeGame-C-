/*
 ▄▀▀▀█▄    ▄▀▀▄ ▄▀▀▄  ▄▀▀▄ ▄▄   ▄▀▀▄ ▄▀▀▄  ▄▀▀▄ ▀▄  ▄▀▀▀▀▄
█  ▄▀  ▀▄ █   █    █ █  █   ▄▀ █   █    █ █  █ █ █ █
▐ █▄▄▄▄   ▐  █    █  ▐  █▄▄▄█  ▐  █    █  ▐  █  ▀█ █    ▀▄▄
 █    ▐     █    █      █   █    █    █     █   █  █     █ █
 █           ▀▄▄▄▄▀    ▄▀  ▄▀     ▀▄▄▄▄▀  ▄▀   █   ▐▀▄▄▄▄▀ ▐
█                     █   █               █    ▐   ▐
▐                     ▐   ▐               ▐
*/

///----------------------------------------------------------DEFINING----------------------------------------------------------///

#include <bits/stdc++.h>
#include <conio.h>
#include "Snake.h"
#include "Food.h"

#define ll long long
//#define int long long
#define pi pair <int,int>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define pb push_back
#define fi first
#define se second
#define MASK(n) (1LL << n)
#define bit_check(x,i) (x & MASK(i))
#define bit_on(x,i) (x | MASK(i))
#define bit_off(x,i) (x & ~MASK(i))
#define HEIGHT 25
#define WIDTH 50
#define task "SnakeGame"

///----------------------------------------------------------VARIABLE----------------------------------------------------------///

using namespace std;
const int oo = 1e9, MOD = 1e9 + 7, maN = 1000 + 15;
int x = 10, y = 10;
bool gameover = 0;

///----------------------------------------------------------FUNCTION----------------------------------------------------------///

Snake MySnake({WIDTH/2, HEIGHT/2}, 1);
Food CurrentFood;

void CreatBoard()
{
    cout << "\n\n";
    COORD SnakePosition = MySnake.getPosition();
    COORD FoodPosition = CurrentFood.getPosition();
    deque <COORD> SnakeBody = MySnake.BodyCheck();
    FOR(i,0,HEIGHT - 1)
    {
        cout << "\t\t#";
        FOR(j,1,WIDTH - 2)
        {
            if(i == 0 || i == HEIGHT - 1) cout << '#';
            else if(i == SnakePosition.Y && j == SnakePosition.X)   cout << '0';
            else if(i == FoodPosition.Y && j == FoodPosition.X)     cout << '*';
            else
            {
                bool IsBodyPart = 0;
                FOR(k,0,SnakeBody.size() - 1)
                {
                    if(i == SnakeBody.at(k).Y && j == SnakeBody.at(k).X)
                    {
                        IsBodyPart = 1;
                        break;
                    }
                }
                if(IsBodyPart)  cout << 'o';
                else            cout << ' ';
            }
        }
        cout << "#\n";
    }
}

///----------------------------------------------------------MAIN----------------------------------------------------------///

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    srand(time(NULL));
    while(!gameover)
    {
        CreatBoard();
        if(kbhit())
        {
            switch(getch())
            {
                case 'w':
                    MySnake.changeDirection(-2);
                    break;
                case 'a':
                    MySnake.changeDirection(-1);
                    break;
                case 's':
                    MySnake.changeDirection(2);
                    break;
                case 'd':
                    MySnake.changeDirection(1);
                    break;
            }
        }
        MySnake.Move();
        if(MySnake.Eaten(CurrentFood.getPosition()))
        {
            CurrentFood.CreatFood();
            MySnake.Grow();
        }
        if(MySnake.Boom()) gameover = 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
}
/*
            ___           _                        __ _
           | __|  _  _   | |_     _  _    _ _     / _` |
   ___     | _|  | +| |  | ' \   | +| |  | ' \    \__, |   ___
  |UwU|   _|_|_   \_,_|  |_||_|   \_,_|  |_||_|   |___/   |UwU|
_|"""""|_| """ |_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'
*/
