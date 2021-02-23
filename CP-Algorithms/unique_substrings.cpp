//counts the number of unique substrings in a given string
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<int> hashes(string s){
    int n = s.length();
    vector <int> hs(n+1);
    int m = 1e9 + 9, p = 31;
    int p_pow = 1;
    hs[0] = 0;
    for (int i = 1; i < n+1; i++){
        hs[i] = (hs[i-1] + (s[i-1] - 'a' + 1)*p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hs;
}

void no_of_substrings(string s){
    int c = 0;
    int p = 31, m = 1e9 + 9;
    int n = s.length();
    vector<int> hs = hashes(s);
    vector <long long> pow(n+1, 1);
    for (int i = 1; i < n+1; i++)
        pow[i] = (pow[i-1] * p) % m;
    for (int l = 1; l < n+1; l++){
        set<int> hash_group;
        int hash = 0;
        for (int k = 0; k < n-l+1; k++){
            hash = ((hs[k+l] - hs[k]) * pow[n-k]) % m;
            hash_group.insert(hash);
        }
        c = hash_group.size();
        cout << "The number of unique substrings of length: " << l << " are " << c << endl;
    }
}

int main(){
    string s;
    getline(cin, s);
    no_of_substrings(s);
}