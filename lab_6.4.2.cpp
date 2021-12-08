#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int n, int i)
{
    if (i < n)
    {
        a[i] = -5 + rand() % 10;
        Create(a, n, i + 1);

        return;
    }
}

void Print(int* a, const int n, int i)
{
    if (i < n)
    {
        if (i == 0)
            cout << "[";
        cout << a[i];
        if (i != n - 1)
            cout << ", ";
        else
            cout << "]" << endl;
        Print(a, n, i + 1);

        return;
    }
}

int Sum(int* a, const int n, int i)
{
    if (i < n)
    {
        if (a[i] < 0)
            return a[i] + Sum(a, n, i + 1);
        else
            return  Sum(a, n, i + 1);
    }
    else
        return 0;
}


void Max(int* a, const int n, int& max, int& imax, int i)
{
    if (i < n)
    {
        if (a[i] > max)
        {
            max = a[i];
            imax = i;
        }
        Max(a, n, max, imax, i + 1);
    }

}

void Min(int* a, const int n, int& min, int& imin, int i)
{
    if (i < n)
    {
        if (a[i] < min)
        {
            min = a[i];
            imin = i;
        }
        Min(a, n, min, imin, i + 1);
    }
}

int Dob(int* a, const int n, int i)
{
    if (i < n)
    {
        return a[i] * Dob(a, n, i + 1);
    }
    else
        return 1;
}

void Sort(int* a, const int n, int i, int j)
{
    if (a[i] > a[i + 1])
    {
        int tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
    }
    if (i < n - j - 1)
        Sort(a, n, j, i + 1);

    if (j < n - 1)
        Sort(a, n, i, j + 1);
}

int main()
{
    srand(time(0));

    int n;
    cout << "n = "; cin >> n;
    int* a = new int[n];

    Create(a, n, 0);
    int max = a[0], min = a[0], imax = 0, imin = 0;
    Print(a, n, 0);

    Min(a, n, min, imin, 0);
    Max(a, n, max, imax, 0);
    cout << "imin = " << imin << endl;
    cout << "imax = " << imax << endl;

    int D = 1;
    if (imin < imax)
        D = Dob(a, imax, imin + 1);
    else
        D = Dob(a, imin, imax + 1);
    cout << "D = " << D << endl;

    cout << "S = " << Sum(a, n, 0) << endl;

    Sort(a, n, 0, 0);
    Print(a, n, 0);

    return 0;
}
