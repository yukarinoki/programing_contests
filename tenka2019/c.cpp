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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> bsum(n);
    bsum[0] = (s[0]=='#' ? 1 : 0);
    for(int i=1;i<n;i++) bsum[i] = bsum[i-1] + (s[i] == '#' ? 1 : 0);
    int ans = min(bsum[n-1], n-bsum[n-1]);
    for(int i=0;i<n;i++){
        int m = i+1;
        ans = min(bsum[i] + (n - m) - (bsum[n-1] - bsum[i]), ans);
    }
    cout << ans << endl;
    return 0;
}