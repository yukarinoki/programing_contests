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

typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int dp[10005];
vector<ll> primes;
void fill_prime(int n){
    primes.push_back(2);
    for(int i=3;i<=n;i++){
        bool flag = true;
        for(auto x: primes) if(i%x==0){flag = false; break;}
        if(flag) primes.push_back(i);
    }
}

int main(){
    fill_prime(100000);
    COMinit();

    int n,m; cin >> n >> m;
    vector<int> pn;
    for(auto x: primes) {
        if(m%x==0){
            pn.push_back(0);
            int id = pn.size()-1;
            while(m%x==0){m /= x; pn[id]++;}
        }
    }
    if(m>1) pn.push_back(1);
    sort(all(pn));
  //  for(auto x: pn) cout << x << endl;

    ll ans = 1;
    for(auto x: pn) ans = (ans * COM(x+n-1, x)) %MOD;
    cout << ans << endl;
    return 0;
}