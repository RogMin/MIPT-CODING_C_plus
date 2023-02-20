#include <iostream>

using namespace std;
#ifndef N
#define N 3 // actual size of the array
#endif

void reverseArray(int (&a)[N])
{
    for (int i = F-1; i > -1 ; i--)
    {
       cout << a[i] << " ";
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
    reverseArray(arr);    
    return 0;
}
