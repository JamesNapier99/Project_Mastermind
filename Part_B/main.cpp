////////////////////////////////////////////////////////////////
// Project Mastermind: Part A
// Written by James Napier, Julia Rasmussen, and Samuel Sheehan
////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "code.h"
#include "response.h"
#include "mastermind.h"

using namespace std;
using namespace n;

//constructor for code class.
code::code(const int &n, const int &m)
{
    LENGTH = n;
    RANGE = m;
    CODE.resize(LENGTH);
    COUNT = 0;
}

//get function for Obj code
std::vector<int> code::getCode()
{
    return CODE;
}

//initializes the random code to guess.
void code::initializeCode()
{
    for (int i = 0; i < LENGTH; i++)
    {
        CODE[i] = rand() % RANGE;
    }
}

//sets a specific digit in the code
void code::setCodeDigit(int digit, int index)
{
    CODE[index] = digit;
}

//returns the number of digits in the correct position
int code::checkCorrect(code& guess)
{
    int numCorrect = 0;
    for (int i = 0; i < LENGTH; i++)
    {
        if (guess.CODE[i] == CODE[i])
        {
            numCorrect++;
        }
    }
    return numCorrect;
}

//returns the # of digits in the incorrect position
int code::checkIncorrect(code& guess)
{
    int numIncorrect = 0;
    int count = LENGTH;
    vector<int> temp = CODE;
    for (int i = 0; i < count; i++)
    {
        if (guess.CODE[i] == temp[i]) {
            guess.CODE.erase(guess.CODE.begin() + i);       // seems unnecessry to reference the beginning since vectors are indexed at 0 being the start...
            temp.erase(temp.begin() + i);                   // same as above
            i--;
            count--;
        }
    }
    /*
    for (int i = 0; i<count; i++)
        cout << temp[i] << " ";
    for (int i = 0; i<count; i++)
        cout << guess.CODE[i] << " ";
    */
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (guess.CODE[i] == temp[j])
            {
                //guess.CODE.erase(guess.CODE.begin() + i);
                //temp.erase(temp.begin() + j);
                //count--;
                temp[j] = RANGE + 2;
                numIncorrect++;
                break;
            }
        }
    }
    return numIncorrect;
}

//prints the code.
void code::print()
{
    for (int i = 0; i < LENGTH; i++)
    {
        cout << CODE[i];
    }
}

//********************************************************************************************
//Here's some code for part B.
//********************************************************************************************
response::response(int c, int i)
{
    numCorrect = c;
    numIncorrect = i;
}

//setter for numCorrect.
void response::setCorrect(int correct)
{
    numCorrect = correct;
}

//setter for numIncorrect.
void response::setIncorrect(int incorrect)
{
    numIncorrect = incorrect;
}

//getter for numCorrect.
int response::getCorrect() const
{
    return numCorrect;
}

//getter for numIncorrect.
int response::getIncorrect() const
{
    return numIncorrect;
}

////override the == function.
//bool operator == (const response& lhs, const response& rhs)
//{
//    return ((lhs.getCorrect() == rhs.getCorrect()) && (lhs.getIncorrect() == rhs.getIncorrect()));
//}
//
//ostream& operator << (ostream& ostr, const response& r)
//{
//    ostr << r.getCorrect() << ", " << r.getIncorrect();
//    return ostr;
//}

mastermind::mastermind() : secretCode(5, 10)
{
    secretCode.initializeCode();
    n = 5;
    m = 10;
}

mastermind::mastermind(const int& nGiven, const int& mGiven) : secretCode(nGiven, mGiven)
{
    secretCode.initializeCode();
    n = nGiven;
    m = mGiven;
}

void mastermind::printSecretCode()
{
    secretCode.print();
}

code mastermind::humanGuess()
{
    code guess(n, m);
//    fills in guess with a total of LENGTH integers.
    for (int i = 0; i < n; i++)
    {
        int temp;
        bool valid = false;
        while(!valid)
        {
            //prompt user for value at index i of guess.
            cout << "\nPlease enter index " << i << " of your guess: ";
            cin >> temp;
            if (temp < m && temp >= 0)
            {
                valid = true;
            } else
            {
                cout << "\nValue is out of range. Please try again";
            }
        }
        //push int to the back of guess vector.
        guess.setCodeDigit(temp, i);

    }
        return guess;
}

response mastermind::getResponse(code& guess)
{
    int correct;
    int incorrect;
    correct = secretCode.checkCorrect(guess);
    incorrect = secretCode.checkIncorrect(guess);
    cout << correct;
    cout << incorrect;

    response resp(correct,incorrect);

    return resp;
}

bool mastermind::isSolved(response& r)
{
    response key(5,0);
    return ((r.getCorrect() == key.getCorrect()) && (r.getIncorrect() == key.getIncorrect()));
}

void mastermind::playGame()
{
    secretCode.initializeCode();
    secretCode.print();
    bool win;
    for (int i = 0; i < 10; i++) {
        cout << "\nGuess Number " << i + 1;
        code guess = humanGuess();
        response r = getResponse(guess);
        cout << "Number of correctly placed digits: " << r.getCorrect() << "\n";
        cout << "Number of incorrectly placed digits: " << r.getIncorrect() << "\n";
        win = isSolved(r);
        if (win)
        {
            cout << "\nYou guessed the secret number! Congrats!";
            cout << "\n================================================================================";
            break;
        } else
        {
            cout << "\nYour guess was not correct. You have " << 9 - i << " guesses left!";
            cout << "\n================================================================================";
        }
    }
    if (!win)
    {
        cout << "\nSorry, you ran out of guesses. Try again next time!";
        cout << "\n================================================================================";
    }
}
//********************************************************************************************
//End of code for Part B.
//********************************************************************************************
//the main function of the program.
int main()
{
    int len, ran;
    cout << "================================================================================";
    cout << "\nPlease enter the length of the guess you want to play with: ";
    cin >> len;
    cout << "Please enter the range of numbers you want to play with: ";
    cin >> ran;
    cout << "================================================================================";
    mastermind master(len, ran);
    master.playGame();
}