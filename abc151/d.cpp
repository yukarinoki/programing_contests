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

#define INF 200000009

typedef long long ll;

int main(){
    int h,w; cin >> h >> w;
    int d[h][w];
    rep(i,h) rep(j,w) d[i][j] = INF;
    vector<string> vs(h);
    rep(i,h) cin >> vs[i];
    int sh,sw;
    rep(i,h) rep(j,w){
        if(vs[i][j] == '.'){
            sh = i; sw = j;
            break;
        } 
    }
    bool c[h][w]; rep(i,h) rep(j,w) c[i][j] = false;
    
    //行き
    queue<pair<int,int>> q;
    q.push(mp(sh,sw));
    c[sh][sw] = true;
    d[sh][sw] = 0;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while(!q.empty()){
        int th = q.front().first;
        int tw = q.front().second;
        q.pop();
        rep(i,4){
            if(
                th + dy[i] < h && th + dy[i] >= 0 &&
                tw + dx[i] < w && tw + dx[i] >= 0 &&
                vs[th + dy[i]][tw + dx[i]] == '.' &&
                !c[th + dy[i]][tw + dx[i]]
            ){
                d[th + dy[i]][tw + dx[i]] = d[th][tw] + 1;
                c[th + dy[i]][tw + dx[i]] = true;
                q.push(mp(th + dy[i], tw + dx[i]));
            }
        }
    }

    int ma = -1;
    rep(i,h) rep(j,w){
        if(ma < d[i][j] && d[i][j] != INF){
            sh = i; sw = j;
            ma = d[i][j];
        }
    }

    rep(i,h) rep(j,w) d[i][j] = INF;
    rep(i,h) rep(j,w) c[i][j] = false;
    q.push(mp(sh,sw));
    c[sh][sw] = true;
    d[sh][sw] = 0;

    while(!q.empty()){
        int th = q.front().first;
        int tw = q.front().second;
        q.pop();
        rep(i,4){
            if(
                th + dy[i] < h && th + dy[i] >= 0 &&
                tw + dx[i] < w && tw + dx[i] >= 0 &&
                vs[th + dy[i]][tw + dx[i]] == '.' &&
                !c[th + dy[i]][tw + dx[i]]
            ){
                d[th + dy[i]][tw + dx[i]] = d[th][tw] + 1;
                c[th + dy[i]][tw + dx[i]] = true;
                q.push(mp(th + dy[i], tw + dx[i]));
            }
        }
    }

    ma = -1;
    rep(i,h) rep(j,w){
        if(ma < d[i][j] && d[i][j] != INF){
            sh = i; sw = j;
            ma = d[i][j];
        }
    }

    rep(i,h) rep(j,w) d[i][j] = INF;
    rep(i,h) rep(j,w) c[i][j] = false;
    q.push(mp(sh,sw));
    c[sh][sw] = true;
    d[sh][sw] = 0;

    while(!q.empty()){
        int th = q.front().first;
        int tw = q.front().second;
        q.pop();
        rep(i,4){
            if(
                th + dy[i] < h && th + dy[i] >= 0 &&
                tw + dx[i] < w && tw + dx[i] >= 0 &&
                vs[th + dy[i]][tw + dx[i]] == '.' &&
                !c[th + dy[i]][tw + dx[i]]
            ){
                d[th + dy[i]][tw + dx[i]] = d[th][tw] + 1;
                c[th + dy[i]][tw + dx[i]] = true;
                q.push(mp(th + dy[i], tw + dx[i]));
            }
        }
    }

    ma = -1;
    rep(i,h) rep(j,w){
        if(ma < d[i][j] && d[i][j] != INF){
            sh = i; sw = j;
            ma = d[i][j];
        }
    }

    cout << ma << endl;
    return 0;
}