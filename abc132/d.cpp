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

ll powmod(ll x, ll e, ll mod){
    ll prod = 1%mod;
    for(int i=63;i>=0;--i){
        prod = prod*prod%mod;
        if(e&1LL<<i) prod=prod*x%mod;
    }
    return prod;
}

ll invmod(ll a, ll p){
    return powmod(a%p, p-2, p);
}


int main(){
    ll n,k; cin >> n >> k;
    for(long long int i=1;i<=k;i++){
        long long ans = 1;

        for(ll j=1; j<=i-1; j++){
            ans = (ans * (((k-j) * invmod(j, MOD)) % MOD)) % MOD;
        }
        for(ll j=1; j<=i ;j++){
            ans = (ans * (((n-k-j+2) * invmod(j,MOD)) % MOD)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}