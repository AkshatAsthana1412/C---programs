#include <iostream>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    int arr[1000];
    while (t--){
        int n, x;
        cin >> n >> x;
        int odds = 0;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if (arr[i] % 2){
                odds ++;
            }
        }
        int evens = n - odds;
        int max_odds = min(odds - (odds+1)%2, x - (x+1)%2);
        if (max_odds >= 1 && max_odds + evens>= x)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}