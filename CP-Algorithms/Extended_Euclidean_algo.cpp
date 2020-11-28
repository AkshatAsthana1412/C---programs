#include <iostream>
using namespace std;
int extended_euclids(int a, int b, int &x, int&y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_euclids(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int main(){
    int a, b;
    cout << "enter two intgers: \n";
    cin >> a >> b;
    int x = 0, y = 0;
    cout << "The gcd of the numbers is: " << extended_euclids(a,b,x,y) << endl;
    cout << "x = " << x << "y = " << y << endl;
}
