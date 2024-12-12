#include "GameLogic.h"
#include <algorithm> 
#include <random>
#include <chrono>

namespace szablon {
    GameLogic::GameLogic() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        this->rand = std::mt19937(seed);
        this->generate_time = 0;
        this->samples = 0;
    }
    void GameLogic::GenerateSudoku() 
    {
        auto start = std::chrono::high_resolution_clock::now();
        while (fillValues()) {}
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        this->generate_time = static_cast<double>(duration.count()) / 1000000; //nano -> ms
    }
    void GameLogic::fillArrays() 
    {
        for (int row = 0; row < 9; row++) 
        {
            for (int col = 0; col < 9; col++) 
            {
                board[row][col] = 0;
                copy_board[row][col] = 0;
            }
        }
    }
    bool GameLogic::solveSudoku() {
        int row, col;
        if (!hasEmptyCell()) 
        {
            return true;
        }
        for (int value = 1; value <= 9; value++) 
        {
            if (!CheckIfSafe(row, col, value))
            {
                continue;
            }
            board[row][col] = value;
            if (solveSudoku())
            {
                return true;
            }
            board[row][col] = 0;
        }
        return false;
    }

    bool GameLogic::fillValues() 
    {
        this->samples++;
        int values[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        std::shuffle(values, values + 9, rand);
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                if (board[i][j] != 0)
                {
                    continue;
                }
                for (int value : values) 
                {
                    if (!CheckIfSafe(i, j, value)) 
                    {
                        continue;
                    }
                    board[i][j] = value;
                    if (!hasEmptyCell() || fillValues()) 
                    {
                        return true;
                    }
                    board[i][j] = 0;
                }
                return false;
            }
        }
        return false;
    }
    bool GameLogic::hasEmptyCell() 
    {
        for (int r = 0; r < 9; r++) 
        {
            for (int c = 0; c < 9; c++) 
            {
                if (board[r][c] == 0) 
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool GameLogic::CheckIfSafe(int& row, int& col, int num) 
    {
        for (int c = 0; c < 9; c++) 
        {
            if (board[row][c] == num) 
            {
                return false;
            }
        }

        for (int r = 0; r < 9; r++) 
        {
            if (board[r][col] == num) 
            {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int r = startRow; r < startRow + 3; r++) 
        {
            for (int c = startCol; c < startCol + 3; c++) 
            {
                if (board[r][c] == num) 
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool GameLogic::checkSudoku() {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (copy_board[r][c] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void GameLogic::removeDigits(int count) 
    {
        while (count > 0) {
            int cellId = rand() % 81;
            int row = cellId / 9;
            int col = cellId % 9;

            if (board[row][col] != 0) 
            {
                copy_board[row][col] = board[row][col];
                board[row][col] = 0;
                count--;
            }
        }
    }
    double GameLogic::getGenerateTime()
    {
        return this->generate_time;
    }
    int GameLogic::getSamples()
    {
        return this->samples;
    }
    int GameLogic::getBoard(int x, int y)
    {
        return this->board[x][y];
    }
    int GameLogic::getCopyBoard(int x, int y)
    {
        return this->copy_board[x][y];
    }
    void GameLogic::setBoard(int x, int y, int value)
    {
        this->board[x][y] = value;
    }
    void GameLogic::setCopyBoard(int x, int y, int value)
    {
        this->copy_board[x][y] = value;
    }
    GameLogic::~GameLogic() {
        delete copy_board;
        delete board;
    }
}
