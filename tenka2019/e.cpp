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

vector<int> prime_table;
void prime_fill(int n){
    for(int i=2; i<=n;i++){
        bool flag = true;
        for(auto x: prime_table) if(i % x == 0){flag = false; break;}
        if(flag) prime_table.push_back(i);
    }
}
long long int gcd(long long int x,long long int y){
    int r;
    if(x == 0 || y == 0)  return 0;
   
    while((r = x % y) != 0) 
    {
         x = y;
        y = r;
    }
    return y;
}

int main(){
    int n; cin >> n;
    vector<int> a(n+1); 
    rep(i,n+1) cin >> a[n-i];
    prime_fill(10000);
    set<int> ans;
    
    for(auto p: prime_table){
        vector<int> b(p);
        b[0] = a[0] % p;
        for(int i=1;i<=n;i++){
            b[i % (p-1) + 1] =  (b[i % (p-1) + 1] + a[i]) % p;
        }
        bool flag = true;
        for(auto x: b) if(x % p != 0){flag = false; break;}
        if(flag)  ans.insert(p);
    }
    
    long long int gc = a[0];
    for(auto x: a) gc = gcd(gc, x);
    
    for(auto x: prime_table){
        	if(gc % x == 0&& gc != 1 && gc != 0){
                while(gc % x == 0 && gc != 1 && gc != 0) gc /= x;
                ans.insert(x);
            }
    }

   if(gc != 1) ans.insert(gc);
    for(auto x: ans) cout << x <<endl;
    return 0;
}
