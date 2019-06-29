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

ll dp[200005];
vector<ll>  x(200005); 
ll n, X;

ll func(int i, int j){
    if(i == j) return 2*X + x[i] + 2*2*x[i];
    int num  = j - i + 1;
    ll val = 0;
    val += num * X + X;
    val += x[j] + x[i] * (num + 1)*(num + 1);
    for(int itr = j; itr > i; itr--){
        ll k  = j - itr + 1;
        val += (x[itr] - x[itr-1]) * (k + 1) *(k + 1); 
    } 
    return val;
}
int main(){
    cin >> n >> X;
    rep(i,n) cin >> x[i];
    
    if(n > 2000) assert(0);
    for(int i=0;i<n;i++){
        ll minimum = func(0, i);
        for(int j=0;j<i;j++) minimum = min(minimum, dp[j] + func(j+1,i));
        dp[i] = minimum;
    }
    cout << dp[n-1] << endl;
    return 0;
}