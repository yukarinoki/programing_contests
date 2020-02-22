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
    set<int> st;
    int n; cin >> n;
    vector<int> a(n); rep(i,n) cin >> a[i];
    rep(i,n){
        auto itr = lower_bound(st.begin(), st.end(), a[i]);
        cout << *itr << endl;
        if(itr == st.end() || *itr >= a[i]){
            st.insert(a[i]);
        }else{
            itr--;
            st.erase(*itr);
            st.insert(a[i]);
        }
    }
    cout << st.size() << endl;
    return 0;
}