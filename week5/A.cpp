#include <iostream>

int main()
{
    double a = -5;
    double *pa = &a;
    *pa = 0;
    std::cout << "\n" << pa;
    std::cout << "\n"<< *pa;
    std::cout << "\n"<< (pa-3);
    std::cout << "\n"<< *(pa-3);
    std::cout << "\n"<< (pa+5);
    std::cout << "\n"<< *(pa+5);
}

