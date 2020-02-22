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


int dp[10005];
int main(){
    int h,n; cin >> h >> n;
    vector<int> a(n),b(n); rep(i,n) cin >> a[i] >> b[i];
    rep(i,10005) dp[i] = INF;
    dp[h] = 0;
    for(int i=h; i>=1;i--) for(int j=0; j<n;j++){
        if(i - a[j] < 0) dp[0] = min(dp[0], dp[i] + b[j]);
        else dp[i - a[j]] = min(dp[i - a[j]], dp[i]+b[j]);
    }
    cout << dp[0] << endl;
    return 0;
}