#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
typedef long long ll;
 
#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

 int main(){
    ll n,l,f=-1,s;
    cin >> n >> l;
    vector<ll> a(n); 
    rep(i,n) cin >> a[i];
    rep(i,n-1){
        if(a[i]+a[i+1] >= l){
            f = i; s = i+1;
            break;
        }
    }
    if(f==-1){cout << "Impossible" << endl;}
    else{
        cout << "Possible" << endl;
        rep(i,f) cout << i+1 << endl;
        FOR(i,s,n-1) cout << n + s - i - 1 << endl;
        cout << f+1 << endl;
    }

    return 0;
 }