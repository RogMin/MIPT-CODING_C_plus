#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif

int findLastZero(int (&a)[N])
{
    int start_point = 0, end_point = N - 1;
    int point;
    while (end_point - start_point > 2)
    {
        point = (end_point - start_point) / 2 + start_point;
        if (a[start_point] == 0 and a[point] == 1)
        {
            end_point = point;
        }
        else
        {
            start_point = point;
        }
    }
    if (end_point - start_point == 2)
    {
        if (a[start_point + 1] == 0)
        {
            return start_point + 1;
        }
        else
        {
            return start_point;
        }
    }
    else
    {
        return start_point;
    }
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
    int answer = findLastZero(a);
    std::cout << answer << std::endl;
}
