#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))
#define MOD 1000000007
typedef long long ll;

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> x(n), y(m); rep(i,n) cin >> x[i]; rep(i,m) cin >> y[i];
    long long int ax=0,ay=0;
    rep(i,n-1) ax = (ax + (((i+1) * (n-i-1) * (x[i+1]-x[i])) % MOD)) % MOD;
    rep(i,m-1) ay = (ay + (((i+1) * (m-i-1) * (y[i+1]-y[i])) % MOD)) % MOD;
    cout << (ax*ay)%MOD << endl;
    return 0;
}