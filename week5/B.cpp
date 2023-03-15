#include <iostream>

int main()
{
    short int *pa;
    pa = new short int[10];
    for (int i = 0; i < 10; i++)
    {
        pa[i] = i;
        std::cout << " " << pa + i;
    }
    std::cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << " " << pa[i];
    }
    std::cout << "\n";
    for (int i = 0; i < 10; i +=2)
    {
        std::cout << " " << (*(pa +i)) * (*(pa +i));
    }

    
}

