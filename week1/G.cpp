#include <iostream>
using namespace std;

int main(){
    int N, b, a, c, min=0, max=0;
    cin >> N;
    cin >> a >> b;
    while(N-2 >0)
    {
        cin >> c;
        if (b>=a && b >=c )
        {
            max++;
        }
        else if (b<=a && b<=c)
        {
            min++;
        }
        a = b;
        b = c;
        N--;
    }
    if (max > min)
    {
        cout << "MAX";
    }
    else if (min > max)
    {
        cout << "MIN";
    }
    else
    {
        cout << "EQUAL";
    }
    return 0;
}