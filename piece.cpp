#include "piece.h"
#include "board.h"
#include <stdexcept>
piece::piece(string color, int rows, int cols)
{
    this->color = color;
    this->rows = rows;
    this->cols = cols;
}
string piece::getcolor()
{
    return color;
}
int piece::getrow()
{
    return rows;
}
int piece::getcol()
{
    return cols;
}
void piece::setposition(int newrow, int newcol)
{
    rows = newrow;
    cols = newcol;
}
string piece::getsymbol()
{
    return "piece";
}
bool piece::isvalid(int newrow, int newcol, board* board)
{
    if (newrow < 0 || newrow > 7 || newcol < 0 || newcol > 7)
    {
        throw out_of_range("Invalid move: position outside board");
    }
    return true;
}