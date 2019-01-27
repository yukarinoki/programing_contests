#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n),b(n);
    long long suma=0, sumb=0;
    for(int i=0;i<n;i++) {cin >> a[i]; suma+= a[i];}
    for(int i=0;i<n;i++) {cin >> b[i]; sumb+= b[i];}
    if(sumb > suma){cout << -1 << endl; return 0;}
    vector<long long> c(n);
    for(int i=0;i<n;i++) c[i] = a[i] - b[i];
    sort(c.begin(), c.end());
    long long ms=0,ps=0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(c[i] < 0){ ms -= c[i]; ans++;}
        else if(c[i] >= 0) break;
    }
    for(int i=n-1;i>=0;i--){
        if(ps >= ms) break;
        ps += c[i];
        ans++;
    }
    cout << ans << endl;
    return 0;
}