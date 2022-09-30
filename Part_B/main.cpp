////////////////////////////////////////////////////////////////
// Project Mastermind: Part B
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

/*
* Initializes the code object.
* n: integer n, representing the length of the new code object.
* m: integer m, representing the range of the new code object.
*/
code::code(const int& n, const int& m)
{
    LENGTH = n;
    RANGE = m;
    CODE.resize(LENGTH);
    COUNT = 0;
}

/*
* Gets the value of length from a given code object.
* No inputs.
*/
int code::getLength()
{
    return LENGTH;
}

/*
* Gets the code stored in a given code object.
* No inputs.
*/
std::vector<int> code::getCode()
{
    return CODE;
}

/*
* Initializes the random code to guess.
* No inputs.
*/
void code::initializeCode()
{
    for (int i = 0; i < LENGTH; i++)
    {
        CODE[i] = rand() % RANGE;
    }
}

/*
* Sets a specific digit in the code.
* digit: new integer value of the digit.
* index: integer index of the digit to change.
*/
void code::setCodeDigit(int digit, int index)
{
    CODE[index] = digit;
}

/*
* Returns the number of digits in the correct position.
* guess: code object to compare against the original code object.
*/
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

/*
* Returns the number of digits in the incorrect position.
* guess: code object to compare against the original code object.
*/
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

/*
* Prints the stored code.
* No inputs.
*/
void code::print()
{
    for (int i = 0; i < LENGTH; i++)
    {
        cout << CODE[i];
    }
}


/*
* Initializes the response class.
* c: integer to initialize numCorrect to.
* i: integer to initialize numIncorrect to.
*/
response::response(int c, int i)
{
    numCorrect = c;
    numIncorrect = i;
}


/*
* Setter for numCorrect
* correct: integer number of correct digits, to assign to numCorrect.
*/
void response::setCorrect(int correct)
{
    numCorrect = correct;
}

/*
* Setter for numIncorrect
* correct: integer number of incorrect digits, to assign to numIncorrect.
*/
void response::setIncorrect(int incorrect)
{
    numIncorrect = incorrect;
}

/*
* Getter for numCorrect
* No inputs.
*/
//getter for numCorrect.
int response::getCorrect() const
{
    return numCorrect;
}

/*
* Getter for numInorrect
* No inputs.
*/
int response::getIncorrect() const
{
    return numIncorrect;
}

/*
* Overrides the == function for the response class.
* rhs: the response on the right hand side of the == operator, the response to compar the original to.
*/
bool response::operator == (const response& rhs)
{
    return ((getCorrect() == rhs.getCorrect()) && (getIncorrect() == rhs.getIncorrect()));
}

/*
* Overrides the << function.
* ostr: the ostream to print to.
*/
ostream& response::operator << (ostream& ostr)
{
    ostr << getCorrect() << ", " << getIncorrect();
    return ostr;
}

/*
* Intialize mastermind object with a secret code of length 5 and range 10.
* No inputs.
*/
mastermind::mastermind() : secretCode(5, 10)
{
    secretCode.initializeCode();
    n = 5;
    m = 10;
}

/*
* Intialize mastermind object with a secret code of length nGiven and range mGiven.
* nGiven: integer length of the initialized secret code.
* nGiven: integer range of the initialized secret code.
*/
mastermind::mastermind(const int& nGiven, const int& mGiven) : secretCode(nGiven, mGiven)
{
    secretCode.initializeCode();
    n = nGiven;
    m = mGiven;
}

/*
* Print the secret code from the mastermind object.
* No inputs.
*/
void mastermind::printSecretCode()
{
    secretCode.print();
}

/*
* Asks user for guess.
* No inputs.
*/
code mastermind::humanGuess()
{
    code guess(n, m);
    //    fills in guess with a total of LENGTH integers.
    for (int i = 0; i < n; i++)
    {
        int temp;
        bool valid = false;
        while (!valid)
        {
            //prompt user for value at index i of guess.
            cout << "\nPlease enter index " << i << " of your guess: ";
            cin >> temp;
            if (temp < m && temp >= 0)
            {
                valid = true;
            }
            else
            {
                cout << "\nValue is out of range. Please try again";
            }
        }
        //push int to the back of guess vector.
        guess.setCodeDigit(temp, i);

    }
    return guess;
}

/*
* Gets the response from a given guess.
* guess: code object to base reponse off of.
*/
response mastermind::getResponse(code& guess)
{
    int correct;
    int incorrect;
    correct = secretCode.checkCorrect(guess);
    incorrect = secretCode.checkIncorrect(guess);

    response resp(correct, incorrect);

    return resp;
}

/*
* Determines whether or not a given response solves the secret code.
* r: response to check the secret code against.
*/
bool mastermind::isSolved(response& r)
{
    response key(secretCode.getLength(), 0);
    return ((r.getCorrect() == key.getCorrect()) && (r.getIncorrect() == key.getIncorrect()));
}

/*
* Play the Mastermind game.
* No inputs.
*/
void mastermind::playGame()
{
    secretCode.initializeCode();
    cout << "\nShhhhh. Our super secret code is ";
    secretCode.print();
    cout << ".\n";
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
        }
        else
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

/*
* The main function, runs the whole code.
* No inputs.
*/
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