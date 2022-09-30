#pragma once
#ifndef CODE_H
#define CODE_H

#include <vector>
namespace n
{
    class code
    {
    private:
        std::vector<int> CODE;
        int RANGE, LENGTH, COUNT;
    public:
        code(const int &n, const int &m);
        int checkIncorrect(code& guess);
        int checkCorrect(code& guess);
        std::vector<int>  getCode();
        void setCodeDigit(int digit, int index);
        void initializeCode();
        void promptGuess();
        void print();
    };
}
#endif