#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int n; cin >> n;
    int a[12]; rep(i,n) cin >> a[i];
    int max = 0,idx = 0;;
    rep(i,n) if(max < a[i]) {max = a[i]; idx = i;}
    int sum = 0;
    rep(i,n) if(i != idx) sum += a[i];
    if(max < sum) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}