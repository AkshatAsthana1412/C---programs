// To read the problem statement, query hackerearth for the problem of the same name

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, temp, m = pow(10, 9) + 7; //1000000007
    cin >> n;                       //input size of array
    unsigned int ans = 1;           //since the answer may overflow the signed int(which is default int).
    for (int i = 0; i < n; i++){
        cin >> temp;
        ans = (ans * temp) % m;     //no need to create array of size n, we can store input in temp,  
                                    //process it and then overwrite it with the next input number.   
    }
    cout << ans;
}