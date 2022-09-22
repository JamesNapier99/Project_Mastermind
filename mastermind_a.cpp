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
    int checkIncorrect(code &guess);
    int checkCorrect(code &guess);
    int RANGE, LENGTH, COUNT;
public:
    code (int n, int m);
    vector<int> CODE;
    void initializeCode();
    void promptGuess();
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
}

//returns the number of digits in the correct position
int code::checkCorrect (code &guess)
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
    for (int i = 0; i<count; i++)
        cout << temp[i] << " ";
    for (int i = 0; i<count; i++)
        cout << guess.CODE[i] << " ";
    for (int i = 0; i < count; i++)
    {
        for(int j = 0; j < count; i++)
        {
            if (guess.CODE[i] == temp[j])
            {
                guess.CODE.erase(guess.CODE.begin() + i);
                temp.erase(temp.begin() + j);
                count--;
                numIncorrect++;
            }
        }
    }
    return 9;
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
            cout << "\nPlease enter index "<< i <<" of guess #" << COUNT << ": ";
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
    cout << "\nYou Lose!";
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