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
        int max = -1;
        rep(i,n)
        if(max < a[i]) max = a[i]; 
        cout << max << endl;
    }
    return 0;
}
