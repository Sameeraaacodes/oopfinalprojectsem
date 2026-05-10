#include"king.h"
#include<string>
using namespace std;
bool king::isvalid(int newrow, int newcol, board* board)
{
    int row_change = abs(newrow - rows);
    int column_change = abs(newcol - cols);

    if (row_change <= 1 && column_change <= 1)
    {
        return true;
    }

    return false;
}

string king::getsymbol()
{
    if (color == "white")
    {
        return "KING";
    }

    return "king";
}
