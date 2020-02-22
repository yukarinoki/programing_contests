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

long long int gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return 0;
    if(a%b == 0) return b;
    else return gcd(b,a%b); 
}

int main(){
    long long int n,m,k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<long long int> v(m); rep(i,m) cin >> v[i];
    vector<long long int> a(n); rep(i,n) cin >> a[i];
    rep(i,m) v[i] %= k;
    rep(i,n) a[i] %= k;
    sort(all(a));
    sort(all(v));
    long long int ans = 0;
    if(s=="+") for(int i=0;i<m;i++){
        if(binary_search(all(a), (k-v[i])%k)){
            int id = lower_bound(all(a), (k-v[i])%k) - a.begin();
            int idd = upper_bound(all(a), (k-v[i])%k) - a.begin();
            ans = ans + idd - id;
        }
    }else{
        map<long long int,long long int> vm,am;
        rep(i,m){
            int gc = gcd(v[i], k);
            if(vm.count(gc)==0) vm[gc] = 1;
            else vm[gc]++;
        }
        rep(i,n){
            int gc = gcd(a[i], k);
            if(am.count(gc)==0) am[gc] = 1;
            else am[gc]++;
        }
        for(const auto& [key,val]: vm){
            for(auto [kk,vv]: am){              
                if((key*kk) % k == 0){
                  //  cout << vv << " " << val << endl;
                    ans = ans + (val*vv);
                }
            }
        }
    }      
    cout << ans << endl;

    return 0;
}