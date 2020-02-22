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
    long long int n,k; cin >> n >> k;
    vector<long long int> divd, a(n); rep(i,n) cin >> a[i];
    vector<ll> ad(n);
    long long int sum = 0;
    rep(i,n) sum = sum + a[i];
    for(long long int i=1; i*i <= sum; i++){
        if(sum%i == 0){ divd.pb(i); divd.pb(sum/i);}
    }
    sort(all(divd), greater<ll>());
    long long int ans;
    for(auto d: divd){
        long long int ds = 0;
        for(int i=0;i<n;i++){
            ad[i] = (d - (a[i]%d))%d;
        }
       sort(all(ad));
        int r = n-1;
        int t = 0;
        for(int i=0; i<r;i++){
            //for(auto x: ad) cout << x << " ";
            //cout << endl;
            int dif = ad[i];
            t += dif;
            ad[i] = 0;
            while(dif!=0){
                if(d-ad[r] < dif){
                    dif -= d-ad[r];
                    ad[r]=0;
                    r--;
                }else{
                    ad[r] = (ad[r]+dif) % d;
                    dif = 0;
                    if(ad[r]==0) r--;
                }
            }

        }
      //  cout << d << ":" << t << endl;
        if(t <= k){ans = d; break;} 

    }
    cout << ans << endl;
}