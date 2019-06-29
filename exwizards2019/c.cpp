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
    int n,q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<int>> pr(26);
    vector<string> qu(26);
    rep(i,q){
        string qs, qd; cin >> qs >> qd;
        qu[qs[0]-'A'].push_back(qd[0]);
    }
    rep(i,n) pr[s[i]-'A'].push_back(i);
    int ans = 0;
    rep(i,26){
        if(pr[i].size()==0) continue;
        if(qu[i].size()==0){ans += pr[i].size(); continue;}
        int l=0,r=n;
        int pos = 0;
        rep(j, qu[i].size()){
            if(qu[i][j] == 'L') pos++;
            else if(qu[i][j] == 'R') pos--;
            if(l < pos) l = pos;
            if(r > n+pos) r = n + pos;
        }
        cout << pr[i][0] << endl;
        rep(j,pr[i].size()) if(pr[i][j] >= l && pr[i][j] < r) ans++;
        cout << i << ":" << l << ":" << r << ":" << ans << endl; 
    }
    cout << ans << endl;
    return 0;
}