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
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans=0, tsum=0;
    rep(i,n){
        if(a[i]==0){ 
            ans += tsum / 2;
            tsum=0;
        }else{
            tsum += a[i];
        }
    }
    cout << ans + (tsum / 2) << endl;
    return 0;
}