 // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// введення масиву і запис у файл
void inputArray()
{
    int n;
    cout << "n = ";
    cin >> n;

    int* A = new int[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    ofstream f("array.txt");

    f << n << endl;

    for (int i = 0; i < n; i++)
        f << A[i] << " ";

    f.close();

    delete[] A;
}

// читання масиву з файлу
void readArray(int*& A, int& n)
{
    ifstream f("array.txt");

    f >> n;

    A = new int[n];

    for (int i = 0; i < n; i++)
        f >> A[i];

    f.close();
}

// Завдання 1 
//16. Задано одновимірний масив А розміру 2N.Побудувати масив В розміру 2N, розмістивши у першій половині масиву В другу половину масиву А, а у другій половині масиву В, першу - А.
void task1()
{
    int* A;
    int n;

    readArray(A, n);

    int* B = new int[n];

    int k = n / 2;

    for (int i = 0; i < k; i++)
        B[i] = A[i + k];

    for (int i = 0; i < k; i++)
        B[i + k] = A[i];

    cout << "B:\n";

    for (int i = 0; i < n; i++)
        cout << B[i] << " ";

    cout << endl;

    delete[] A;
    delete[] B;
}

// Завдання 2
//16. Знайти номер першого мінімального значення серед додатних елементів,розташованих правіше першого елемента, рівного нулю.
void task2()
{
    int* A;
    int n;

    readArray(A, n);

    int zero = -1;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            zero = i;
            break;
        }
    }
  if (zero == -1)  cout<<" nema zero \n" ;
  else
  {
    int min = 100000;
    int index = -1;

    for (int i = zero + 1; i < n; i++)
    {
        if (A[i] > 0 && A[i] < min)
        {
            min = A[i];
            index = i;
        }
    }

    cout << "Index = " << index << endl;
  }
    
    delete[] A;
}

// Завдання 3
//16. Задано масив чисел A(n),n <= 500.Розробити програму, яка обчислює суму всіх чисел, які знаходяться між першим і останнім від’ємними елементами цього масиву і вказує цей діапазон.Якщо від’ємних чисел немає або є тільки одно, то виводить повідомлення про це.
void task3()
{
    int* A;
    int n;

    readArray(A, n);

    int first = -1;
    int last = -1;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            if (first == -1)
                first = i;
                else 
            last = i;
        }
    }

    if (first == -1 || first == last)
    {
        cout << "Not enough negative numbers\n";
        return;
    }

    int sum = 0;

    for (int i = first + 1; i < last; i++)
        sum += A[i];

    cout << "Sum = " << sum << endl;
   //  delete  ???
}

// вектор
void showVector()
{
    ifstream f("array.txt");

    int n;
    f >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        f >> v[i];

    cout << "Vector:\n";

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;

    f.close();
}

int main()
{
    int x;

    do
    {
        cout << "\n1 input array\n";
        cout << "2 task1\n";
        cout << "3 task2\n";
        cout << "4 task3\n";
        cout << "5 vector\n";
        cout << "0 exit\n";

        cin >> x;

        if (x == 1) inputArray();
        if (x == 2) task1();
        if (x == 3) task2();
        if (x == 4) task3();
        if (x == 5) showVector();

    } while (x != 0);

    return 0;
}

