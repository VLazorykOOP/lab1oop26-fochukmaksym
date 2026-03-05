#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// 3.1 Введення масиву і запис у текстовий файл
void inputArrayToTextFile()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int* A = new int[n];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
        cin >> A[i];

    ofstream file("array.txt");

    file << n << endl;

    for (int i = 0; i < n; i++)
        file << A[i] << " ";

    file.close();

    delete[] A;

    cout << "Array saved to text file\n";
}

// 3.2 Створення випадкового масиву і запис у бінарний файл
void randomArrayToBinaryFile()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int* A = new int[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
        A[i] = rand() % 20 - 10;

    ofstream file("array.bin", ios::binary);

    file.write((char*)&n, sizeof(n));
    file.write((char*)A, sizeof(int) * n);

    file.close();

    delete[] A;

    cout << "Random array saved to binary file\n";
}

// 3.3 Розв'язання задачі варіанту
void solveTask()
{
    ifstream file("array.txt");

    int n;

    file >> n;

    int* A = new int[n];

    for (int i = 0; i < n; i++)
        file >> A[i];

    file.close();

    int zeroIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            zeroIndex = i;
            break;
        }
    }

    if (zeroIndex == -1)
    {
        cout << "No zero element\n";
        return;
    }

    int minValue = 100000;
    int minIndex = -1;

    for (int i = zeroIndex + 1; i < n; i++)
    {
        if (A[i] > 0 && A[i] < minValue)
        {
            minValue = A[i];
            minIndex = i;
        }
    }

    ofstream result("result.txt");

    cout << "Index of element: " << minIndex << endl;

    result << "Index: " << minIndex;

    result.close();

    delete[] A;
}

// 3.4 Читання у vector і виведення
void readVectorFromFile()
{
    ifstream file("array.txt");

    int n;

    file >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        file >> arr[i];

    file.close();

    cout << "Array from file:\n";

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;
}
