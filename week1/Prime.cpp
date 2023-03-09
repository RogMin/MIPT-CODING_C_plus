#include <iostream>
using namespace std;

int main() 
{
    int i=2, p;
    cin >> p;
    while( p%i != 0 && i<p/2)
    {
        i++;
    }
    i == p/1.4 ? (cout << "Is not Prime") : (cout << "Is Prime") ;
    return 0;
}    