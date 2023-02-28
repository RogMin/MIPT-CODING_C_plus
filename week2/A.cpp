#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif


void reverseArray(int (&a)[N])
{
    int b[N];
    for(int i = 0; i < N; i++)
    {
        b[i] = a[N - 1 - i];
    }
    for(int i = 0; i < N; i++)
    {
        a[i] = b[i];
    }
}

void readArray(int (&a)[N])
{
    for(int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }
}

void printArray(int (&a)[N])
{
    for(int i = 0; i < N; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a[N];
    readArray(a);
    reverseArray(a);
    printArray(a);
}