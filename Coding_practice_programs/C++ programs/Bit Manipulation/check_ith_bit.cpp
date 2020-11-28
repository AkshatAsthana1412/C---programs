// This program checks whether the ith bit is set in the given number
typedef unsigned int uint;
bool check_ith_bit(uint n, uint i){
    return (n & (1<<i)) == 1;
}