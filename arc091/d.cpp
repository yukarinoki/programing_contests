#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int main(){
    int n,k;
    ll ans=0;
    cin >> n >> k;
    for(int b=k+1;b<=n;b++){
        int upp = n-k,low = n-b+1;
        int lq = low / b,lr = low % b;
        int uq = upp / b,ur = upp % b;
        if(lq==uq) ans += (ur - lr + 1)*lq;
        else ans += ((b - lr) * lq) + (((uq-lq-1)*((uq-1)+(lq+1))) / 2) * b +  (ur + 1) * uq;
        ans += (k!=0 ? 1 : 0);

    }
    cout << ans << endl;
    return 0;
}