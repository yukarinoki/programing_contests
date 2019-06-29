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
long long int gcd(long long int x,long long int y){
    long long int r;
    if(x == 0 || y == 0)  return 0;

    while((r = x % y) != 0) 
    {
         x = y;
        y = r;
    }
    return y;
}
vector<long long int> prime_table;
void prime_fill(int n){
    for(long long int i=2; i<=n;i++){
        bool flag = true;
        for(auto x: prime_table) if(i % x == 0){flag = false; break;}
        if(flag) prime_table.push_back(i);
    }
}

int main(){
    long long int a,b; cin >> a >> b;
    prime_fill(40000);
    if(a==b){
        cout << 0 << endl;
        return 0;
    }else if(a == (a*b) / gcd(a,b) || b == (a*b) / gcd(a,b)){
        cout << 0 << endl;
        return 0;
    }
    long long int k = 0, ma = (a*b) / gcd(a,b);

    for(int i = 100000; i>=1;i--){
        if(a % i  == b % i){
            long long int kk = i - (a % i);
            long long int tt = gcd(a+kk,b+kk);
            if((a * b) / tt < ma || ((a*b) / tt == ma && k > kk)){
                k = kk;
                ma =  (a * b) / tt;
            }
        }
    }

    cout << k << endl;
    return 0;
}