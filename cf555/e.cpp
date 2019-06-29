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
int mp[200005];
int main(){
    int n; cin >> n;
    vector<int> a(n), b(n); 
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) a[i] = a[i] % n;
    rep(i,n) b[i] = b[i] % n;
    rep(i,n) mp[i] = 0;
    set<int> st;
    rep(i,n){
        mp[b[i]]++;
        st.insert(b[i]);
        st.insert(b[i]+n);
    }
    rep(i,n){
        auto it = st.lower_bound(n-a[i]);
        mp[*it % n]--;
        a[i] = (*it - (n - a[i]) + n) % n;
        if(mp[*it % n] == 0){
            st.erase(*it % n);
            st.erase(*it % n + n);
        }
    }
    rep(i,n) cout << a[i] << " ";
    cout << endl;
    return 0;
}