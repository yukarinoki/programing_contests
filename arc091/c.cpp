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

/*
233333332

466666664
466666664

466...664
69....996
699...996
46....664
*/

void swap(ll* a, ll* b){
    ll t = *a;
    *a = *b;
    *b = t;
}

int main(){
    ll n,m,ans=0;
    cin >> n >> m;
    if(n<m) swap(&m,&n);
    if(n==1&&m==1){ ans=1;
    }else if(m==1){ ans=n-2;
    }else{ ans = (m-2)*(n-2);}

    cout << ans  << endl;
    return 0;
}