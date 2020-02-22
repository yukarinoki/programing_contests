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
    int n,k; cin >> n >> k;
    vector<int> p(n); rep(i,n) cin >> p[i];
    double ans = 0, t = 0;
    for(int i=0; i<k;i++) t = t + ((double)(p[i]+1) / 2.0);
    ans = t;
    for(int i=k; i<n; i++){
        t = t + ((double)(p[i]+1) / 2.0) - ((double)(p[i-k]+1) / 2.0);
        ans = max(t, ans);
    }
    printf("%.13lf\n", ans);
    return 0;
}