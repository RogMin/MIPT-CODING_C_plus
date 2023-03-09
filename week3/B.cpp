#include <iostream>

using namespace std;
#ifndef N
#define N 6 // actual size of the array
#endif

void shiftRight(int (&a)[N])
{
    int res[N];
    res[0] = a[N-1] ;
    for (int i = 1; i < N; i++)
    {
        res[i] = a[i-1];
        
    }
    for (int i = 0; i < N; i++)
    {
      cout << res[i] << " ";
    }
    
     cout << endl;
}
int main()
{
    int arr[N];  
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }    
    shiftRight(arr);    
    return 0;
}
