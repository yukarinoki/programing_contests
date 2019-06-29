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
    long long int n; cin >> n;
    vector<long long int> s(n); rep(i,n) cin >> s[i];
    sort(all(s));
    int q; cin >> q;
    vector<pair<long long int,long long int>> qv(q); 
    rep(i,q) cin >> qv[i].first >> qv[i].second;
    

    rep(i,q){
        long long int rm = -1;
        long long int ans = 0;
        rep(j,n){
            if(rm < qv[i].first + s[j]){
                rm = qv[i].second + s[j];
                ans = ans + qv[i].second - qv[i].first + 1;
            }else{
                ans = ans + qv[i].second + s[j] - rm;
                rm = qv[i].second + s[j];
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}