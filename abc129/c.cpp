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
long long int dp[100005];
int main(){
    int n,m; cin >> n >> m;
    vector<int> a(m); rep(i,m) cin >> a[i];
    rep(i,m-1) if(a[i]+1==a[i+1]){ cout << 0 << endl; return 0;}
    vector<bool> b(n+1); rep(i,n) b[i] = false;
    rep(i,m) b[a[i]] = true;
    rep(i,100005) dp[i] = 0;
    dp[0] = 1;
    for(int i=1;i <= n ;i++){
        if(b[i]) continue;
        if(i-1 >= 0 && !b[i-1]) dp[i] = (dp[i] + dp[i-1]) % MOD;
        if(i-2 >= 0 && !b[i-2]) dp[i] = (dp[i] + dp[i-2]) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}