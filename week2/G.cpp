#include <iostream>
#ifndef N
#define N 5 // actual size of the array
#endif

int findUnique(int (&a)[N])
{
    int b = a[0];
    for (int i = 1; i < N; i++)
    {
        b ^= a[i];
    }
    return b;
}

void readArray(int (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }
}

void printArray(int (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a[N];
    readArray(a);
    int b = findUnique(a);
    std::cout << b << std::endl;
}