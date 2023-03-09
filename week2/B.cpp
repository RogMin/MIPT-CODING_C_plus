#include <iostream>
using namespace std;

int nul(int a)
{
    int result=0;
    for(int i = 5; i <= a; i*=5)
    {
      result+=a/i;  
    }
    return result;
}

int main(){
    int a;
    cin >> a;
    cout << nul(a);
    return 0;
}