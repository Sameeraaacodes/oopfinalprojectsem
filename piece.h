#pragma once
#include <string>
using namespace std;
class board;
class piece
{
protected:
    string color;
    int rows;
    int cols;
public:
    piece(string color, int rows, int cols);
    string getcolor();
    int getrow();
    int getcol();
    virtual string getsymbol();
    void setposition(int newrow, int newcol);
    virtual bool isvalid(int newrow, int newcol, board* board);
};