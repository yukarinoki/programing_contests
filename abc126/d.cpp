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
    vector<vector<pair<int,int>>> v(n);
    vector<bool> b(n);
    vector<int>  cl(n);
    
    rep(i,n-1){
        int uu,vv,w; cin >> uu >> vv >> w;
        v[uu-1].push_back(mp(vv-1,w));
        v[vv-1].push_back(mp(uu-1,w));   
    }
    
    rep(i,n) b[i] = false;
    b[0] = true;
    int pos = 0, count = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int ver = q.front();
        int tc = cl[ver];
        q.pop();
        for(auto x: v[ver]){
            int tov = x.first;
            int dist = x.second;
            if(b[tov] == false){
                b[tov] = true;
                cl[tov] = tc^(dist%2);
                q.push(tov);
                count++;
            }
        }
    } 

    rep(i,n) cout << cl[i] << endl;
    return 0;
}