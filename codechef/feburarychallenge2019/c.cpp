#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)


int main(){
    long long int t; cin >> t;
    rep(kk,t){
        int n; cin >> n;
        int a[n]; rep(i,n) cin >> a[i];
        int b[n]; rep(i,n) cin >> b[i];
        int max = -1;
        rep(i,n)
        if(b[i] > a[(i - 1 + n) % n] + a[(i+1) % n] && max < b[i]) max = b[i]; 
        cout << max << endl;
    }
    return 0;
}
