#pragma once
#include<iostream>
#include<string>
using namespace std;
class king : public piece
{
public:
    king(string color, int rows, int cols);

    bool isvalid(int newrow, int newcol, board* board);

    string getsymbol();
};

