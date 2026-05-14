#pragma once
#include<iostream>
#include<string>
using namespace std;
bool isCheckMate(string color);

bool wouldCauseCheck(int oldRow,
    int oldCol,
    int newRow,
    int newCol);

bool isPathClear(int startRow,
    int startCol,
    int endRow,
    int endCol);

piece* getPiece(int i, int j);
};

class game
{
private:
    board b;

    string currentTurn;

    bool gameOver;

    string winner;

public:
    game();

    void startGame();

    void switchTurn();
};
