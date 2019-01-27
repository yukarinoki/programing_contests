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
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll ans=0;
    rep(k,30){
        ll t = 1 << k;
        vector<ll> sa(n);
        vector<ll> sb(n);
        rep(i,n) sa[i] = a[i] % (2 * t);
        rep(i,n) sb[i] = b[i] % (2 * t);
        sort(ALL(sb));
        ll no=0;
        rep(i,n){
            no += upper_bound(ALL(sb), 4 * t - sa[i] - 1) - lower_bound(ALL(sb), 3 * t - sa[i]);
            no += upper_bound(ALL(sb), 2 * t - sa[i] - 1) - lower_bound(ALL(sb), t - sa[i]);   
        }
        ans |= (no % 2) << k;
    }
    
    cout << ans << endl;
    return 0;
}