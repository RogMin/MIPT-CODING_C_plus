#include <iostream>

using namespace std;
#ifndef N
#define N 4 // actual size of the array
#endif

void printArray(int (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout <<endl;
}
void selectSort(int (&a)[N])
{
   int max = 0;
   int j = 0;
   for (int i = 0; i < N; i++)
   {
    max = a[i]; 
    j = i-1;
    while(j > 0 && a[j] > max)
    {
        a[j+1] = a[j];
        j = j-1;
    }
    a[j+1] = max;
   }
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
    selectSort(a);
    printArray(a);
    return 0;
}
