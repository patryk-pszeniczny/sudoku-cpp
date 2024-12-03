#pragma once
#include <random>
namespace szablon {

    class GameLogic {
    public:
        int board[9][9];
        int copy_board[9][9];
        double generate_time;
        int samples;

        GameLogic();
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
        ~GameLogic();
    };
}
