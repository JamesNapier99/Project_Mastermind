#pragma once
#ifndef RESPONSE_H
#define RESPONSE_H

#include <ostream>

class response
 {
    private:
        int numCorrect;
        int numIncorrect;
    public:
        response(int c, int i);
        void setCorrect(int correct);
        void setIncorrect(int incorrect);
        int getCorrect() const;
        int getIncorrect() const;
        friend bool operator == (const response& lhs, const response& rhs);
        friend std::ostream& operator << (std::ostream& ostr, const response& rhs);
};

#endif
