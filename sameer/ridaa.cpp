#include"ridaa.h"
#include<iostream>
#include<string>
using namespace std;
bool board::isCheckMate(string color)
{


    if (!ischeck(color))
    {
        return false;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessboard[i][j] != NULL &&
                chessboard[i][j]->getcolor() == color)
            {
                for (int r = 0; r < 8; r++)
                {
                    for (int c = 0; c < 8; c++)
                    {
                        if (r == i && c == j)
                        {
                            continue;
                        }

                        if (chessboard[r][c] != NULL)
                        {
                            if (chessboard[r][c]->getcolor() == color)
                            {
                                continue;
                            }
                        }

                        if (chessboard[i][j]->isvalid(r, c, this))
                        {
                            if (!wouldCauseCheck(i, j, r, c))
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}



bool board::isPathClear(int startRow, int startCol, int endRow, int endCol)
{
    int rowDirection = 0;
    int colDirection = 0;

    if (endRow > startRow)
    {
        rowDirection = 1;
    }
    else if (endRow < startRow)
    {
        rowDirection = -1;
    }

    if (endCol > startCol)
    {
        colDirection = 1;
    }
    else if (endCol < startCol)
    {
        colDirection = -1;
    }

    int currentRow = startRow + rowDirection;
    int currentCol = startCol + colDirection;

    while (currentRow != endRow || currentCol != endCol)
    {
        if (chessboard[currentRow][currentCol] != NULL)
        {
            return false;
        }

        currentRow += rowDirection;
        currentCol += colDirection;
    }

    return true;
}


bool board::wouldCauseCheck(int oldRow,
    int oldCol,
    int newRow,
    int newCol)
{
    piece* movingPiece = chessboard[oldRow][oldCol];

    piece* capturedPiece = chessboard[newRow][newCol];

    chessboard[newRow][newCol] = movingPiece;

    chessboard[oldRow][oldCol] = NULL;

    int originalRow = movingPiece->getrow();
    int originalCol = movingPiece->getcol();

    movingPiece->setposition(newRow, newCol);

    bool check = ischeck(movingPiece->getcolor());

    chessboard[oldRow][oldCol] = movingPiece;

    chessboard[newRow][newCol] = capturedPiece;

    movingPiece->setposition(originalRow, originalCol);

    return check;
}


piece* board::getPiece(int i, int j)
{
    return chessboard[i][j];
}

game::game()
{
    currentTurn = "white";
    gameOver = false;
    winner = "";
}

void game::startGame()
{
    bool gameStarted = false;

    Rectangle startButton = { 300, 500, 200, 60 };

    b.initializeboard();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        if (!gameStarted)
        {
            DrawText("Chess Game", 240, 180, 50, WHITE);

            DrawText("Project Members:", 260, 300, 30, GRAY);

            DrawText("Sameer Arshad", 280, 360, 25, WHITE);
            DrawText("Abdul Moeed", 285, 400, 25, WHITE);
            DrawText("Rida Khalid", 300, 440, 25, WHITE);

            DrawRectangle(300, 500, 200, 60, DARKBROWN);

            DrawText("START", 345, 515, 30, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(),
                startButton) &&
                IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                gameStarted = true;
            }
        }
        else
        {
            b.drawboard();

            if (!gameOver)
            {
                b.handlemouseclick();

                if (b.isCheckMate("white"))
                {
                    gameOver = true;
                    winner = "BLACK";
                }

                if (b.isCheckMate("black"))
                {
                    gameOver = true;
                    winner = "WHITE";
                }
            }
            else
            {
                DrawRectangle(80, 320, 650, 90, BLACK);

                string text = winner + " WINS BY CHECKMATE";

                DrawText(text.c_str(),
                    100,
                    345,
                    35,
                    GREEN);
            }
        }

        EndDrawing();
    }
}
void game::switchTurn()
{
    if (currentTurn == "white")
    {
        currentTurn = "black";
    }
    else
    {
        currentTurn = "white";
    }
}