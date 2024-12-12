#pragma once
#include <random>
namespace szablon {

    class GameLogic {
    public:
        GameLogic();
        double getGenerateTime();
        
        int getSamples();
        int getBoard(int x, int y);
        int getCopyBoard(int x, int y);

        void setBoard(int x, int y, int value);
        void setCopyBoard(int x, int y, int value);

        void GenerateSudoku();
        void fillArrays();
        void removeDigits(int count);

        bool solveSudoku();
        bool checkSudoku();
        bool CheckIfSafe(int& row, int& col, int num);
        bool fillValues();
        bool hasEmptyCell();
    private:
        std::mt19937 rand;
        int board[9][9];
        int copy_board[9][9];
        int samples;
        double generate_time;
    protected:
        ~GameLogic();
    };
}
