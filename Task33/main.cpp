#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\nMENU\n";
        cout << "1 - Input array and save to text file\n";
        cout << "2 - Generate random array and save to binary file\n";
        cout << "3 - Solve task (sum between first and last negative)\n";
        cout << "4 - Read array from file using vector\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: inputArrayToTextFile(); break;
        case 2: randomArrayToBinaryFile(); break;
        case 3: solveTask(); break;
        case 4: readVectorFromFile(); break;
        }

    } while (choice != 0);

    return 0;
}
