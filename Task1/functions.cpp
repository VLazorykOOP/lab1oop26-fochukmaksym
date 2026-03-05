#include <iostream>
#include "functions.h"

using namespace std;

void inputArray()
{
    int n;

    cout << "Enter N: ";
    cin >> n;

    int size = 2 * n;

    int* A = new int[size];
    int* B = new int[size];

    cout << "Enter elements of array A:\n";

    for (int i = 0; i < size; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        B[i] = A[i + n];

    for (int i = n; i < size; i++)
        B[i] = A[i - n];

    cout << "Array B:\n";

    for (int i = 0; i < size; i++)
        cout << B[i] << " ";

    delete[] A;
    delete[] B;
}