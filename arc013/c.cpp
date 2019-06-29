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
#define MOD 1000000007
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
long long dp[2][55][3205];
int main(){
    int n,k; cin >> n >> k;
    vector<long long int> a(n);
    vector<long long int> d(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        while(a[i]!=0){
            d[i]++;
            a[i] = a[i] / 2;
        }
    }
    sort(d.begin(), d.end());
    if(k >= 3200){
        long long int ans = 1;
        for(int i=0;i<n;i++){
            if(d[i] == 0) continue;
            else ans = ans * (d[i] + 1)
        }
    }
    return 0;
}