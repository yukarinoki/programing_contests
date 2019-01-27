#include <cstdio>
#include <iostream>
#include <bitset>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

int main(){
    int n;
    cin >> n;
    vector<int> a(n); REP(i,n) cin >> a[i];
    vector<int> b(n); REP(i,n) cin >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    REP(i,n){
      cout << a[i] << " ";
      if(a[i]>b[i]){cout << "No" << endl; return 0;}   
    }
    cout << "Yes\n";
    return 0;
}