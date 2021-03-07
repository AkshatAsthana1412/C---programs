#include <iostream>
#include <vector>
using namespace std;

vector<bool> num(true, 1001);
vector<int> primes;
void seive(){
    num[0] = num[1] = false;
    for (int i = 2; i*i <= 1000; ++i){
        if (num[i]){
            primes.push_back(i);
            for (int j = i*i; j <= 1000; j += i)
                num[j] = false;
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    seive();
    int count = 0;
    int i = 0;
    while (primes[i] + primes[i+1] + 1 <= n){
        int pos = primes[i] + primes[i+1] + 1;
        if(num[pos]){
            cout << pos << endl;
            count ++;
        }
        i++;
    }
    if (count >= k)
        cout << "YES";
    else 
        cout << "NO";
}