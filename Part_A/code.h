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

        void initializeCode();
        //void promptGuess();
        void print();
        void writeVec(const std::vector<int> &guess);
        int checkIncorrect(code &guess);
        int checkCorrect(code &guess);
    };
}
#endif