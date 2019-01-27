#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

using namespace std;

int *buildRMQ(int *a, int n) {
  int logn = 1;
  for (int k = 1; k < n; k *= 2) ++logn;
  int *r = new int[n * logn];
  int *b = r; copy(a, a+n, b);
  for (int k = 1; k < n; k *= 2) {
    copy(b, b+n, b+n); b += n;
    rep(i, n-k) b[i] = min(b[i], b[i+k]);
  }
  return r;
}
int minimum(int x, int y, int *rmq, int n) {
  int z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k なる最大 k
  s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
  return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}


int main(){
    int n=105;
    cin >> n;
    ll sum=0;
    int a[n];
    rep(i,n) cin >> a[i];
    int *rmq = buildRMQ(a,n);
    rep(i,10){
        FOR(j,i,10){
            cout << minimum(i,j,rmq,n) << " : ";
        }
        cout << endl;
    }
    return 0;
}