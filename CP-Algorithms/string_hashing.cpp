#include <string>
#include <iostream>
long long compute_hash(std::string s){
    const int m = 1e9 + 9;
    const int p = 31;
    long long hash = 0;
    int p_pow = 1;
    for (char c: s){
        hash = (hash + (c - 'a' + 1)*p_pow) % m;
        p_pow = (p_pow*p) % m;
    }
    return hash;
}

int main(){
    std::string s;
    std::cout << "Enter a string: \n";
    std::getline(std::cin, s);
    std::cout << "Hash of " << s << " is: " << compute_hash(s);
}