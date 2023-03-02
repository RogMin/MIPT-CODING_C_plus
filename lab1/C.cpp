using namespace std;
#include <iostream>
#include <chrono>
#include <random>
#include<vector>
const int N = 1e4;
int a[N];
int b[N];
int c[N];
int pick[N];
int cnt[N];

bool linfind(int n, int x) 
{
    for (int j = 0; j < n; j++) 
    {
        if (pick[j] == x) return true;
    }
    return false;
}
bool strategyC(int n, int x) 
{
    for (int i = 0; i < n; i++) 
    {
        if (c[i] == x) 
        {
            cnt[c[i]]++;
            if (i > 0 && cnt[c[i]] > cnt[c[i - 1]]) swap(c[i], c[i - 1]);
            return true;
        }
    }
    return false;
}

bool strategyB(int n, int x) 
{
    for (int i = 0; i < n; i++) 
    {
        if (b[i] == x) 
        {
            if (i > 0) swap(b[i], b[i - 1]);
            return true;
        }
    }
    return false;
}

bool strategyA(int n, int x) 
{
    for (int i = 0; i < n; i++) 
    {
        if (a[i] == x) 
        {
            if (i != 0) swap(a[i], a[0]);
            return true;
        }
    }
    return false;
}

double CountTime(int n, char temp, bool distrRaw=true) 
{
    int qnt = min(n, 10000);
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    int to = n;
    if (!distrRaw) to = n / 10; // неравномерное распределение данных
    std::uniform_int_distribution <unsigned> dstr(0, to);
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = qnt; cnt > 0; --cnt) 
    {
        int x = pick[dstr(rng)];
        if (temp == 'A') strategyA(n, x);          
        if (temp == 'B') strategyB(n, x);           
        if (temp == 'C') strategyC(n, x);          
        if (temp == 'N') linfind(n, x);       
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    double time_taken = time_span.count(); 
    return (double)time_taken / (double)qnt;
}
void setData(int n)
{
 for (int i = 0; i < n; ++i) 
    {
        a[i] = i;
        b[i] = i;
        c[i] = i;
        cnt[i] = 0;
        pick[i] = i;
    }
}
void printResult(int n) 
{
    setData(n);
    double A, B, C, N;
    A = B = C = N = 0.0;
    setData(n);
    N = CountTime(n, 'A', true); // обычный случай. с C/B/A 
    cout << n << " " << CountTime(n, 'A', false) << " " << CountTime(n, 'B', false) << " " << N << "\n";
    return;
}
int main() 
{   
    freopen("Cdata.txt","w",stdout);
    cout.precision(10);
    for (auto n = 2000; n <= 10000; n *= 1.2)
    {
        printResult(n); 
    }
    fclose(stdout);
    return 0;
}
