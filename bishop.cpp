#include "bishop.h"
#include "board.h"
#include <cmath>
#include <stdexcept>
bishop::bishop(string color, int rows, int cols)
    : piece(color, rows, cols)
{
}
bool bishop::isvalid(int newrow, int newcol, board* board)
{
    if (newrow < 0 || newrow > 7 || newcol < 0 || newcol > 7)
    {
        throw out_of_range("Bishop move outside board");
    }
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