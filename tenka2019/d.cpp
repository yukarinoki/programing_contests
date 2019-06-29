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
#define MOD 998244353

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

long long int t[301][90605];
long long int u[301][90605];
int main(){
    int n; cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int sum = 0; rep(i,n) sum += a[i];
    rep(j,301) rep(i,90600){ t[j][i] = 0; u[j][i] = 0;}
    t[0][0] = 1; u[0][0] = 1;

    for(int i=1; i<=n;i++){
        rep(j,sum){
            t[i][j+a[i-1]] = (t[i][j+a[i-1]] + t[i-1][j]) % MOD;
            t[i][j] = (t[i][j] + 2*t[i-1][j]) % MOD;
        }
    }
    
    if(sum % 2 == 0 && t[n][sum / 2] != 0){
        for(int i=1; i<=n; i++){
            rep(j,sum){
                u[i][j+a[i-1]] = (u[i][j+a[i-1]] + u[i-1][j]) % MOD;
                u[i][j] = (u[i][j] + u[i-1][j]) % MOD;
            }
        }
    }
    long long int ans = 1;
    for(int i=0;i<n;i++) ans = (ans * 3) % MOD;
    if(sum % 2 == 0 && t[n][sum / 2] != 0){
        for(int i= (sum+1) / 2; i <= sum; i++) ans = (ans - 3 *t[n][i] + MOD) % MOD;
        ans = (ans + 3 * u[n][sum / 2] + MOD) % MOD;
    }else{
        for(int i= (sum+1) / 2; i <= sum; i++) ans = (ans - 3 *t[n][i] + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}