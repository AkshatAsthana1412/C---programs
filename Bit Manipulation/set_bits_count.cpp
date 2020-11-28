// This program calculates the number of set bits in the given number in O(k) where k is the number of set bits.

using namespace std;
typedef unsigned int uint;
uint set_bits_count(uint n){
    uint c = 0;
    while (n){
        c++;
        n &= (n-1);
    }
    return c;
}