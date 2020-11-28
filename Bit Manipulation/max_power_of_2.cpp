// this program returns the max power of 2 <= n works for numbers <= 2^32 - 1
typedef unsigned int uint;

uint max_power_of_2(uint n){
    n |= (n>>1);
    n |= (n>>2);
    n |= (n>>4);
    n |= (n>>8);
    n |= (n>>16);
    
    return (n+1) >> 1;
}