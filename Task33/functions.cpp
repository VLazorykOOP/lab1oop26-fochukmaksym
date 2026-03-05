#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array (n <= 500): ";
    cin >> n;

    int A[500];  // статичний масив

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
