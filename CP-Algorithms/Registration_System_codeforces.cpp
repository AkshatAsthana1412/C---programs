#include <iostream>
#include <map>
using namespace std;

int compute_hash(string const& s){
	int p = 31, m = 1e9 + 7;
	int hash = 0;
	int p_pow = 1;
	for (char c: s){
		hash = (hash + (c - 'a' + 1)*p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash;
}

int main() {
	// your code goes here
	int q; cin >> q;
    
	map <int, int> m;
	while (q--){
		string s;
		// cin >> s;
        getline(cin, s);
		int hash = compute_hash(s);
		if (m.find(hash) != m.end()){
			m[hash] += 1;
			cout << s + to_string(m[hash]) << endl;
		}
		else{
			cout << "OK" << endl;
			m[hash] = 0;
		}
	}
	return 0;
}