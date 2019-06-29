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
int mat[505][505], omat[505][505];
int main(){
    int n, m; cin >> n >> m;
    rep(i,n) rep(j,m) cin >> mat[i][j];
    rep(i,n) rep(j,m) cin >> omat[i][j];
    rep(i,n){
        int par = 0;
        rep(j,m) par += mat[i][j] != omat[i][j] ? 1 : 0;
        if(par % 2 == 1){
            cout << "NO" <<endl;
            return 0;
        }
    }

    rep(j,m){
        rep(i,n-1) mat[n-1][j] += mat[i][j] != omat[i][j] ? 1 : 0;
        
        mat[n-1][j] %= 2;
        if(mat[n-1][j] != omat[n-1][j]){
            cout << "NO" <<endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}