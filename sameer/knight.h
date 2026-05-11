#pragma once
#include<iostream>
#include<string>
using namespace std;

class knight : public piece
{
public:
    knight(string color, int rows, int cols);

    bool isvalid(int newrow, int newcol, board* board);

    string getsymbol();
};

