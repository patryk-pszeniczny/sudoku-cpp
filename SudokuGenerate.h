#pragma once
#include <random>
using namespace System;
using namespace System::Collections::Generic;
namespace szablon {

class SudokuGenerate {
    public:
        int board[9][9];
        int copy_board[9][9];
        double generate_time;
        int samples;
        SudokuGenerate();
        void GenerateSudoku();
        void fillArrays();
        bool solveSudoku();
        bool checkSudoku();
        void removeDigits(int count);
    private:
        std::mt19937 rand;
        bool CheckIfSafe(int& row, int& col, int num);
        bool fillValues();
        bool hasEmptyCell();
    protected:
        ~SudokuGenerate();
    };
}
