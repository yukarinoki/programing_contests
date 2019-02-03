#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int n,m; cin >> n >> m;
    vector<int> v(m); rep(i,m) cin >> v[i];
    if(n >= m){cout << 0 << endl; return 0;}
    sort(v.begin(),v.end());
    vector<int> dif; rep(i,m-1) dif.push_back(v[i+1] -v[i]);
    sort(dif.begin(),dif.end(), greater<int>());
    long long int sum = 0;
    rep(i,n-1) sum = sum + dif[i];
    cout << v[m-1] - v[0] - sum << endl;
    return 0;
}