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
    int h,w; cin >> h >> w;
    vector<vector<int>> tate(w),yoko(h); 
    vector<string> m(h); rep(i,h) cin >> m[i];
    rep(i,h) yoko[i].push_back(-1);
    rep(i,w) tate[i].push_back(-1);
    rep(i,h)rep(j,w){
        if(m[i][j] == '#'){
            tate[j].push_back(i);
            yoko[i].push_back(j);
        }
    }
    rep(i,h) yoko[i].push_back(w);
    rep(i,w) tate[i].push_back(h);
    int ans = 0;
    rep(i,h) rep(j,w){
        if(m[i][j] != '#'){
            int tid = lower_bound(all(tate[j]), i) - tate[j].begin();
            int yid = lower_bound(all(yoko[i]), j) - yoko[i].begin();
            ans = max(ans, (tate[j][tid] - tate[j][tid-1] - 1) + (yoko[i][yid] - yoko[i][yid-1] - 1) - 1);
        }
    }
    cout << ans << endl;
    return 0;
}