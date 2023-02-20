#include <iostream>

using namespace std;
#ifndef F
#define F 6 // actual size of the array
#endif

void shiftRight(int (&a)[F])
{
    int res[F];
    res[0] = a[F-1] ;
    for (int i = 1; i < F; i++)
    {
        res[i] = a[i-1];
        
    }
    for (int i = 0; i < F; i++)
    {
      cout << res[i] << " ";
    }
    
     cout << endl;
}
int main()
{
    int arr[F];  
    for (int i = 0; i < F; i++)
    {
        cin >> arr[i];
    }    
    shiftRight(arr);    
    return 0;
}
