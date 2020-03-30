#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include <time.h>
#include <stdio.h>

using namespace std;
static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

bool inGame = false;
int x, y, p1pos = 3, p2pos = 3;
enum Direction {UPUPUPLEFT, UPUPLEFT, UPLEFT, LEFT, DOWNLEFT, DOWNDOWNLEFT, DOWNDOWNDOWNLEFT, UPUPUPRIGHT, UPUPRIGHT, UPRIGHT, RIGHT, DOWNRIGHT, DOWNDOWNRIGHT, DOWNDOWNDOWNRIGHT};
Direction dir;
const int width = 60;
const int height = 20;

void setCursorPosition(int x, int y) {
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}
void Initialize() {
    system("CLS");
    SetConsoleTextAttribute(hOut, 8);
    srand(time(NULL));
    inGame = true;
    x = width / 2;
    y = height / 2;
    dir = (Direction)(rand() % 13);
}
void Draw() {
    setCursorPosition(0, 0);
    for (int i = 0; i < width; i++) {SetConsoleTextAttribute(hOut, 8); cout << '#';}
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width-1) {SetConsoleTextAttribute(hOut, 8); cout << '#';}
            else if ((j == 1 && (i == p1pos || i == p1pos+1 || i == p1pos+2)) || (j == width-2 && (i == p2pos || i == p2pos+1 || i == p2pos+2))) {SetConsoleTextAttribute(hOut, 11); cout << '|';}
            else if (j == x && i == y) {SetConsoleTextAttribute(hOut, 10); cout << 'o';}
            else cout << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++) {SetConsoleTextAttribute(hOut, 8); cout << '#';}
}
void Input() {
    if (GetKeyState('W') & 0x8000) p1pos -= 1;
    if (GetKeyState('S') & 0x8000) p1pos += 1;
    if (GetKeyState(VK_UP) & 0x8000) p2pos -= 1;
    if (GetKeyState(VK_DOWN) & 0x8000) p2pos += 1;
    if (p1pos+3 >= height) p1pos = height-3;
    if (p1pos < 0) p1pos = 0;
    if (p2pos+3 >= height) p2pos = height-3;
    if (p2pos < 0) p2pos = 0;
}
void Logic() {
    switch (dir) {
    case UPUPUPLEFT:
        x-=1; y-=2; break;
    case UPUPLEFT:
        x-=1; y-=1; break;
    case UPLEFT:
        x-=2; y-=1; break;
    case LEFT:
        x-=2; break;
    case DOWNLEFT:
        x-=2; y+=1; break;
    case DOWNDOWNLEFT:
        x-=1; y+=1; break;
    case DOWNDOWNDOWNLEFT:
        x-=1; y+=2; break;
    case UPUPUPRIGHT:
        x+=1; y-=2; break;
    case UPUPRIGHT:
        x+=1; y-=1; break;
    case UPRIGHT:
        x+=2; y-=1; break;
    case RIGHT:
        x+=2; break;
    case DOWNRIGHT:
        x+=2; y+=1; break;
    case DOWNDOWNRIGHT:
        x+=1; y+=1; break;
    case DOWNDOWNDOWNRIGHT:
        x+=1; y+=2; break;
    default:
        break;
    }

    int random = rand() % 13;
    // hits top
    if (y <= 0) {
        switch (dir) {
        case UPUPUPLEFT:
            dir = DOWNDOWNDOWNLEFT; break;
        case UPUPLEFT:
            dir = DOWNDOWNLEFT; break;
        case UPLEFT:
            dir = DOWNLEFT; break;
        case UPUPUPRIGHT:
            dir = DOWNDOWNDOWNRIGHT; break;
        case UPUPRIGHT:
            dir = DOWNDOWNRIGHT; break;
        case UPRIGHT:
            dir = DOWNRIGHT; break;
        default:
            break;
        }
    }
    // hits bottom
    else if (y >= height-1) {
        switch (dir) {
        case DOWNDOWNDOWNLEFT:
            dir = UPUPUPLEFT; break;
        case DOWNDOWNLEFT:
            dir = UPUPLEFT; break;
        case DOWNLEFT:
            dir = UPLEFT; break;
        case DOWNDOWNDOWNRIGHT:
            dir = UPUPUPRIGHT; break;
        case DOWNDOWNRIGHT:
            dir = UPUPRIGHT; break;
        case DOWNRIGHT:
            dir = UPRIGHT; break;
        default:
            break;
        }
    }
    // hits p1 paddle
    else if (x <= 3 && (y == p1pos || y == p1pos+1 || y == p1pos+2)) {
        if ((Direction)random <= 6) dir = (Direction)(random + 7);
        else dir = (Direction)random;
    }
    // hits p2 paddle
    else if (x >= width-3 && (y == p2pos || y == p2pos+1 || y == p2pos+2)) {
        if ((Direction)random >= 7) dir = (Direction)(random - 7);
        else dir = (Direction)random;
    }
    // hits p1 wall
    else if (x <= 1) {
        inGame = false;
        system("CLS");
        SetConsoleTextAttribute(hOut, 10);
        cout << "Player 2 Wins!";
    }
    // hits p2 wall
    else if (x >= width-1) {
        inGame = false;
        system("CLS");
        SetConsoleTextAttribute(hOut, 10);
        cout << "Player 1 Wins!";
    }
}
int main() {
    Initialize();
    int i = 500;
    while (inGame) {
        Draw();
        Input();
        Logic();
        this_thread::sleep_for (chrono::milliseconds(i/10));
        i--;
    }
    SetConsoleTextAttribute(hOut, 15);
    return 0;
}