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
    int n,kk; cin >> n >> kk;
    vector<int> v(n); rep(i,n) cin >> v[i];
    int ans = 0;
    for(int i=0; i<=min(n,kk);i++){
        for(int j=0; j<=i;j++){
            vector<int> tv;
            for(int k=0;k<j;k++) tv.push_back(v[k]);
            for(int k=0;k<(i-j);k++) tv.push_back(v[n-k-1]);
            sort(all(tv));
            int t = 0;
            int kkk = kk - i;
            for(auto x: tv){
                if(x < 0 && kkk>0){ kkk--; continue;}
                else t += x;
            }
            ans = max(t,ans);
        }
    }
    cout << ans << endl;
    return 0;
}