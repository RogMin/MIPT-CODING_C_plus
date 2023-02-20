#include <iostream>

using namespace std;
#ifndef N
#define N 10 // actual size of the array
#endif

void shiftRight(int (&a)[N], unsigned k)
{
    int b;
    int m[N];
    for (int i = 0; i < N; i++)
    {
        m[i] = a[i];
    }
    for (int i = 0; i < N; i++)
    {
        b = k + i;
        while (b > N - 1)
        {
            b = b - N;
        }
        a[b] = m[i];
    }
}

int main()
{
    unsigned k;
    int a[N];
    cin >> k;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    shiftRight(a, k);
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}