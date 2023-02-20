#include <iostream>

using namespace std;
#ifndef N
#define N 7 // actual size of the array
#endif


void findUnique(int (&result)[N])
{
    int x = 1;
    for (int i = 0; i < N; i++)
    {
        if(( x % result[i])  == 0)
        {
            x /= result[i];
        }
        else
        {
            x *= result[i];
        }
    }
    cout << x;
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
    findUnique(a);
    cout << endl;
}