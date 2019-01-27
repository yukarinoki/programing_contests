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
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b));


typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<pair<int,int> > x(n);
    rep(i,n){int tem; cin >> tem; x[i] = mp(tem,i);}
    sort(all(x));
    vector<bool> ans(n);
    int med = n/2;
    int le = x[med-1].first, ri = x[med].first; 
    rep(i,n) ans[i] = false;
    rep(i,n/2) ans[x[i].second] = true;
    rep(i,n) cout << ( ans[i] ? ri : le) << endl;
    
 
    return 0;
}