// visit hackerearth and search for a problem with the same name for the problem statement

// concepts:
//     f(2k+1) = 2k+1
//     f(2k) = f(k)
//     sum of n odd numbers = n^2

// approach: 
//     among n numbers there are n/2 odd and n/2 even numbers if n is even, if n is odd there are n//2 + 1 odd numbers;
//     after we've calculate the sum of n/2 + n%2 odd numbers, there remain n//2 even numbers for each of them f(2k) = k
//     so we divide all numbers by 2, we're again left with consecutive integers from 1 to n//2 and so we repeat the same process
//     until n reduces to 0.

// the program takes O(log n) time for each test case


#include <iostream>
typedef unsigned long long int ullong;
using namespace std;

ullong sqr(ullong a, ullong b){
    a %= b;
    return (a*a) % b;
}

int main(){
    int t; cin >> t;
    ullong n, m;
    while (t--){
        cin >> n >> m;
        ullong s = 0;
        do{
            s = (s + sqr(n/2 + n%2, m)) % m;
        }while(n >>= 1);
        cout << s << endl;
    }
}