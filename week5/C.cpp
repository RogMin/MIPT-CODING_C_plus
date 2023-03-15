#include <iostream>
using namespace std;

int main() {
    int* arr = nullptr;
    int size = 0;
    int num;

    while (std::cin >> num && num != 0) 
    {
        ++size;
        int* temp = new int[size];
        for (int i = 0; i < size - 1; ++i) 
        {
            temp[i] = arr[i];
        }
        temp[size - 1] = num;
        delete[] arr;
        arr = temp;
    }

    for (int i = 1; i < size; ++i) 
    {
        std::cout << arr[i-1] - arr[i] << " ";
    }

    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;
}