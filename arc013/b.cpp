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
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        v[i].push_back(0); v[i].push_back(0); v[i].push_back(0);
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        sort(all(v[i]));
    }
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
        a = max(v[i][0],a);
        b = max(v[i][1],b);
        c = max(v[i][2],c);
    }
    cout << a * b * c << endl;
    return 0;
}