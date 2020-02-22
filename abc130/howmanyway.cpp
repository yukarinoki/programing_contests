#include<vector>
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

#define MOD 1000000007;

int main(){
    int n,m; cin >> n >> m;
    long long int ans = 0;
    long long int a[n][m];
    for(int i=0;i<n;i++)  for(int j=0;j<m;j++) cin >> a[i][j]; 
    for(int i=0;i<m;i++) for(int j=i+1;j<m;j++) {
        long long int t = 0;
        for(int k=0;k<n;k++){
            t = t + max(a[k][i], a[k][j]);
        }
        ans = max(t,ans);
    }
    cout << ans << endl;
}