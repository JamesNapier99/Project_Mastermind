#pragma once
#ifndef CODE_H
#define CODE_H

#include <vector>
namespace n
{
    class code
    {
    private:
        int RANGE, LENGTH, COUNT;
        std::vector<int> CODE;
    public:
        code(const int& n, const int& m);
        void initializeCode();
        void promptGuess();
        void print();
        void writeVec(std::vector<int> &guess);
        int checkIncorrect(code &guess);
        int checkCorrect(code &guess);
    };
}
#endif