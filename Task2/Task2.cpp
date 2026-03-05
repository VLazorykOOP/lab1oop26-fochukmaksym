// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int* A = new int[n];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int zeroIndex = -1;

    // шукаємо перший 0
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            zeroIndex = i;
            break;
        }
    }

    int min = 1000000;
    int index = -1;

    // шукаємо мінімальний додатний правіше нуля
    for (int i = zeroIndex + 1; i < n; i++)
    {
        if (A[i] > 0 && A[i] < min)
        {
            min = A[i];
            index = i;
        }
    }

    cout << "Index: " << index;

    delete[] A;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
