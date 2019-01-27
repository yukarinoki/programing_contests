#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b));

using namespace std;
typedef long long i64;

int main(){
    int q;
    cin >> q;
    rep(i,q){
        i64 a,b;
        cin >> a >> b;
        if(a < b){
            i64 tem = b;
            b = a;
            a = tem;
        }
        i64 t = a * b;
        i64 n = floor(sqrt(t));
       // cout <<"a : "<< a << endl;
        //cout << "are : " << (n - 1)* 2 + 1 << endl;
        if(a==b) cout << (n-1) * 2 << endl;
        else if(n*n==t) cout << (n-1) * 2 - 1 << endl;
        else if(a < (n - 1) * 2 + 1) cout << (n - 1)* 2 << endl;
        else cout << (n - 1)* 2 + 1 << endl;
    }
    return 0;
}