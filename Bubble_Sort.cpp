#include <vector>

void bubble_sort(std::vector<int> arr){
    int flag = 0;
    int temp;
    for (int i = 0; i < arr.size()-1; i ++){    
        for (int j = 0; j < arr.size()-i; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }    
        }
        if (flag){
            flag = 0;
        }    
        else{
            break;
        }
    }
}