#include "bishop.h"
#include "board.h"
#include <cmath>
bishop::bishop(string color, int rows, int cols)
    : piece(color, rows, cols)
{
}
bool bishop::isvalid(int newrow, int newcol, board* board)
{
    int row_change = newrow - rows;
    int column_change = newcol - cols;
    if (abs(row_change) == abs(column_change))
    {
        if (board->isPathClear(rows, cols, newrow, newcol))
        {
            return true;
       }
    }
    return false;
}
string bishop::getsymbol()
{
    if (color == "white")
    {
        return "BISHOP";
    }
    return "bishop";
}