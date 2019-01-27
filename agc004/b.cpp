#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

ll *buildRMQ(ll *a, ll n) {
  ll logn = 1;
  for (ll k = 1; k < n; k *= 2) ++logn;
  ll *r = new ll[n * logn];
  ll *b = r; copy(a, a+n, b);
  for (ll k = 1; k < n; k *= 2) {
    copy(b, b+n, b+n); b += n;
    rep(i, n-k) b[i] = min(b[i], b[i+k]);
  }
  return r;
}
ll minimum(ll x, ll y, ll *rmq, ll n) {
  ll z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k なる最大 k
  s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
  return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}

int main(){
    ll N,x;
    cin >> N >> x;
    ll aa[4010];
    ll *a = aa + 2000; 
    ll *b = a - N;
    rep(i,N) cin >> a[i];
    rep(i,N) *(a - i - 1) = a[N-1-i];
  //  rep(i, 2 * N) cout << "b[" << i <<"] = " << b[i] << endl;
    ll *rmq = buildRMQ(b, 2 * N);
    ll ans = (ll)1000000000 *2000+1;
    rep(k,N){
        ll cost=0;
        // k denote how many times one spell the magic.
        cost += x * k;
        rep(i,N){
            cost += minimum(i+N-k,i+N,rmq,2*N);
        }
        ans = ans > cost ? cost : ans; 
    }
    cout << ans << endl;
    return 0;
}