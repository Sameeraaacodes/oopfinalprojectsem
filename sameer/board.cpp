#include"board.h"
#include<iostream>
usim
board::board()
{
    selected_row = -1;
    selected_column = -1;
    piece_selected = false;
    whiteturn = true;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chessboard[i][j] = NULL;
        }
    }
}

void board::initializeboard()
{
    for (int i = 0; i < 8; i++)
    {
        chessboard[1][i] = new pawn("black", 1, i);
        chessboard[6][i] = new pawn("white", 6, i);
    }

    chessboard[0][0] = new rook("black", 0, 0);
    chessboard[0][1] = new knight("black", 0, 1);
    chessboard[0][2] = new bishop("black", 0, 2);
    chessboard[0][3] = new queen("black", 0, 3);
    chessboard[0][4] = new king("black", 0, 4);
    chessboard[0][5] = new bishop("black", 0, 5);
    chessboard[0][6] = new knight("black", 0, 6);
    chessboard[0][7] = new rook("black", 0, 7);

    chessboard[7][0] = new rook("white", 7, 0);
    chessboard[7][1] = new knight("white", 7, 1);
    chessboard[7][2] = new bishop("white", 7, 2);
    chessboard[7][3] = new queen("white", 7, 3);
    chessboard[7][4] = new king("white", 7, 4);
    chessboard[7][5] = new bishop("white", 7, 5);
    chessboard[7][6] = new knight("white", 7, 6);
    chessboard[7][7] = new rook("white", 7, 7);
}
void board::drawboard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int x = j * 100;
            int y = i * 100;

            if ((i + j) % 2 == 0)
            {
                DrawRectangle(x, y, 100, 100, BEIGE);
            }
            else
            {
                DrawRectangle(x, y, 100, 100, DARKBROWN);
            }

            if (selected_row == i &&
                selected_column == j)
            {
                DrawRectangleLines(x, y, 100, 100, RED);
            }

            if (chessboard[i][j] != NULL)
            {
                string symbol = chessboard[i][j]->getsymbol();

                if (chessboard[i][j]->getcolor() == "white")
                {
                    DrawText(symbol.c_str(), x + 10, y + 35, 20, WHITE);
                }
                else
                {
                    DrawText(symbol.c_str(), x + 10, y + 35, 20, BLACK);
                }
            }
        }
    }
}
void board::handlemouseclick()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        int mousex = GetMouseX();
        int mousey = GetMouseY();

        int row = mousey / 100;
        int col = mousex / 100;

        if (row < 0 || row >= 8 || col < 0 || col >= 8)
        {
            return;
        }

        if (!piece_selected)
        {
            if (chessboard[row][col] != NULL)
            {
                if (whiteturn &&
                    chessboard[row][col]->getcolor() == "white")
                {
                    selected_row = row;
                    selected_column = col;
                    piece_selected = true;
                }
                else if (!whiteturn &&
                    chessboard[row][col]->getcolor() == "black")
                {
                    selected_row = row;
                    selected_column = col;
                    piece_selected = true;
                }
            }
        }
        else
        {
            piece* selectedPiece =
                chessboard[selected_row][selected_column];

            if (selectedPiece != NULL)
            {
                if (selectedPiece->isvalid(row, col, this))
                {
                    if (chessboard[row][col] != NULL)
                    {
                        if (selectedPiece->getcolor() ==
                            chessboard[row][col]->getcolor())
                        {
                            piece_selected = false;
                            selected_row = -1;
                            selected_column = -1;
                            return;
                        }
                    }

                    if (!wouldCauseCheck(selected_row,
                        selected_column,
                        row,
                        col))
                    {
                        piece* temp = chessboard[row][col];

                        if (temp != NULL)
                        {
                            delete temp;
                        }

                        chessboard[row][col] = selectedPiece;

                        chessboard[selected_row][selected_column] = NULL;

                        selectedPiece->setposition(row, col);

                        whiteturn = !whiteturn;
                    }
                }
            }

            piece_selected = false;
            selected_row = -1;
            selected_column = -1;
        }
    }
}
bool board::ischeck(string color)
{
    int kingrow = -1;
    int kingcol = -1;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessboard[i][j] != NULL)
            {
                if (chessboard[i][j]->getcolor() == color)
                {
                    if (chessboard[i][j]->getsymbol() == "KING" ||
                        chessboard[i][j]->getsymbol() == "king")
                    {
                        kingrow = i;
                        kingcol = j;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessboard[i][j] != NULL)
            {
                if (chessboard[i][j]->getcolor() != color)
                {
                    if (chessboard[i][j]->isvalid(kingrow, kingcol, this))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}