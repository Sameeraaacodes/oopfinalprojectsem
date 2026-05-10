#pragma once
#include<iostream>
#include<string>
using namespace std;
class board
{
private:
    int selected_row;

    int selected_column;

    bool piece_selected;

protected:
    piece* chessboard[8][8];

public:
    bool whiteturn;

    board();

    void initializeboard();

    void drawboard();

    void handlemouseclick();

    bool ischeck(string color);

    bool isCheckMate(string color);
