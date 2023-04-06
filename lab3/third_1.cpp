#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#ifndef M
#define M 1
#endif
using namespace std;

enum Direction
{
 left = 1,
 right = 2,
};

struct Cell
{
    bool isStopped;
    Direction direction;
    int x;
};

int RandomNumbInRange(int min, int max)
{
    std::random_device rd;    
    std::mt19937 rng(rd());    
    std::uniform_int_distribution<int> uni(min,max);
    return uni(rng);
}

void SetDirection(Cell (&cells)[M], int N)
{
    for (int i = 0; i < N; i++)
    {
        int dir = RandomNumbInRange(1, 2);
        switch(dir)
        {
            case 1:
            cells[i].direction = Direction::left;
            break;
            case 2:
            cells[i].direction = Direction::right;
            break;
            default:
            cout << "Unknown direction";
            break;
        }
    }
}


void MoveCells(Cell (&cells)[M], int &exit_tick, int N)
{
    int flag;
    for (int k = 0; k < N; ++k)
    {
        flag = 0;
        if (!cells[k].isStopped)
        {
            if (cells[k].direction == 1)
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].x - 1) == cells[i].x))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].x--;
                    exit_tick = 1;
                }
            }
            else
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].x + 1) == cells[i].x))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].x++;
                    exit_tick = 1;
                }
            }
        }
    }
}

void Stop(Cell (&cells)[M], int X, int N)
{
    for (int k = 0; k < N; ++k)
    {
        if (!cells[k].isStopped)
        {
            if ((cells[k].x == 0) or (cells[k].x == (X - 1)))
            {
                cells[k].isStopped = true;
            }
            else
            {
                for (int i = 0; i < N; ++i)
                {
                    if (abs(cells[i].x - cells[k].x) == 1)
                    {
                        cells[k].isStopped = true;
                    }
                }
            }
        }
    }
}

void Tick(Cell (&cells)[M], int &exit_tick, int X, int N, int &counter)
{
    exit_tick = 0;
    Stop(cells, X, N);
    SetDirection(cells, N);
    MoveCells(cells, exit_tick, N);
    counter++;
}

int main()
{
    int X = 100;
    int exit_tick = 1;
    int N = 1;
    Cell cells[M];
    int step_counter = 0;
    while (X < 5000)
    {
        step_counter = 0;
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i < 100; ++i)
        {
            exit_tick = 1;
            cells[0].isStopped = false;
            cells[0].x = X / 2;
            while (exit_tick == 1)
            {
                Tick(cells, exit_tick, X, N, step_counter);
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << X << "," << (static_cast<float>(time_span.count()) / static_cast<float>(100)) << "," << (static_cast<float>(step_counter) / static_cast<float>(100)) << std::endl;
        X = X + 20;
    }
    return 0;
}