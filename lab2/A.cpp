#include <iostream>
using namespace std;

#ifndef N
#define N 5
#endif
 
 
void forward_step(int &left, int &right, int &control, int arr[N]) 
{

    for (int i = left; i < right; i++) 
    {
        if ( arr[i] > arr[i + 1] )
        { 
            swap( arr[i], arr[i + 1]);
            control = i;
        } 
    }
    right = control;
}

void backward_step(int &left, int &right, int &control, int arr[N]) 
{
    for ( int i = right; i > left; i-- ) 
    {
        if ( arr[i - 1] > arr[i] ) 
        {
          swap( arr[i], arr[i-1] );
          control = i;  
        }
    }
    left = control;
}

void shaker_sort( int arr[N]) 
{
    int left = 0;
    int right = N-1;
    int control = N -1;
    while (left < right)
    {
        forward_step(left, right, control, arr);
        backward_step(left, right, control, arr);
    }
}

int main() {
    int arr[N];
    for ( int i = 0 ; i < N; i++ )
    {
        cin >> arr[i];
    }
    shaker_sort(arr);
    for ( int i = 0; i < N; i++ )
    {
        cout << arr[i] << " ";
    }
}




