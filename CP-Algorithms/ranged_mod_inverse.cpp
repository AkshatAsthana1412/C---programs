#include <iostream>
using namespace std;

//the results will be valid only if m is prime, because for a modular inverse to exist
//for a pair, the pair must be coprime
int main(){
    int m;
    cout << "Enter the number upto which to calculate modular inverse: ";
    cin >> m;
    int inv[m];
    inv[1] = 1;
    for (int i = 2; i < m; i++)
        inv[i] = m - (m/i * inv[m%i]) % m;
    
    cout <<"\nThe modular inverses from 1 to " << m << " are: \n";
    for (int i = 1; i < m; i++)
        cout << inv[i] << ' ';
}