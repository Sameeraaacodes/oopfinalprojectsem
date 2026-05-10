#pragma once
#include "piece.h"
class bishop : public piece
{
public:
    bishop(string color, int rows, int cols);
    bool isvalid(int newrow, int newcol, board* board);
    string getsymbol();
};