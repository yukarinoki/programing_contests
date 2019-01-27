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
    int a,b,c;
    cin >> a >> b >> c;
    if(b<c) swap(b,c);
    if(a<b) swap(a,b);
    if(b<c) swap(b,c);
  
    if(a%2 & b%2 & c%2) cout << b*c << endl;
    else cout << 0 << endl;
    return 0;
}