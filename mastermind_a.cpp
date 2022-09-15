///////////////////////////////////////////////////////
// Project Mastermind: Part A
// Written by [placeholder],[placeholder],[placeholder]
///////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class code
{
private:
    int checkIncorrect(code& const guess) const;
    int checkCorrect(code& const guess) const;
    code promptGuess();
    int RANGE, LENGTH, COUNT;
public:
    code (int n, int m);
    vector<int> CODE;
    void initializeCode();
    void print();
};

code::code (int n, int m)
{
    LENGTH = n;
    RANGE = m;
    CODE.resize(LENGTH);
    COUNT = 0;
}

void code::initializeCode()
{
   for (int i = 0; i < LENGTH; i++)
   {
        CODE[i] = rand() % RANGE;
   }
}

int code::checkCorrect(code& const guess)
{
    
}


void code::print()
{
    for (auto val = CODE.begin(); val != CODE.end(); ++val)
        cout << ' ' << *val;
}

int main()
{
    code temp(8, 10);
    temp.initializeCode();
    temp.print();
}