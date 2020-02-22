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
    int l; cin >> l;
    int p = 1; int n=0;
    bool f = false;
    while(l-p>p-1){
        p = 2 * p;
        n++;
    }
    if(p == l) f = true;
    cout << p << " " << n << " " << f << endl;

    if(f){
        cout << n+1 << " " << 2*n << endl;
        rep(i,n){
            cout << i+1 << " " << i+2 << " " << pow(2,i) << endl;
            cout << i+1 << " " << i+2 << " " << 0 << endl;
        }
    }else{
        cout << n+1 << " " << 2*n << endl;
        rep(i,n){
            cout << i+1 << " " << i+2 << " " << pow(2,i) << endl;
            cout << i+1 << " " << i+2 << " " << 0 << endl;
        }
        int pp = __builtin_popcount(l-1); 
        cout << "1" << " " << n+2 << " " << p << endl;
        p = p/2;
        for(int i=n+2; i<n+2+pp-2;i++){
            while(p&(l-1) ==0) p = p/2;
            cout << i << " " << i+1 << " " << 0 << endl;
            cout << i << " " << i+1 << " " << p << endl;
        }
        while(p&(l-1) ==0) p = p/2;
        cout << n+pp << " " << n+1 << " " << p << endl;
        cout << n+pp << " " << n+1 << " " << 0 << endl;
    }
    return 0;

}