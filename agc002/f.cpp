#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
typedef long long ll;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

#define MOD 1000000007

ll fact[4040404], frev[4040404];
ll invs[4040404];

ll comb(int n, int k)
{
	if (n < k) return 0;
	return fact[n] * frev[k] % MOD * frev[n - k] % MOD;
}

void fill_factorial_table(){
	fact[0] = 1; frev[0] = 1;
	invs[0] = 1;
	invs[1] = 1;
	for (int i = 2; i < 4040404; ++i) invs[i] = MOD - MOD / i * invs[MOD % i] % MOD;
	for (int i = 1; i < 4040404; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
		frev[i] = frev[i - 1] * invs[i] % MOD;
	}
}

ll dp[4040][2020];

int main(){
    ll n,k;
    cin >> n >> k;
    if(k==1){ cout << "1" << endl; return 0;}
    dp[1][1] = 1;
    dp[0][1] = 1;
    fill_factorial_table();
    FOR(j,2,n+1){
        dp[0][j] =  comb((j * (k - 1)) - 1, k - 2) * dp[0][j-1] % MOD;

    }
    FOR(i,1,n+1){
        FOR(j,i,n+1){
            dp[i][j] =  (dp[i-1][j] + ((comb(i + (j * (k - 1)) - 1, k - 2) * dp[i][j-1]) % MOD)) % MOD ;
        }
    }
    cout << (dp[n][n] * fact[n]) % MOD << endl;

    return 0;
}