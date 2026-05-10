#pragma once
#include<iostream>
#include<string>
using namespace std;
class queen : public piece
{
public:
    queen(string color, int rows, int cols);

    bool isvalid(int newrow, int newcol, board* board);

    string getsymbol();
};