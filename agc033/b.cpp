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
    int h,w,n; cin >> h >> w >> n;;
    int sr,sc; cin >> sr >> sc;
    string s,t; cin >> s >> t;
    int pos = sr;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(s[i]=='L') pos--;
        if(pos < 0){ flag = true; break;}
        if(t[i]=='R' && pos != w) pos++;
    }
    //if(flag) cout << "hida" << endl;
    pos = sr;
    for(int i=0;i<n;i++){
        if(s[i]=='R') pos++;
        if(pos > w){ flag = true; break;}
        if(t[i]=='L' && pos!=1) pos--;
         
    }
    //if(flag) cout << "migi" << endl;
    pos = sc;
    for(int i=0;i<n;i++){
        if(s[i]=='U') pos++;
        if(pos > h){ flag = true; break;}
        if(t[i]=='D' && pos != 1) pos--;
      
    }
    //if(flag) cout << "ue" << endl;
    pos = sc;
    for(int i=0;i<n;i++){
        if(s[i]=='D') pos--;
        if(pos < 0){ flag = true; break;}
        if(t[i]=='U' && pos != h) pos++;
       
    }
    //if(flag) cout << "sita" << endl;
    if(flag) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}