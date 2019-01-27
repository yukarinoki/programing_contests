#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if(n==2){ cout << abs(a[0]-a[1]) <<endl; return 0;}
    sort(all(a));
    ll c = 1;
    long long int ans = 0;
    ll l=a[0],r=a[0];
    ll le = 1, ri = n-1;
    while(le <= ri){
        /*
        if(l < r){ans += abs(l-a[ri]); l = a[ri--];}
        else{ans += abs(r-a[ri]); r = a[ri--];}
        if(le>ri) break;
        if(l < r){ans += abs(l-a[ri]); l = a[ri--];}
        else {ans += abs(r-a[ri]); r = a[ri--];}
        if(le>ri) break;

        if(l < r){ans += abs(r-a[le]); r = a[le++];}
        else{ans += abs(l-a[le]); l = a[le++];}
        if(le>ri) break;
        if(l < r){ans += abs(r-a[le]); r = a[le++];}
        else{ans += abs(l-a[le]); l = a[le++];}
        if(le>ri) break;
        */
        ll t = max(max(abs(r-a[le]),abs(l-a[le])), max(abs(r-a[ri]),abs(l-a[ri])));
        if( t == abs(r-a[le])){ans += abs(r-a[le]); r = a[le++]; if(le>ri) break;}
        else if(t ==  abs(l-a[le])){ans += abs(l-a[le]); l = a[le++]; if(le>ri) break;}
        else if(t ==  abs(r-a[ri])){ans += abs(r-a[ri]); r = a[ri--]; if(le>ri) break;}
        else if(t ==  abs(l-a[ri])){ans += abs(l-a[ri]); r = a[ri--]; if(le>ri) break;}
    }
    cout << ans << endl;
    return 0;
}