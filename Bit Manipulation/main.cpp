#include<iostream>
#include "bit_manipulation.h"
typedef unsigned int uint;
using namespace std;

int main(){
    cout << "enter the value of n: \n";
    uint n; cin >> n;
    cout << "\nenter the value of i: \n";
    uint i; cin >> i;
    cout << "check ith bit " << check_ith_bit(n,i) << endl;
    cout << "check power of 2 " << check_power_of_2(n) << endl;
    cout << "max power of 2 " << max_power_of_2(n) << endl;
    cout << "set bits count " << set_bits_count(n) << endl;
}