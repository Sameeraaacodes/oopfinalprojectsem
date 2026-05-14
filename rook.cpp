#include "rook.h"
#include "board.h"
#include <stdexcept>
rook::rook(string color, int rows, int cols)
    : piece(color, rows, cols)
{
}
bool rook::isvalid(int newrow, int newcol, board* board)
{
    if (newrow < 0 || newrow > 7 || newcol < 0 || newcol > 7)
    {
        throw out_of_range("Rook move outside board");
    }
    int row_change = newrow - rows;
    int column_change = newcol - cols;

    if (row_change == 0 || column_change == 0)
    {
        if (board->isPathClear(rows, cols, newrow, newcol))
        {
            return true;
        }
    }
    return false;
}