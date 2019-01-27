#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int main(){
    int n;
    ll sum=0;
    cin >> n;
    vector<ll> a(n+2);
    FOR(i,1,n+1) cin >> a[i];
    a[0] = 0;
    a[n+1] = 0;
    rep(i,n+1){
        sum += a[i] < a[i+1] ? a[i+1] - a[i] : a[i] - a[i+1];
    }
   // cout << "sum" << sum << endl;
    FOR(i,1,n+1){
        //cout << i << " : "<< (a[i+1]-a[i]) << endl;
        if(((a[i+1]-a[i]) <= 0 && (a[i]-a[i-1]) <= 0) || ( (a[i+1]-a[i]) >= 0 && (a[i]-a[i-1]) >= 0))  cout << sum << endl;
        else cout << sum - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]) + abs(a[i+1]-a[i-1]) << endl;
    }

    return 0;
}