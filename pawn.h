#pragma once
#include "piece.h"
using namespace std;
class pawn : public piece
{
public:
    pawn(string color, int rows, int cols);
    bool isvalid(int newrow, int newcol, board* board);
    string getsymbol();
};