#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> get_primes(int R){
    int lim = sqrt(R);
    vector<int> mark(lim+1, false);
    vector<int> primes;
    for (int i = 2; i <= lim; ++i){
        if (!mark[i]){
            primes.push_back(i);
            for (int j = i*i; j <= lim; j+=i)
                mark[j] = true;
        }
    }
    return primes;
}

int main(){
    int R, L;
    cout << "Enter the endpoints of the range: \n";
    cin >> L >> R;
    vector<int> is_prime(R-L+1, true);
    vector<int> primes = get_primes(R);
    for (int i: primes){
        for (int j = max(i*i, (L+i-1)/i*i); j <= R; j+=i){
            is_prime[j-L] = false;
        }
    }
    if (L == 1)
        is_prime[0] = false;
        
    cout << "The primes in range "<< L << " " << R << " are \n";
    for (int i = 0; i < R-L+1; i++){
        if (is_prime[i])
            cout << i+L << endl;
    }
}