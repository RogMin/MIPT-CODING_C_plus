#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c, d;
    cin >> a >> b >> c;
    if (a == 0 && b!=0)
    {
        cout << (-c/b);
        return 0;
    }
    else if( a != 0 && b != 0)
    {
        d = (b*b) - (4*a*c);
        if(d == 0)
        {
            cout << (-b/2*a);
            return 0;
        }
        else if(d>0)
        {
            cout << (-b + sqrt(d))/(2*a)  << ' '  << (-b - sqrt(d))/(2*a);
            return 0;
        }
    }
    cout << "None";
    return 0;
}