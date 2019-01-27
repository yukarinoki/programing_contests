#include <cstdio>
#include <iostream>
#include <bitset>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

int main(){
    ll n;
    cin >> n;
    n++;
    ll keta=1,t=10;
    while(n > t){
        keta++;
        t *= 10;
    }
    t /= 10; 
    ll ans = (n / t) * t - 1;
    ll sol=0;
    while(t != 0){
        sol += ans / t;
        ans -= t * (ans / t);
        t /= 10;
    }
    cout << sol << endl;
    return 0;
}