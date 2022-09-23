///////////////////////////////////////////////////////////////////////////////
// Project#1 
// Mastermind: Part A
// Written by:
// James Napier:                                      napier.j@northeastern.edu
// Julia Rasmussen:                                rasmussen.j@northeastern.edu
// Samuel Sheehan:                                   sheehan.s@northeastern.edu
//
// Main program file for project 1. Contains declaration for the
// code constructor, initializeCode, checkCorrect, checkIncorrect,
// print and writeVec.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "code.h"

using namespace std;
using namespace n;

code::code (const int &n, const int &m)
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
    } //end for
}

int code::checkCorrect (const code &guess)
// Compares index i of the inputted code guess object's CODE field with
// index i of this code object's CODE field for 0<=i<LENGTH and returns
// the number of equivalent values.
{
    int numCorrect = 0;

    for (int i = 0; i < LENGTH; i++)
    {
        if (guess.CODE[i] == CODE[i])
        {
            numCorrect++;
        } //end if
    } //end for
    return numCorrect;
}

int code::checkIncorrect(code &guess)
// First, removes values that are correctly placed in inputted code guess'
// CODE field. Then, compares the remaining values in the inputted code to
// the master code, and returns how many common values there are,
// i.e incorrectly placed digits in the guess.
{
    int numIncorrect = 0;
    int count = LENGTH;
    vector<int> temp = CODE;

    //removes common values from each CODE field
    for (int i = 0; i < count; i++)
    {
        if (guess.CODE[i] == temp[i]) {
            guess.CODE.erase(guess.CODE.begin() + i);
            temp.erase(temp.begin() + i);
            i--;
            count--;
        } //end if
    } //end for

    // Loops through both the guess CODE field and the master CODE field,
    // comparing values to count how many are equivalent with different
    // indices. When a common value is found, it is set to a value outside
    // of the given range of values as to avoid double counting.
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (guess.CODE[i] == temp[j])
            {
                temp[j] = RANGE + 2;
                numIncorrect++;
                break;
            } //end if
        } //end for
    } //end for
    return numIncorrect;
}

void code::print()
// Prints the values in the CODE vector field.
{
    for (int i = 0; i < LENGTH; i++)
    {
        cout << CODE[i];
    } //end for
}

void code::writeVec(const vector<int> &guess)
// Writes a vector to the CODE vector field of a code object.
{
    for (int i = 0; i < LENGTH; i++)
    {
        CODE[i] = guess[i];
    } //end for
}

int main()
//the main function of the program.
{
    int len = 5;
    int ran = 7;
    code master(len, ran);
    master.initializeCode();
    code guess1(len, ran);
    code guess2(len, ran);
    code guess3(len, ran);
    vector<int> g1{5, 0, 3, 2, 6};
    vector<int> g2{2, 1, 2, 2, 2};
    vector<int> g3{1, 3, 3, 4, 5};
    guess1.writeVec(g1);
    guess2.writeVec(g2);
    guess3.writeVec(g3);
    cout << "For sample guess 1, there are " << master.checkCorrect(guess1)
        << " correctly placed digits and " << master.checkIncorrect(guess1)
        << " incorrectly placed digits.\n";
    cout << "For sample guess 2, there are " << master.checkCorrect(guess2)
         << " correctly placed digits and " << master.checkIncorrect(guess2)
         << " incorrectly placed digits.\n";
    cout << "For sample guess 3, there are " << master.checkCorrect(guess3)
         << " correctly placed digits and " << master.checkIncorrect(guess3)
         << " incorrectly placed digits.\n";
    cout << "\nThe correct code was: ";
    master.print();
    cout << "\n";
}
