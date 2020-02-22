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
    int n,m; cin >> n >> m;
    vector<pair<int,int>> v(m),st(m);
    for(int i=0;i<m;i++) {cin >> st[i].first >> st[i].second; v[i].first = st[i].first; v[i].second = i;}
    sort(all(v));
    int c = 0;
    int pos=0;
    vector<bool> f(m); rep(i,m) f[i]=false;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        bool onetime = true;
        int las = -1;
        while(pos<m&&v[pos].first==i){
            if(!onetime){
                f[las] = true;
                f[v[pos].second] = true;
                q.push(mp(st[v[pos].second].second, v[pos].second));
                c++;
                pos++;
            }else{
                if(c>0) f[v[pos].second] = true;
                las = v[pos].second;
                q.push(mp(st[v[pos].second].second, v[pos].second));
                c++;
                pos++;
            }
            if(onetime) onetime = false;
        }
        if(c==1) f[q.top().second] = false;
        if(!q.empty()&&q.top().first==i&&c>1){
            while(!q.empty()&&q.top().first==i){
                 int e = q.top().first, id = q.top().second;
                 if(f[id]) ans.pb(id);
                 q.pop();
                 c--;
            }
        }
        if(!q.empty() && q.top().first==i){q.pop(); c--;}
    }
    cout << ans.size() << endl;
    for(auto x: ans) cout << x+1 << endl;
    return 0;
}