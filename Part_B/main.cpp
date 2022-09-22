////////////////////////////////////////////////////////////////
// Project Mastermind: Part A
// Written by James Napier, Julia Rasmussen, and Samuel Sheehan
////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "code.h"

using namespace std;
using namespace n;

//constructor for code class.
code::code(int n, int m)
{
    LENGTH = n;
    RANGE = m;
    CODE.resize(LENGTH);
    COUNT = 0;
}

//initializes the random code to guess.
void code::initializeCode()
{
    for (int i = 0; i < LENGTH; i++)
    {
        CODE[i] = rand() % RANGE;
    }
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

//prompts user to enter a guess of the code.
void code::promptGuess()
{
    //loops through code at most 10 times.
    while (COUNT < 10)
    {
        COUNT += 1;
        code guess(LENGTH, RANGE);

        //print code
        cout << "\nOur super secret code is ";
        print();

        //fills in guess with a total of LENGTH integers.
        for (int i = 0; i < LENGTH; i++)
        {
            int temp;
            //prompt user for value at index i of guess.
            cout << "\nPlease enter index " << i << " of guess #" << COUNT << ": ";
            cin >> temp;

            //push int to the back of guess vector.
            guess.CODE[i] = temp;
        }

        int numCorrect = checkCorrect(guess);
        int numIncorrect = checkIncorrect(guess);

        cout << "\nNumber of correct digits: " << numCorrect;
        cout << "\nNumber of digits in wrong place: " << numIncorrect;

        //checks whether or not the given guess is correct. if so, win condition.
        if (numCorrect == LENGTH)
        {
            COUNT = 10;
            cout << "\nYou guessed the secret number! Congrats!";
            cout << "\n================================================================================";
            return;
        }
        else
        {
            cout << "\nYour guess was not correct. You have " << 10 - COUNT << " guesses left!";
            cout << "\n================================================================================";
        }
    }
    //the lose condition.
    cout << "\nSorry, you ran out of guesses. Try again next time!";
    cout << "\n================================================================================";
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
int response::getCorrect()
{
    return numCorrect;
}

//getter for numIncorrect.
int response::getCorrect()
{
    return numCorrect;
}

//override the == function.
bool operator == (const response rhs)
{
    return ((numCorrect == rhs.getCorrect()) && (numIncorrect == rhs.getIncorrect()));
}

void operator << ()
{
    cout << numCorrect << ", " << numIncorrect;
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
    code master(len, ran);
    master.initializeCode();
    master.promptGuess();
}