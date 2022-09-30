#pragma once
#ifndef RESPONSE_H
#define RESPONSE_H

#include <vector>
#include <iostream>

namespace n {
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
        bool operator == (const response& rhs);
        std::ostream& operator << (std::ostream& ostr); //do we need to have this be a friend?
    };

    //    bool operator==(const response& lhs, const response& rhs);


}
#endif
