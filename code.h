#pragma once
#ifndef CODE_H
#define CODE_H

#include <vector>

class code
{
private:
    int checkIncorrect(code &guess);
    int checkCorrect(code &guess);
    int RANGE, LENGTH, COUNT;
public:
    code (int n, int m);
    std::vector<int> CODE;
    void initializeCode();
    void promptGuess();
    void print();
};

#endif CODE_H