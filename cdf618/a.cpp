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
#include <cstdint>
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
#define MOD 1000000007;

typedef long long ll;

int main(){
    int q; cin >> q;
    rep(itr,q){
        int n; cin >> n;
        int sum = 0;
        vector<int> v(n); rep(i,n) cin >> v[i];
        rep(i,n) sum += v[i];
        int c = 0;
        rep(i,n) if(v[i]==0) c++;
        if(sum+c == 0) cout << c+1 << endl;
        else cout << c << endl;
    }
    return 0;
}