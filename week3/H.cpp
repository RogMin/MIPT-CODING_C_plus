#include <iostream>
using namespace std;

#ifndef N
#define N 2
#endif

#ifndef M
#define M 4
#endif

void writeArray(int (&a)[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> a[i][j];
        }       
    }
} 

void printTransponsed(int (&AT)[M][N])
{
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cout << AT[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray(int(&arr)[N+M])
{
    for (int i=0; i<N+M; i++)
    {
        cout << arr[i] << " ";
    }
}

void printAndTranspose(int (&A)[N][M])
{
    int AT[M][N];
    for(int j = 0; j < M; ++j)
    {
        for(int i = 0; i < N; ++i)
        {
            AT[j][i] = A[i][j];
        }
    }
    printTransponsed(AT);
}
int main(){
    int a[N][M];
    writeArray(a);
    printAndTranspose(a);
    return 0;
}