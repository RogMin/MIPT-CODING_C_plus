#include <iostream>
using namespace std;

int main(){
    int a = 0, b = 0, c;
    cin >> c;
    while (a + b <= c)
    {
        while (a + b <= c)
        {
            if (a*a + b*b == c)
            {
                break;
            }
            b++;
        }
        if (a*a + b*b == c)
        {
            break;
        }
        else
        {
            a++;
            b = 0;
        }
    }
    if (a*a + b*b == c)
    {
        cout << a << " b = " << b << endl;
    }  
    else 
    {
        cout << "Нет решений" << endl;
    }
    return 0;
}