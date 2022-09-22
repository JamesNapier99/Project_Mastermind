#pragma once
#ifndef MASTERMIND_H
#define MASTERMIND_H

class mastermind
{
private:
    code secretCode;
    int n;
    int m
public:
    mastermind();
    mastermind(int nGiven, int mGiven);
    void printSecretCode();
};


#endif