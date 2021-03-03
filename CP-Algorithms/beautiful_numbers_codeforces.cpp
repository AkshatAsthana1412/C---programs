#include <iostream>
#include <cmath>
using namespace std;

bool check_digits(int n, int a, int b){
    int temp = n;
    while(temp > 0 && (temp%10 == a || temp%10 == b)){
        temp /= 10;
    }
    return temp == 0;
}

int extended_euclids(int a, int b, int &x, int &y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_euclids(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return g;
}

long long inverse(int a, int m){
    int x, y;
    int g = extended_euclids(a, m, x, y);
    if (g!=1){
        cout << "Inverse doesn't exist";
        exit(0);
    }
    else{
        return (x%m + m)%m;
    }
}

long long fact(int x, int m){
    long long res = 1;
    while (x--){
        res = res * x % m;
    }
    return res;
}

int main(){
    int a, b, n, x, y;
    int m = 1e9 + 7;
    cin >> a >> b >> n;
    long long ans = 0;
    for (int c = a*n ; c <= b*n; c++){
        if (check_digits(c, a, b)){
            int g = extended_euclids(a,b,x,y);
            a /= g;
            b /= g;
            if (c % g)
                continue;
            else{
                x *= c;
                y *= c;
                int k = (n - x - y)/(a - b);
                x = x - k*b;
                y = y + k*a;
                // cout << x << ' ' << y << endl;
                ans += fact(n, m) * inverse(fact(x, m) * fact(y, m), m) % m;
            }
        }
    }
    cout << ans <<endl;
}
