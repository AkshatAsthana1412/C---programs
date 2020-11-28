//Query hackerrank with the name of this module for problem statement

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    //creating the dq, the front element in the dq will be the largest element in the          current window and the last element the smallest
    deque <int> d;
    //storing initial value in the dq
    d.push_back(0);

    //iterating through the first k elements and storing the largest value index at the         front of the dq
    for (int i = 1; i < k; i++){
        while (!d.empty() && (arr[d.back()] < arr[i]))
            d.pop_back();
        d.push_back(i);
    }
    //print the largest element in the first window
    cout << arr[d.front()] << ' ';
    
    //iterating through the rest of the array
    for (int j = k; j < n; j++){
        //pop the front element if it is out of the current window
        if (j - d.front() == k)
            d.pop_front();

        //insert new element at its right place in the dq
        while (!d.empty() && arr[j] > arr[d.back()])
            d.pop_back();
        d.push_back(j);

        //print the largest element in the current window
        cout << arr[d.front()] << ' ';
    }
    cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
