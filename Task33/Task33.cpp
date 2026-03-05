// Task33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array (n <= 500): ";
    cin >> n;

    int A[500];  // використаємо статичний масив для простоти

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int firstNeg = -1, lastNeg = -1;

    // знаходимо перший та останній від’ємні
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            if (firstNeg == -1)
                firstNeg = i;
            lastNeg = i;
        }
    }

    if (firstNeg == -1 || firstNeg == lastNeg)
    {
        cout << "No negative elements or only one negative element.\n";
    }
    else
    {
        int sum = 0;
        cout << "Elements between first and last negative: ";
        for (int i = firstNeg + 1; i < lastNeg; i++)
        {
            cout << A[i] << " ";
            sum += A[i];
        }
        cout << "\nSum = " << sum << endl;
    }

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
