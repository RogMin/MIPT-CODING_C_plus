#include <iostream>
using namespace std;

int my_power(int base, int power)
{
    int s=1;
    while (power>0)
    {
        s*=base;
        power--;
    }
    return s;
}

int main()
{
    int base, power;
    cin >> base >> power;
    cout << my_power(base, power);
    return 0;
}