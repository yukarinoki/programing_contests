#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)


int main(){
    long long int t; cin >> t;
    rep(kk,t){
        int n; cin >> n;string s[n];
        int c[256]; rep(i,256) c[i] = 0;
        rep(i,n) cin >> s[i];
        rep(i,n){
            bool ch[256]; rep(j,256) ch[j] = false;
           for(auto x: s[i]) if(!ch[(int)x]){c[(int)x]++; ch[(int)x] = true;}
        }
        int ans =0;
        rep(i,256) if(c[i] == n) ans++;
        cout << ans << endl;
    }
    return 0;
}
