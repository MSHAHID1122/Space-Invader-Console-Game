#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using namespace std;
// maze of space invaders
int const y = 71;
char field[25][y] = {
    {"######################################################################"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"|                                                                    |"},
    {"######################################################################"}};

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void menu1()
{
    cout << "1. PLAY GAME" << endl;
}
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()

int crafth_x = 21;
int crafth_y = 27;
int craftb_x1 = 22;
int craftb_y1 = 25;
int craftb_x2 = 22;
int craftb_y2 = 26;
int craftb_x3 = 22;
int craftb_y3 = 27;
int craftb_x4 = 22;
int craftb_y4 = 28;
int craftb_x5 = 22;
int craftb_y5 = 29;

int enemyh_x = 2;
int enemyh_y = 27;
int enemyb_x1 = 1;
int enemyb_y1 = 25;
int enemyb_x2 = 1;
int enemyb_y2 = 26;
int enemyb_x3 = 1;
int enemyb_y3 = 27;
int enemyb_x4 = 1;
int enemyb_y4 = 28;
int enemyb_x5 = 1;
int enemyb_y5 = 29;
int bullet1_x = 0;
int bullet1_y = 0;
int bullet2_x = 0;
int bullet2_y = 0;
int bullet3_x = 0;
int bullet3_y = 0;
int bullet4_x = 0;
int bullet4_y = 0;

// FUNCTIONS PROTOTYEPS
void battle_field();
void move_ship_left();
void move_ship_right();
void move_enemy_right();
void move_enemy_left();
int score = 0;
// void moveBullet();
int fire_count = 0;
int main()
{
    int option1;
    cout << "SSSSSSSSSS   SSSSSSS      SS       SSSSSS    SSSSSSSSS    SS         SS      SS      SSSSSSS " << endl;
    Sleep(1000);
    cout << "SS           SS   SS     SS SS     SS        SS           SS         SS     SS SS    SS   SS  " << endl;
    Sleep(1000);
    cout << "SSSSSSSSSS   SSSSSSS    SS   SS    SS        SSSSSSSSS    SS   SS    SS    SS   SS   SSSSSSS   " << endl;
    Sleep(1000);
    cout << "        SS   SS        SSSSSSSSS   SS        SS           SS SS   SS SS   SSSSSSSSS  SS SS      " << endl;
    Sleep(1000);
    cout << "SSSSSSSSSS   SS       SS       SS  SSSSSSS   SSSSSSSSS    SSSS     SSSS  SS       SS SS   SSS    " << endl;

    while (true)
    {
        system("cls");
        menu1();
        cin >> option1;
        if (option1 == 1)
        {
            system("cls");
            battle_field();

            while (true)
            {

                // bullets
                if (bullet1_x > 0)
                {
                    if (field[bullet1_x + 1][bullet1_y] != '#')
                    {
                        field[bullet1_x + 1][bullet1_y] = '@';
                        gotoxy(bullet1_y, bullet1_x + 1);
                        SetConsoleTextAttribute(console, 4);
                        cout << '@';

                        field[bullet1_x][bullet1_y] = '@';
                        gotoxy(bullet1_y, bullet1_x);
                        cout << ' ';
                        bullet1_x = bullet1_x + 1;
                    }
                    else if (field[bullet1_x + 1][bullet1_y] == '#')
                    {
                        field[bullet1_x][bullet1_y] = ' ';
                        gotoxy(bullet1_y, bullet1_x);
                        cout << ' ';
                        bullet1_x = 0;
                        bullet1_y = 0;
                    }
                }
                if (bullet2_x > 0)
                {
                    if (field[bullet2_x + 1][bullet2_y] != '#')
                    {

                        gotoxy(bullet2_y, bullet2_x + 1);
                        SetConsoleTextAttribute(console, 4);
                        cout << '@';

                        gotoxy(bullet2_y, bullet2_x);
                        cout << ' ';
                        bullet2_x = bullet2_x + 1;
                    }
                    else if (field[bullet2_x + 1][bullet2_y] == '#')
                    {
                        gotoxy(bullet2_y, bullet2_x);
                        cout << ' ';
                        bullet2_x = 0;
                        bullet2_y = 0;
                    }
                }

                Sleep(1);
                for (int i = 0; i < 24; i++)
                {
                    for (int j = 0; j < 71; j++)
                    {
                        if (field[i][j] == '*' && field[i - 1][j] != '#')
                        {
                            if (field[i - 1][j] == '+')
                            {
                                score = score + 1;
                            }
                            else if (field[i - 1][j] == '>' || field[i - 1][j] == '<')
                            {
                                score++;
                                if (score < 0)
                                {
                                    system("cls");
                                    gotoxy(80, 25);
                                    cout << score;
                                    return 0;
                                }
                            }
                            gotoxy(89, 10);
                            cout << score;
                            fire_count = fire_count + 1;
                            field[i - 1][j] = '*';
                            gotoxy(j, i - 1);
                            SetConsoleTextAttribute(console, 4);
                            cout << '*';

                            field[i][j] = ' ';
                            gotoxy(j, i);
                            cout << ' ';
                        }
                        else if (field[i - 1][j] == '#')
                        {
                            field[i][j] = ' ';
                            gotoxy(j, i);
                            cout << ' ';
                        }
                    }
                    cout << endl;
                }
                srand(time(0));
                int k = rand() % 10;

                if (enemyb_y5 == 1)
                {

                    move_enemy_right();
                }
                else if (enemyb_y5 >= 67)
                {

                    move_enemy_left();
                    if (bullet2_x = 0)
                    {
                        bullet2_x = enemyh_x + 1;
                        bullet2_y = enemyh_y;
                        gotoxy(bullet2_y, bullet2_x);
                        cout << '@';
                        field[bullet2_x][bullet2_y] = '@';
                    }
                }
                else if (k > 5 && enemyb_y5 > 1)
                {

                    move_enemy_left();
                }
                else if (k < 3 && enemyb_y5 < 67)
                    move_enemy_right();

                if (GetAsyncKeyState(VK_LEFT))
                {

                    move_ship_left();
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    move_enemy_right();
                    move_ship_right();
                    if (bullet1_x = 0)
                    {
                        bullet1_x = enemyh_x + 1;
                        bullet1_y = enemyh_y;
                        gotoxy(bullet1_y, bullet1_x);
                        cout << '@';
                        field[bullet1_x][bullet1_y] = '@';
                    }
                }

                if (GetAsyncKeyState(VK_UP))
                {
                    if (fire_count < 6)
                    {
                        int fire_x = crafth_x - 1;
                        int fire_y = crafth_y;
                        field[fire_x][fire_y] = '*';
                        gotoxy(fire_y, fire_x);
                        cout << '*';
                    }
                    fire_count = 0;
                }
            }
        }
        else if (option1 == 2)
        {
            cout << "no highscore" << " Click any key to continue playing Game" << endl;
            cin.get();
        }
    }
}

