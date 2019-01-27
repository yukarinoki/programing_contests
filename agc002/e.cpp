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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(ALL(a), greater<int>());
    int i=0;
    while((i+1<n) && ( i < a[i+1] && a[i] > i+1) && a[i+1] != i+1){
        i++;
    }
    int u=0,r=0;
    while(((i+r+1) < n) &&  i < a[i+r+1] ){
        r++;
    }
    while(i+u+1 < a[i]){
        u++;
    }
 //cout << "i : " << i << " a[i+r+1] : " << a[i+r+1] << endl;
  // cout << "r%2 : " << r%2 << endl;
  //cout << "u%2 : " << u%2 << endl;
    if(r%2==1 && u%2==1) cout << "First" << endl;
    else if(r%2==1 && u%2==0) cout << "First" << endl;
    else if(r%2==0 && u%2==1) cout << "First" << endl;
    else if(r%2==0 && u%2==0) cout << "Second" << endl;
    return 0;
}