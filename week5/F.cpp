#include <iostream>
#include <cstring>
using namespace std;

char *resize(const char *buf, size_t size, size_t new_size) {
    if (new_size == 0) {
        delete[] buf;
        return nullptr;
    }
    char* new_buf = new char[new_size];
    size_t copy_size = min(size, new_size);
    for (size_t i = 0; i < copy_size; i++) {
        new_buf[i] = buf[i];
    }
    delete[] buf;
    return new_buf;
}

int main() {
    size_t size, new_size;
    cin >> size >> new_size;
    char* a = new char[size];
    
    for (size_t i = 0; i < size; i++) {
        cin >> a[i];
    }
    
    char* new_arr = resize(a, size, new_size);
    
    for (size_t i = 0; i < new_size; i++) {
        cout << new_arr[i] << " ";
    }
    cout << endl;
    
    delete[] new_arr;
    
    return 0;
}
