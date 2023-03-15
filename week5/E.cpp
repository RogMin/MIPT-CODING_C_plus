#include <iostream>
using namespace std;

bool reserve_memory(size_t N, int* ptr) {
    if (N) {
        ptr = new int[N];
        return true;
    }
    else return false;
}


void free_memory(int* ptr) {
    if (ptr)
        delete [] ptr;
}

int main() {
    size_t N = 0;
    int* ptr = nullptr;
    cin >> N;
    cout << reserve_memory(N, ptr) << endl;
    free_memory(ptr);
    return 0;
}