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
    long long int n,m; cin >> n >> m;
    string s; cin >> s;
    vector<long long int> v(m); rep(i,m) cin >> v[i];
    vector<long long int> a(n); rep(i,n) cin >> a[i];
    long long int ans = 0;
    if(s=="+") for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout << v[j] + a[i] << " ";
        cout << endl;
    }
    else for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout << v[j]*a[i] << " ";
        cout << endl;
    }
    return 0;
}