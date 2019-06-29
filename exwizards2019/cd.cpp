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
    string qa,qd,s; cin >> s;
    rep(i,q){
        string ts,tts; cin >> ts >> tts;
        qa += ts[0];
        qd += tts[0];
    }

    {
    bool tf = false;
    int tpos = n-1;
    rep(i,q){
        if(qa[i]==s[0]){
        if(qd[i] == 'L') tpos-- ;
        else if(qd[i] == 'R') tpos++;
        }
        if(tpos < 0){tf = true; break;}
    }
    if(tf){cout << 0 << endl; return 0;}
    tf = false;
    tpos = 0;
    rep(i,q){
        if(qa[i]==s[0]){
        if(qd[i] == 'L') tpos-- ;
        else if(qd[i] == 'R') tpos++;
        }
        if(tpos > n-1){tf = true; break;}
    }
    if(tf){cout << 0 << endl; return 0;}
    }

    int l=-1,r=n-1;
    int ml,mr;
    while(r - l > 1){
        int mid = (l+r) / 2;
        int pos = mid;
        bool flag = false;
        rep(i,q){
            if(qa[i]==s[pos]){
            if(qd[i] == 'L') pos-- ;
            else if(qd[i] == 'R') pos++;
            }
            if(pos < 0){flag = true; break;}
        }
        if(flag) l = mid;
        else r = mid;
    }
    ml = l;
    l=0,r=n;
    while(r - l > 1){
        int mid = (l+r) / 2;
        int pos = mid;
        bool flag = false;
        rep(i,q){
            if(qa[i]==s[pos]){
            if(qd[i] == 'L') pos-- ;
            else if(qd[i] == 'R') pos++;
            }
            if(pos > n-1){flag = true; break;}
        }
        if(flag) r = mid;
        else l = mid;
    }
    mr = r;
    cout << mr - ml -1 << endl;
    return 0;
}