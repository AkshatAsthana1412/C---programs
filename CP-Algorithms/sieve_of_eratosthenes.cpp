#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cout << "Enter a number: \n";
    cin >> n;
    vector<char> is_prime(n+1, true); //or use vector<bool>
    for (int i = 2; i*i <= n; i++){
        if (is_prime[i]){
            for (int j = i*i; j <= n; j+=i)
                is_prime[j] = false;
        }
    }

    cout << "The prime numbers from 1 to " << n << " are:\n";
    for (int i = 2; i <= n; i++){
        if (is_prime[i])
            cout << i << endl;
    }
}