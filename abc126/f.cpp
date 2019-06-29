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
    int n,k; cin >> n >> k;
    int t = 1;
    rep(i,n) t = t * 2;
    if(k >= t){cout << -1 << endl; return 0;}
    else if(n==1&&k==1){cout << -1 << endl; return 0;}
    vector<int> v(t);
    int xo = 0;
    if(k==0){
        for(int i=0;i<t;i++) cout << i << " " << i << " ";
    }
    else {
        cout << 0 << " ";
        cout << k << " ";
        cout << 0 << " ";
        for(int i=1;i<t;i++){
            if(i!=k){
                cout << i << " ";
                xo ^= i;
            }
            
        }
        cout << k << " ";
        for(int i=t-1;i>=1;i--){
            if(i!=k) cout << i << " ";
        }
    }
    cout << endl;
    //cout << xo << endl;
    return 0;   
}