#pragma once
#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "code.h"
#include "response.h"

namespace n
{
    class mastermind
    {
    private:
        code secretCode;
        int n;
        int m;
    public:
        mastermind();
        mastermind(const int& nGiven, const int& mGiven);
        void printSecretCode();
        code humanGuess();
        response getResponse(code& guess);
        bool isSolved(response& r);
        void playGame();
    };
}

#endif