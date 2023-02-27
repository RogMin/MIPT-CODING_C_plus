using namespace std;
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#ifndef N
#define N 100000000
#endif

void search_sort(long long arr[N], long long n, long long num) 
{
	for (long long i = 0; i < num; i++) 
    {
        for (long long j = 0; j < num; j++)
        {
		    if (arr[i] + arr[j] == n && i != j) 
            {
			    j = num+1;
		    }
        }
	}
}
void search_linear(long long arr[N], long long n, long long num) 
{
  int first = 0;
  int last = num - 1;
  int sum;
  while (first < last) 
  {
    sum = arr[first] + arr[last];
    if (sum == n) 
    {
      break;
    } 
    else 
    {
      if (sum < n) {first++;}
      else {last--;};
    }
  }
}
int main() 
{
    ofstream f("D:/C++/MIPT-CODING_C_plus/lab1/B.text", ios::out);
    long long num = 100;
	int unsigned seed = 1001;
	default_random_engine rng(seed);
	long long* arr = new long long[N];
	for (long long i = 0; i < N; i++) 
    {
		arr[i] = i;
	}
	for(num;num<=N;num *=2){
	    uniform_int_distribution<unsigned> dstr(0, num-1);
	    auto begin = chrono::steady_clock::now();
	    for (unsigned long long cnt = 1000000; cnt != 0; --cnt) 
        {
		    search_linear(arr, arr[dstr(rng)], num);
	    }
	    auto end = chrono::steady_clock::now();
	    auto time_span = chrono::duration_cast<chrono::milliseconds>(end - begin);
	    cout << "\n\n";
	    cout << time_span.count()<<' '<<num << endl;
	    f << time_span.count()<<' '<<num << endl;
	}
	return 0;
}
