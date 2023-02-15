#include <iostream>
using namespace std;

int revers(int N)
{
    int M=0;
    while(N != 0)
    {
        M = M*10 + (N%10);
        N = N/10;
    }
    return M;
}

int main()
{
    int N;
    cin >> N;
    if (N==revers(N)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
