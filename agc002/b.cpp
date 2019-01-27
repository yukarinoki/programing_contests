#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
typedef long long ll;
 
#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

 int main(){
    int n,m;
    cin >> n >> m;
    vector<int> num(n,1);
    vector<bool> c(n, false);
    int ans = 1;
    c[0] = true;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        num[x-1]--;
        num[y-1]++;
        if(c[x-1]&&!c[y-1]){
            c[y-1] = true; 
            ans++;
        }
        if(c[x-1]&&num[x-1]==0){
            c[x-1] = false; 
            ans--;
        }
    }
    cout << ans << endl;

     return 0;
 }