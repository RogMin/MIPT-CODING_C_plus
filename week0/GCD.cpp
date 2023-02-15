#include <iostream>
using namespace std;

int main() 
{
    int a, b, c;
    cin >> a >> b;
    while (a%b != 0)
    {   
        if (a%b == a)
        {
        c = a;
        a = b;
        b = c;
        }
        a = a-b;
    }
    cout << b << endl;
    return 0;
}    