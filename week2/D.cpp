#include <iostream>

using namespace std;
#ifndef N
#define N 5 // actual size of the array
#endif


void printArray(int (&arr)[N])
{
   for (int i = 0; i < N; i++)
    {
      cout << arr[i] << " ";
    }
     cout << endl;  
}
void moveNegativeToEnd(int (&arr)[N])
{
    int result[N];
    int j=-1;
    for(int i : arr)
    {  
     
     if(i < 0)
     {
        j++;
        result[j] = i;
     }
    }
    for(int i : arr)
    {

     if(i >= 0)
     {
         j++;
        result[j] = i;
     }
    }
    printArray(result);
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
    moveNegativeToEnd(a);
    cout << endl;
}