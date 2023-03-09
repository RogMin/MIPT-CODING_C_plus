#include <iostream>
using namespace std;

int recursive_power(int base, int power)
{
    if (power == 0)
    {
        return 1;
    } 
    else if(power > 0)
    {
        return base*recursive_power(base, power-1);
    }
    return 0;
}

int main(){
    int base, power;
    cin >> base >> power;
    cout << recursive_power(base, power);
    return 0;
}