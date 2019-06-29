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
    vector<int> vma(n),vmi(n);
    vector<int> v(n);
    rep(i,n){
        vmi[i] = 1000000000;
        vma[i] = -1;
    }
   // set<int> s;
    rep(i,n){
        int c; cin >> c;
        v[i] = c-1;
     //   s.insert(c);
        vmi[c-1] = min(vmi[c-1], i);
        vma[c-1] = max(vma[c-1], i);
    }
    sort(all(vmi));
    sort(all(vma));
    int ans=-1;
    for(int i=0;i<n;i++){
        int c = v[i];
        for(auto pos: vmi){
            if(pos == 1000000000) break;
            else if(c != v[pos]){ ans = max(ans, abs(pos - i)); break;}
        }
        for(auto pos: vma){
            if(pos == -1) break;
            else if(c != v[pos]){ ans = max(ans, abs(pos - i)); break;}
        }
    }
    cout << ans << endl;
    return 0;
}