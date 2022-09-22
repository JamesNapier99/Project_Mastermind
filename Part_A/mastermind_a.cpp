///////////////////////////////////////////////////////////////////////////////
// Project#1 
// Mastermind: Part A
// Written by:
// James Napier:                                      napier.j@northeastern.edu
// Julia Rasmussen:                                rasmussen.j@northeastern.edu
// Samuel Sheehan:                                   sheehan.s@northeastern.edu
//
// Main program file for projet 1. Contains declaration for the 
// code constructor, initializeCode, checkCorrect, checkIncorrect, promptGuess,
// and print
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "code.h"

using namespace std;
using namespace n;

code::code (int n, int m)
// constructor for code class
{
    LENGTH = n;
    RANGE = m;
    CODE.resize(LENGTH);
    COUNT = 0;
}


void code::initializeCode()
// initializes CODE, a random vector of size SIZE containing
// integers between 0 and RANGE-1 for a code object
{
   for (int i = 0; i < LENGTH; i++)
   {
        CODE[i] = rand() % RANGE;
   }
}

int code::checkCorrect (code &guess)
// Compares index i of the given code object's CODE field with 
// index i of this code object's CODE field for 0<=i<LENGTH
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
int code::checkIncorrect (code &guess)
{
    int numIncorrect = 0;
    int count = LENGTH;
    vector<int> temp = CODE;
    for (int i = 0; i < count; i++)
    {
        if (guess.CODE[i] == temp[i]) {
            guess.CODE.erase(guess.CODE.begin() + i);
            temp.erase(temp.begin() + i);
            i--;
            count--;
        }
    }

    for (int i = 0; i < count; i++)
    {
        for(int j = 0; j < count; j++)
        {
            if (guess.CODE[i] == temp[j])
            {
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
        //fills in guess with a total of LENGTH integers.
        for (int i = 0; i < LENGTH; i++)
        {
            int temp;
            //prompt user for value at index i of guess.
            cout << "\nPlease enter index "<< i + 1 <<" of guess #" << COUNT << ": ";
            cin >> temp;

            //push int to the back of guess vector.
            guess.CODE[i] = temp;
        }
        cout << "\nNumber of correct digits: " << checkCorrect(guess);
        cout << "\nNumber of digits in wrong place: " << checkIncorrect(guess);

        //checks whether or not the given guess is correct. if so, win condition.
        if (checkCorrect(guess) == LENGTH)
        {
            COUNT = 10;
            cout << "\nYou Win!";
            return;
        }
    }
    //the lose condition.
    cout << "\nYou Lose!\n";
}

//prints the code.
void code::print()
{
    for (int i = 0; i < LENGTH; i++)
    {
        cout << CODE[i];
    }
}

//the main function of the program.
int main()
{
    int len, ran;
    cout << "\nPlease enter the length of the guess you want to play with: ";
    cin >> len;
    cout << "\nPlease enter the range of numbers you want to play with: ";
    cin >> ran;
    code master(len, ran);
    master.initializeCode();
    master.print();
    master.promptGuess();
    master.print();
}