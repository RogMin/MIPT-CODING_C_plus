#include <iostream>

using namespace std;
#ifndef N
#define N 5 // actual size of the array
#endif

int findLastZero(int (&arr)[N])
{
    int l = 0, r = N, mid;
    while (l < r) 
    {
        mid = (l + r) / 2; 
        if (arr[mid] == 1)
        {
            r = mid;
        } 
        else if ( arr[mid] == 0 && arr[mid+1] == 1)
        {
            return mid;
        }
        else l = mid + 1;
    }
    r--;
    return 0;
}
void writeArray(int (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
} 
int main()
{   
    int a[N];
    writeArray(a);
    findLastZero(a);
    cout << endl;
}