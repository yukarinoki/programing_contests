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

int main(){
    ll n; cin >> n;
    ll a[10][10];
    rep(i,10) rep(j,10) a[i][j] = 0;
    for(int i=1;i<n+1;i++){
        if(i%10 == 0) continue;
        ll t,b; b = i%10;
        t = i;
        while(10 <= t) t = t / 10;
        a[t][b]++;
    }
    ll ans = 0;
    FOR(i,1,10) FOR(j,1,10) ans = ans + a[i][j]*a[j][i];
    cout << ans << endl;
    return 0;
}