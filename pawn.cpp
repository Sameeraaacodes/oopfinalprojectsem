#include "pawn.h"
#include "board.h"
#include <cmath>
#include <stdexcept>

pawn::pawn(string color, int rows, int cols)
    : piece(color, rows, cols)
{
}

bool pawn::isvalid(int newrow, int newcol, board* board)
{
    if (newrow < 0 || newrow > 7 || newcol < 0 || newcol > 7)
    {
        throw out_of_range("Pawn move outside board");
    }

    int row_change = newrow - rows;
    int column_change = newcol - cols;

    if (color == "white")
    {
        if (column_change == 0 &&
            row_change == -1 &&
            board->getPiece(newrow, newcol) == NULL)
        {
            return true;
        }

        if (rows == 6 &&
            column_change == 0 &&
            row_change == -2 &&
            board->getPiece(5, cols) == NULL &&
            board->getPiece(4, cols) == NULL)
        {
            return true;
        }

        if (abs(column_change) == 1 &&
            row_change == -1 &&
            board->getPiece(newrow, newcol) != NULL &&
            board->getPiece(newrow, newcol)->getcolor() != color)
        {
            return true;
        }
    }
    else
    {
        if (column_change == 0 &&
            row_change == 1 &&
            board->getPiece(newrow, newcol) == NULL)
        {
            return true;
        }

        if (rows == 1 &&
            column_change == 0 &&
            row_change == 2 &&
            board->getPiece(2, cols) == NULL &&
            board->getPiece(3, cols) == NULL)
        {
            return true;
        }

        if (abs(column_change) == 1 &&
            row_change == 1 &&
            board->getPiece(newrow, newcol) != NULL &&
            board->getPiece(newrow, newcol)->getcolor() != color)
        {
            return true;
        }
    }

    return false;
}

string pawn::getsymbol()
{
    if (color == "white")
    {
        return "PAWN";
    }

    return "pawn";
}