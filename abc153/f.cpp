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
    ll n,d,a; cin >> n >> d >> a;
    vector<pair<ll,ll>> v(n); 
    rep(i,n) cin >> v[i].first >> v[i].second;
    queue<pair<ll,ll>> st;
    sort(all(v));
    ll sub = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll x = v[i].first, h = v[i].second;
        while(!st.empty() && st.front().second < x) {sub -= st.front().first; st.pop();}
        
        if(sub < h){
            ll dif = h - sub;
            ll t;
            if(dif % a == 0) t = dif/a; 
            else t = (dif/a) + 1;
            st.push(mp(t * a, x+2*d));
            sub = sub + t*a;
            ans = ans + t;
        }
    }
    cout << ans << endl;
    return 0;
}