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
            mastermind() : secretCode(5, 10) {};
            mastermind(const int& nGiven, const int& mGiven) : secretCode(nGiven, mGiven) {};
            void printSecretCode();
            code humanGuess();
            response getResponse();
            bool isSolved(response& r);
            void playGame();
    };
}

#endif