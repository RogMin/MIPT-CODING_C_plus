#include <iostream>
#include <chrono>
#include <random>
#include <math.h>
const int N = 1000;
int swap_counter = 0;

void insert_sort_gap(int (&a)[N], int const begin, int const end, int gap)
{
    for (int i = gap; i < end; i++)
    {
        int temp = a[i];
        int k = i;
        for (; (k >= gap) && (a[k - gap] > temp); k -= gap)
        {
            a[k] = a[k - gap];
            swap_counter++;
        }
        swap_counter++;
        a[k] = temp;
    }
}

void shell_sort(int (&a)[N], int k)
{
    int m = k / 2;
    while (m != 0)
    {
        insert_sort_gap(a, 0, k, m);
        m = m / 2;
    }
}

int main()
{
    int a[N];
    for (int k = 10; k < N; k = k + 10)
    {
        swap_counter = 0;
        double av = 0;
        for (int i = 0; i < 100; i++)
        {
            std::default_random_engine rng(i);
            std::uniform_int_distribution<int> dstr(0, k);
            for (int j = 0; j < k; j++)
            {
                a[j] = dstr(rng);
            }
            auto begin = std::chrono::steady_clock::now();
            for (unsigned cnt = 100; cnt != 0; --cnt)
            {
                shell_sort(a, k);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            av = av + time_span.count();
        }
        av = av / 100;
        swap_counter = swap_counter / 10000;
        std::cout << k << "," << av << "," << swap_counter << std::endl;
    }
    return 0;
}