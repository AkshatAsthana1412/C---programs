#include <iostream>
using namespace std;

long long binpow(int a, int b, int m){
	long long res = 1;
	while (b != 0){
		if (b&1){
			res = (res * a) % m;
		}
		a = (a*a)%m;
		b >>= 1;
	}
	return res;
}

bool fermats_prob_prime(int n, int iter = 4){
	if (n < 4)
		return n == 2 || n == 3;
	for (int i = 0; i < iter; i++){
		int a = 2 + rand() % (n-3);
		if (binpow(a, n-1, n) != 1)
			return false;
		}
	return true;
}

int main() {
	// your code goes here
	cout << "Enter a number: ";
	int n; cin >> n;
	cout << "\nThe number is prime (1: true, 0: false): " << fermats_prob_prime(199);
	return 0;
}