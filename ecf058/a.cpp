#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int l ,r, d; cin >> l >> r >> d;
        int ans;
        if(d < l) ans = d;
        else ans = (((r + 1) / d) + ((r+1) % d == 0 ? 0 : 1)) * d;

        cout << ans << endl;
    }
    return 0;
}