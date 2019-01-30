#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;


int main(){
    int n,a; cin >> n >> a;
    vector<int> v(n); for(int i=0;i<n;i++){cin >> v[i]; v[i] -= a;}
    vector<long long int> plus(3000), minus(3000),sub(3000);
    sort(v.begin(),v.end());
    long long int num_zero = upper_bound(v.begin(),v.end(), 0) - lower_bound(v.begin(),v.end(), 0);
    vector<long long int> pv,mv;
    for(int i=0;i<n;i++){
        if(v[i] < 0) mv.push_back(-v[i]);
        else if(v[i] > 0) pv.push_back(v[i]);
    }
    plus[0] = 1; minus[0] = 1;
    for(int i=0;i<mv.size(); i++){
        for(int j=0;j<2600;j++) sub[j] = minus[j];
        for(int j=0;j<2600;j++) minus[j+mv[i]] += sub[j];
    }
    for(int i=0;i<pv.size(); i++){
        for(int j=0;j<2600;j++) sub[j] = plus[j];
        for(int j=0;j<2600;j++) plus[j+pv[i]] += sub[j];
    }
    long long int ans = 0;
    for(int i=0;i<2501;i++) ans = ans + (plus[i] * minus[i]);
    //cout << ans << "," << num_zero << endl;
    long long o = 1;
    ans = (ans - 1) * (o<<num_zero) + (o<<num_zero) - 1;
    cout << ans << endl;
}