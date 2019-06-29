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

#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long ll;

ll fact[4040404], frev[4040404];
ll invs[4040404];

ll C(int a, int b) // <= this indicates combination aCb
{
	if (a < b) return 0;
	return fact[a] * frev[b] % MOD * frev[a - b] % MOD;
}
ll P(int a, int b){
    if(a<b) return 0;
    return fact[a] * frev[a - b] % MOD;
}

void fill_combination_table(){
	fact[0] = 1; frev[0] = 1;
	invs[0] = 1;
	invs[1] = 1;
	for (int i = 2; i < 4040404; ++i) invs[i] = MOD - MOD / i * invs[MOD % i] % MOD;
	for (int i = 1; i < 4040404; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
		frev[i] = frev[i - 1] * invs[i] % MOD;
	}
}


long long dp[2][3][100005];
int main(){
    rep(k,2) rep(j,3) rep(i, 100005) dp[k][j][i] = 0;
    fill_combination_table();
    int n,m; cin >> n >> m;
    if(n > 1000 || m > 1000) assert(0);
    dp[1][1][1] = 1;
    for(int i=2; i <= n+m-1;i++){
        for(int j=1; j <= min(i, n); j++){
            dp[i%2][0][j] = (((dp[(i-1)%2][0][j] + dp[(i-1)%2][1][j]) % MOD) + dp[(i-1)%2][2][j] )% MOD;
            dp[i%2][1][j] = dp[(i-1)%2][0][j-1] % MOD;
            dp[i%2][2][j] = dp[(i-1)%2][1][j-1] % MOD;
        }
        cout << i << ": *****" << endl;
        rep(j,7){
            cout << n-j << ":";
            rep(k,3) cout << dp[i%2][k][n-j]<< " ";
            cout << endl;
        }
        cout << "*******" << endl;
    }
    cout <<"C : " << C(n+m-2,n-1) << endl; 
    cout << (C(n+m-2, n-1) + MOD - (dp[(n+m-1)%2][0][n] + dp[(n+m-1)%2][1][n] + dp[(n+m-1)%2][2][n])) % MOD << endl;
    return 0;
}
