//query hackerearth for problem with the same name to read the problem statement

#include<iostream>
using namespace std;

int count1(long long int k){
    int c = 0;
    while (k){
        c ++;
        k &= (k-1);
    }
    return c;
}
void iterate_subsets(int n, int m, long long int p1[], long long int p2[], long long int p3[]){
    int c = 0;
    for (int i = 0; i < 1<<n; ++i){
        long long int r1=0, r2=0, r3=0;
        for (int j = 0; j < n; ++j){
            if (i & (1 << j)){
                r1 |= p1[j];
                r2 |= p2[j];
                r3 |= p3[j];
            }
        }
        if (count1(r1) + count1(r2) + count1(r3) == m){
            c ++;
        }
    }
    cout << c << endl;
}

int main(){
    long long int p1[20], p2[20], p3[20];
    int t; cin >> t;
    int temp;
    while (t--){
        for (int k = 0; k < 20; ++k){ //clear array after each test case else we'll run into the OR statements
            p1[k] = 0;                // with non-zero data and alter results.  
            p2[k] = 0;
            p3[k] = 0;
        }
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cin >> temp;
                if (temp){
                    if (j > 120)
                        p3[i] |= (1LL << (long long)(j-120));   // 1LL type-casts the integer literal into Long long value
                    else if (j > 60)
                        p2[i] |= (1LL << (long long)(j-60));
                    else
                    {
                        p1[i] |= (1LL << (long long)j);
                    }              
                }
            }
        }
        iterate_subsets(n, m, p1, p2, p3);
    }
}