#include"queen.h"
#include<string>
using namespace std;
queen::queen(string color, int rows, int cols)
    : piece(color, rows, cols)
{
}

bool queen::isvalid(int newrow, int newcol, board* board)
{
    int row_change = newrow - rows;
    int column_change = newcol - cols;

    if (row_change == 0 ||
        column_change == 0 ||
        abs(row_change) == abs(column_change))
    {
        if (board->isPathClear(rows, cols, newrow, newcol))
        {
            return true;
        }
    }

    return false;
}

string queen::getsymbol()
{
    if (color == "white")
    {
        return "QUEEN";
    }

    return "queen";
}
