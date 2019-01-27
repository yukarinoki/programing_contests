#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <string.h>
#include <numeric>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
typedef long long ll;

int main(){
    int n = 0; cin >> n;
    if(n==1) {printf("Yes\n2\n1 1\n1 1\n"); return 0;}
    if(n<3){cout << "No" << endl; return 0;}
    int k = 3;
    while(k*(k-1) < 2 * n) k++;
    if(k*(k-1) != 2 * n){cout << "No" << endl; return 0;}
    vector<vector<int>> s(k);
    rep(i,k) s[i].push_back(k-1);
    s[0].push_back(1); s[0].push_back(2);
    s[1].push_back(1); s[1].push_back(3);
    s[2].push_back(2); s[2].push_back(3);
    int now = 3,num = 3;
    rep(i,k - 3){
        rep(j,i+3) s[j].push_back(j+num+1);
        rep(j,i+3) s[i+3].push_back(j+num+1);
        num += i+3;   
    }
    cout << "Yes" << endl;
    cout << k << endl;
    rep(i,k) { rep(j,k) cout << s[i][j] << " "; cout << endl;}
    return 0;
}