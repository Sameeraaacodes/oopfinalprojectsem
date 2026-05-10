#pragma once
#include "piece.h"
class rook : public piece
{
public:
    rook(string color, int rows, int cols);
    bool isvalid(int newrow, int newcol, board* board);
    string getsymbol();
};