// END OF MAIN FUCTION

// FUNCTION DEFINTIONS

// void moveBullet()
// {
//     if(field[bx+1][by]!='#'){
//     gotoxy(by,bx);
//     cout << " ";
//     bx = bx + 1;
//     gotoxy(by,bx);
//     cout << "&";
//     }
// }
void move_ship_left()
{
    if (craftb_y1 > 1)
    {
        gotoxy(crafth_y, crafth_x);
        cout << ' ';
        gotoxy(crafth_y - 1, crafth_x);
        SetConsoleTextAttribute(console, 7);
        cout << '^';
        crafth_y = crafth_y - 1;
        gotoxy(craftb_y1, craftb_x1);
        cout << ' ';
        gotoxy(craftb_y1 - 1, craftb_x1);
        SetConsoleTextAttribute(console, 7);
        cout << '<';
        craftb_y1 = craftb_y1 - 1;
        gotoxy(craftb_y2, craftb_x2);
        cout << ' ';
        gotoxy(craftb_y2 - 1, craftb_x2);
        SetConsoleTextAttribute(console, 7);

        cout << '<';
        craftb_y2 = craftb_y2 - 1;
        gotoxy(craftb_y3, craftb_x3);
        cout << ' ';
        gotoxy(craftb_y3 - 1, craftb_x3);
        SetConsoleTextAttribute(console, 7);
        cout << '!';
        craftb_y3 = craftb_y3 - 1;
        gotoxy(craftb_y4, craftb_x4);
        cout << ' ';
        gotoxy(craftb_y4 - 1, craftb_x4);
        SetConsoleTextAttribute(console, 7);
        cout << '>';
        craftb_y4 = craftb_y4 - 1;
        gotoxy(craftb_y5, craftb_x5);
        cout << ' ';
        gotoxy(craftb_y5 - 1, craftb_x5);
        SetConsoleTextAttribute(console, 7);
        cout << '>';
        craftb_y5 = craftb_y5 - 1;
    }
}
void move_ship_right()
{
    if (craftb_y5 < 69)
    {
        gotoxy(crafth_y, crafth_x);
        cout << ' ';
        gotoxy(crafth_y + 1, crafth_x);
        SetConsoleTextAttribute(console, 7);
        cout << '^';
        crafth_y = crafth_y + 1;
        gotoxy(craftb_y5, craftb_x5);
        cout << ' ';
        gotoxy(craftb_y5 + 1, craftb_x5);
        SetConsoleTextAttribute(console, 7);
        cout << '>';
        craftb_y5 = craftb_y5 + 1;
        gotoxy(craftb_y4, craftb_x4);
        cout << ' ';
        gotoxy(craftb_y4 + 1, craftb_x4);
        SetConsoleTextAttribute(console, 7);
        cout << '>';
        craftb_y4 = craftb_y4 + 1;

        gotoxy(craftb_y3, craftb_x3);
        cout << ' ';
        gotoxy(craftb_y3 + 1, craftb_x3);
        SetConsoleTextAttribute(console, 7);
        cout << '!';
        craftb_y3 = craftb_y3 + 1;
        gotoxy(craftb_y2, craftb_x2);
        cout << ' ';
        gotoxy(craftb_y2 + 1, craftb_x2);
        SetConsoleTextAttribute(console, 7);
        cout << '<';
        craftb_y2 = craftb_y2 + 1;
        gotoxy(craftb_y1, craftb_x1);
        cout << ' ';
        gotoxy(craftb_y1 + 1, craftb_x1);
        SetConsoleTextAttribute(console, 7);
        cout << '<';
        craftb_y1 = craftb_y1 + 1;
    }
}
void battle_field()
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 71; j++)
        {
            if (field[i][j] == ' ')
            {
                cout << field[i][j];
            }
            else if (field[i][j] == '#' || field[i][j] == '|')
            {
                SetConsoleTextAttribute(console, 6);
                cout << field[i][j];
            }
        }
        cout << endl;
    }
}
void move_enemy_right()
{

    if (enemyb_y5 < 69)
    {
        gotoxy(enemyh_y, enemyh_x);
        cout << ' ';
        gotoxy(enemyh_y + 1, enemyh_x);
        SetConsoleTextAttribute(console, 7);
        cout << '+';
        enemyh_y = enemyh_y + 1;
        gotoxy(enemyb_y5, enemyb_x5);
        cout << ' ';
        gotoxy(enemyb_y5 + 1, enemyb_x5);
        SetConsoleTextAttribute(console, 7);
        cout << '>';
        enemyb_y5 = enemyb_y5 + 1;
        gotoxy(enemyb_y4, enemyb_x4);
        cout << ' ';
        gotoxy(enemyb_y4 + 1, enemyb_x4);
        SetConsoleTextAttribute(console, 7);
        cout << '>';
        enemyb_y4 = enemyb_y4 + 1;
        gotoxy(enemyb_y3, enemyb_x3);
        cout << ' ';
        gotoxy(enemyb_y3 + 1, enemyb_x3);
        SetConsoleTextAttribute(console, 7);
        cout << '!';
        enemyb_y3 = enemyb_y3 + 1;
        gotoxy(enemyb_y2, enemyb_x2);
        cout << ' ';
        gotoxy(enemyb_y2 + 1, enemyb_x2);
        SetConsoleTextAttribute(console, 7);
        cout << '<';
        enemyb_y2 = enemyb_y2 + 1;
        gotoxy(enemyb_y1, enemyb_x1);
        cout << ' ';
        gotoxy(enemyb_y1 + 1, enemyb_x1);
        SetConsoleTextAttribute(console, 7);
        cout << '<';
        enemyb_y1 = enemyb_y1 + 1;
    }
}
void move_enemy_left()
{
    if (enemyb_y1 > 1)
    {
        gotoxy(enemyh_y, enemyh_x);
        cout << ' ';
        gotoxy(enemyh_y - 1, enemyh_x);
        cout << '+';
        enemyh_y = enemyh_y - 1;
        gotoxy(enemyb_y1, enemyb_x1);
        cout << ' ';
        gotoxy(enemyb_y1 - 1, enemyb_x1);
        cout << '<';
        enemyb_y1 = enemyb_y1 - 1;
        gotoxy(enemyb_y2, enemyb_x2);
        cout << ' ';
        gotoxy(enemyb_y2 - 1, enemyb_x2);
        cout << '<';
        enemyb_y2 = enemyb_y2 - 1;
        gotoxy(enemyb_y3, enemyb_x3);
        cout << ' ';
        gotoxy(enemyb_y3 - 1, enemyb_x3);
        cout << '!';
        enemyb_y3 = enemyb_y3 - 1;
        gotoxy(enemyb_y4, enemyb_x4);
        cout << ' ';
        gotoxy(enemyb_y4 - 1, enemyb_x4);
        cout << '>';
        enemyb_y4 = enemyb_y4 - 1;
        gotoxy(enemyb_y5, enemyb_x5);
        cout << ' ';
        gotoxy(enemyb_y5 - 1, enemyb_x5);
        cout << '>';
        enemyb_y5 = enemyb_y5 - 1;
    }
}
