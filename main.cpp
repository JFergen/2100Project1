#include <iostream>
using namespace std;

void FillJug(int& jug, int max); // Fills jug to full
void EmptyJug(int& jug); // Empties jug completely
void JugToJug(int& jug1, int& jug2, int jug2Max); // Moves water from jug1 -> jug2 until jug1 is empty or jug2 is full
void PrintJugs(int jug1, int jug2); // Prints both jugs and the amount of water they have

int main()
{
    int jugA; // Holds the amount of water in jug A
    int AMax; // Holds the max size of jug A
    int jugB; // Holds the amount of water in jug B
    int BMax; // Holds the max size of jug B
    int waterAmount; // Holds the amount of water currently

    cout << "Enter how much water jug A can hold (Must be a non-zero, positive integer): "; // Getting size of jug A from user
    cin >> jugA;

    while(jugA <= 0) // If size is not non-zero or not positive
    {
        cout << "Jug A must be non-zero and positive integer. Try again: ";
        cin >> jugA;
    }
    AMax = jugA; // Setting the max amount jug A can hold
    jugA = 0; // Setting current amount to 0

    cout << "Enter how much water jug B can hold (Must be a non-zero, positive integer): "; // Getting size of jug B from user
    cin >> jugB;

    while(jugB <= 0) // If size is not non-zero or not positive
    {
        cout << "Jug B must be a non-zero and positive integer. Try again: ";
        cin >> jugB;
    }
    BMax = jugB; // Setting max amount jug B can hold
    jugB = 0; // Setting current amount to 0

    cout << "Enter the amount of water (Must be a non-zero, positive integer): "; // Getting total amount of water from user
    cin >> waterAmount;

    while(waterAmount <= 0) // If water amount is not non-zero or not positive
    {
        cout << "The amount of water must be a non-zero and positive integer. Try again: ";
        cin >> waterAmount;
    }

    while(waterAmount > (AMax + BMax)) // If the amount of water is greater than the two jugs added together
    {
        cout << "The amount of water must be less than or equal to (" << AMax + BMax << ") (the size of jug A + jug B). Try again: ";
        cin >> waterAmount;
    }

    //Printing Stuff
    cout << endl << endl;
    cout << "A(" << AMax << ") \t B(" << BMax << ")" << endl;
    cout << "Request amount:" << waterAmount << endl;
    cout << "----------" << endl;
    PrintJugs(jugA, jugB);

    // Fills up jug A and pours it into jug B. If jug B is full then it is emptied. This is continued until jug A + jug B = water requested
    while( (jugA + jugB) != waterAmount)
    {
        if(jugA == 0)
        {
            FillJug(jugA, AMax);

            if( (jugA + jugB) > waterAmount) // If after filling up jug A, and the total is more than the amount requested, it can not be done.
            {
                cout << "Request can not be fulfilled" << endl;
                break;
            }

            PrintJugs(jugA, jugB);
            continue;
        }

        if(jugB == BMax)
        {
            EmptyJug(jugB);
            PrintJugs(jugA, jugB);
            continue;
        }

        JugToJug(jugA, jugB, BMax);
        PrintJugs(jugA, jugB);
    }

    if(jugA + jugB == waterAmount) // If it is able to fulfill the requested amount of water
    {
        cout << "Request fulfilled" << endl;
    }

    return 0;
}

void FillJug(int& jug, int max)
{
    jug = max;
}

void EmptyJug(int& jug)
{
    jug = 0;
}

void JugToJug(int& jug1, int& jug2, int jug2Max)
{
    while( (jug1 > 0) && (jug2 < jug2Max) )
    {
        jug1--;
        jug2++;
    }
}

void PrintJugs(int jug1, int jug2)
{
    cout << jug1 << "\t " << jug2 << endl;
}