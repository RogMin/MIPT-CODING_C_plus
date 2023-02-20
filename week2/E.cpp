#include <iostream>

using namespace std;
#ifndef N
#define N 3 // actual size of the array
#endif

void printArray(int (&arr)[2*N])
{
   for (int i = 0; i < 2* N; i++)
    {
      cout << arr[i] << " ";
    }
     cout << endl;  
}
void mergeArrays(int (&ar1)[N], int (&ar2)[N], int (&result)[2 * N])
{
    int i = 0;
    for (int j = 0; j < N; j++)
    {
        result[i] = ar1[j];
        i++;
    }
    for (int j = 0; j < N; j++)
    {
        result[i] = ar2[j];
        i++;       
    }
    int temp;
    for (int i = 0; i < 2*N - 1; i++) 
    {
        for (int j = 0; j < 2*N - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
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
    int b[N];
    int ab[N*2];
    writeArray(a);
    writeArray(b);
    mergeArrays(a,b, ab);
    cout << endl;
}