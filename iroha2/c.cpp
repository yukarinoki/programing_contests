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
    multiset<pair<int,int>> s;
    rep(i,n){int t; cin >> t; s.insert(mp(t, i));}
    int idx = 1;
    auto itr = s.begin();
    int pi = (*itr).first;
    vector<int> v(n);
    while(itr != s.end()){
        int t = (*itr).first;
        int id = (*itr).second;
        if(pi == t) v[id] = idx;
        else v[id] = ++idx;
        itr++;
        pi = t;
    }
    for(auto x: v) cout << x << endl;
    return 0;
}