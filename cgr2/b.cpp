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
    int n,h; cin >> n >> h;
    vector<int> a(n); rep(i,n) cin >> a[i];
    multiset<int> s;
    rep(i,n){
        s.insert(a[i]);
        if(s.size() % 2 == 0){
            int ans = 0;
            auto itr = s.begin();
            rep(i,s.size()/2){
                int l = *itr;
                itr++;
                int r = *itr;
                itr++;
                ans += max(l,r);
            }
           // cout << ans << endl;
            if(ans > h){
                cout << i << endl;
                return 0;
            }
        }else if(s.size() % 2 == 1){
            int ans = 0;
            auto itr = s.begin();
            ans += *itr;
            itr++;
            rep(i,s.size()/2){
                int l = *itr;
                itr++;
                int r = *itr;
                itr++;
                ans += max(l,r);
            }
           // cout << ans << endl;
            if(ans > h){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << n << endl;
    return 0;
}