////////////////////////////////////////////////////////////////
// Project Mastermind: Part A
// Written by James Napier, Julia Rasmussen, and Samuel Sheehan
////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class code
{
private:
    int checkIncorrect(code& guess);
    void checkCorrect(code& guess);
    void promptGuess();
    int RANGE, LENGTH, COUNT;
public:
    code (int n, int m);
    vector<int> CODE;
    void initializeCode();
    void print();
};

//constructor for code class.
code::code (int n, int m)
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

    promptGuess();
}

//checks whether or not given code is correct.
bool code::checkCorrect (code& guess)
{
    int numCorrect = 0;
    for (int i = 0; i < LENGTH; i++)
    {
        if (guess.CODE[i] == CODE[i])
        {
            numCorrect += 1;
            guess.CODE[i] = RANGE + 1; //mark somehow. Considering the value is INT maybe set it 1 beyond max of RANGE?
        }
    }
    cout << "Number of Correct Guesses in Correct Spaces: " << numCorrect;
    int numIncorrect = checkIncorrect(guess);
    cout << "Number of Correct Guesses in Incorrect Spaces: " << numIncorrect;

    if (numCorrect == LENGTH)
    {
        return true;
    }
    return false;
}

//rewrites the print function for the code class.
int code::checkIncorrect (code& guess)
{
    int numIncorrect = 0;
    vector<int> tempAns = CODE;
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; i++)
        {
            if (guess.CODE[i] == tempAns[j])
            {
                numIncorrect += 1;
                guess.CODE[i] = RANGE + 1;
                tempAns[j] = RANGE + 2;
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
    if (COUNT < 10)
    {
        COUNT += 1;
        vector<int> guess(LENGTH);

        //fills in guess with a total of LENGTH integers.
        for (int i = 0; i < LENGTH; i++)
        {
            //prompt user for value at index i of guess.
            int temp;
            cout << "Please enter index "<< i <<" of guess #" << COUNT;
            cin >> temp;

            //push int to the back of guess vector.
            guess.push_back(temp);
        }

        //checks whether or not the given guess is correct. if so, win condition.
        if (checkCorrect(temp))
        {
            COUNT = 10;
            cout << "You Win!";
            return;
        }
    }
    //the lose condition.
    cout << "You Lose!";
}

//prints the code.
void code::print()
{
    for (auto val = CODE.begin(); val != CODE.end(); ++val)
        cout << ' ' << *val;
}

//the main function of the program.
int main()
{
    code temp(8, 10);
    temp.initializeCode();
    temp.print();
}