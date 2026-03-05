// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int N;
    cout << "Enter N:";
    cin >> N;

    int A[100], B[100];

    cout << "Enter" << 2 * N << "elements of array A:\n";
    for (int i = 0; i < 2 * N; i++) {
        cin >> A[i];
    }
    //Переношу другу половину А в першу половину В

    for (int i = 0; i < N; i++) {
        B[i] = A[i + N];
    }
    //Переношу першу половину А в другу полвовину В
    for (int i = 0; i < N; i++) {
        B[i + N] = A[i];
    }
    cout << "Array B:\n";
    for (int i = 0; i < 2 * N; i++) {
        cout << B[i] << " ";
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
