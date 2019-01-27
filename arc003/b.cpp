#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int main(){
    int n;
    cin >> n;
    string s[n],ss[n];
    rep(i,n) {cin >> s[i]; ss[i] = s[i];}
    vector<pair <string, int> > v;
    rep(i,n){
        reverse(ss[i].begin(), ss[i].end());
        v.push_back(make_pair(ss[i], i));
    }
    sort(v.begin(), v.end());
    rep(i,n){
        cout << s[v[i].second] << endl;
    }

    return 0;
}