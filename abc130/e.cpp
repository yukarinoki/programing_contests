#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;

#define MOD 1000000007;

int main(){
  int n,m; cin >> n >> m;
  vector<long long int> dp(max(n,m)+1), ts(100005), tt(100005);
  vector<long long int> s(max(n,m)), t(max(n,m));
  for(int i=0;i<n;i++) cin >> s[i];
  for(int i=0;i<m;i++) cin >> t[i];
  
  dp[0] = 1;
  for(int i=1;i<=max(n,m);i++){
  	if(i-1<n) ts[s[i-1]] = (ts[s[i-1]] + dp[i-1]) % MOD;
    if(i-1<m) tt[t[i-1]] = (tt[t[i-1]] + dp[i-1]) % MOD;
  	dp[i] = ((i-1<n ? tt[s[i-1]] : 0) + (i-1<m ? ts[t[i-1]] : 0))+ (s[i-1]!=t[i-1] ? dp[i-1] : 0);
    if(s[i-1]!=t[i-1]) cout << dp[i] << endl;
    dp[i] = dp[i]%MOD;
    printf("ts[%lld]:%lld,ts[%lld]:%lld,dp[%d]:%lld\n", s[i-1], ts[s[i-1]], t[i-1],tt[t[i-1]],i,dp[i]);
  }
  cout << dp[max(n,m)] << endl;
  return 0;
}