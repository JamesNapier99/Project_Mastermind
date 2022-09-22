#pragma once
#ifndef RESPONSE_H
#define RESPONSE_H

#include <vector>

class response
{
private:
    int numCorrect;
    int numIncorrect;
public:
    response(int c, int i);
    void setCorrect(int correct);
    void setIncorrect(int incorrect);
    int getCorrect();
    int getIncorrect();
    bool operator == (const response rhs);
    void operator << ();
};
#endif
