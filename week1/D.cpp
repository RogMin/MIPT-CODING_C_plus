#include <iostream>
using namespace std;

int main()
{
    int N, b, a, min=0, max=0;
    cin >> N;
    cin >> a;
    while(N - 1> 0)
    {
        cin >> b;
        if (b>a)
        {
            max++;
        }
        else
        {
            min++;
        }
        a=b;
        N--;
    }
    if (max > min)
    {
        cout << "MAX";
    }
    else if( max = min)
    {
        cout << "EQUAL";
    }
    else
    { 
        cout << "MIN";
    }
    return 0;
}