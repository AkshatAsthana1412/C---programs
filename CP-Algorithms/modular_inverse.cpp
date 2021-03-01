#include <iostream>

using namespace std;

int extended_euclids(int a,int b,int &x,int &y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_euclids(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b) * y1;
    return g;
}
int main(){
    int x, y, a, m;
    cout << "Enter the values of a and m, to find inv[a] mod m: ";
    cin >> a >> m;
    int g = extended_euclids(a, m, x, y);
    if (g!=1){
        cout << "\nModular inverse doesn't exist for the pair.";
    }
    else{
        cout << "\nThe modular inverse of "<< a << " is: " << (x%m + m) % m;
    }
    return 0;
}