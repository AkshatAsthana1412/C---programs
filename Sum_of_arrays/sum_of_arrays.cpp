#include <iostream>
using namespace std;

unsigned int sum_of_array(int *arr, int size)
{
    unsigned int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int t; cin >> t;
    for (int j = 0; j < t; j++){
        int size; cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
            cin >> arr[i];
        cout << "sum of array is: "<< sum_of_array(arr, size);
    }
}