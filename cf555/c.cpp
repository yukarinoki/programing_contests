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
    vector<int> v(n); rep(i,n) cin >> v[i];
    int lp=0, rp = n-1;
    string s;
    int ln = -1;
    bool flag = false;

    while(lp != rp){
        if(v[lp] < v[rp] && ln < v[lp]){s += 'L'; ln = v[lp++];}
        else if(v[lp] > v[rp] && ln < v[rp]){s += 'R'; ln = v[rp--];}
        else if(v[lp] < v[rp] && ln < v[rp]){s += 'R'; ln = v[rp--];}
        else if(v[lp] > v[rp] && ln < v[lp]){s += 'L'; ln = v[lp++];}
        else if(lp != rp && v[lp]==v[rp] && v[lp] > ln){flag = true; break;}
        else break;
    }

    if(flag){
        int sl,sr;
        int tln = ln;
        int trp = rp, tlp = lp;
        for(; tlp<rp && v[tlp] > tln; tlp++){
            sl++;
            tln = v[tlp];
        }
        tln = ln;
        for(; trp>lp && v[trp] > tln; trp--){
            sr++;
            tln = v[trp];
        }
        if(sl <= sr) rep(i,sr) s += 'R';
        else rep(i,sl) s += 'L';
    }else if(v[lp]==v[rp] && v[lp] > ln) s+='R';
    
    cout << s.length() << endl;
    cout << s << endl;
    return 0;
}