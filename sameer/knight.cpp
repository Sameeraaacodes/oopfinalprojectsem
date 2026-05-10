#include<iostream>
#include<string>
using namespace std;
#include"knight.h"

knight::knight(string color, int rows, int cols)
    : piece(color, rows, cols)
{
}

bool knight::isvalid(int newrow, int newcol, board* board)
{
    int row_change = abs(newrow - rows);
    int column_change = abs(newcol - cols);

    if ((row_change == 2 && column_change == 1) ||
        (row_change == 1 && column_change == 2))
    {
        return true;
    }

    return false;
}
string knight::getsymbol()
{
    if (color == "white")
    {
        return "KNIGHT";
    }

    return "knight";
}
