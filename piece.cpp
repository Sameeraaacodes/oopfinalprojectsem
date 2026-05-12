#include "piece.h"
#include "board.h"
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
    return false;
}