#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C

int main(){
    int n,q; cin >> n >> q;
    vector<long long int> a(n); for(int i=0;i<n;i++) cin >> a[i];
    vector<long long int> x(q); for(int i=0;i<q;i++) cin >> x[i];

    for(int t=0;t<q;t++){
    long long int ans = 0;
    int l = 0, r = 0;
    long long int sum = 0;
    while(l != n){
        if(r > n-1){ans = ans + r - l; sum -= a[l]; l++;}
        else if(a[r] + sum <= x[t]){sum += a[r]; r++;}
        else{ans = ans + r - l; sum -= a[l]; l++;}
    }
    cout << ans << endl;
    }
    return 0;
}