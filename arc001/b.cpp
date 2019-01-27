#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int main(){
    int a,b;
    cin >> a >> b;
    if(a>b) swap(a,b);
    int ans =0,ta;
    int d = b-a;

    ans += (d/10) + 1; d = ((d/10)+1)*10-d;
    if(d - (d/5)*5 > ((d/5)+1)*5-d){ans += (d/5) + 1; d = ((d/5)+1)*5-d;}
    else{ ans += d/5; d = d%5; }
    ans += d;

    ta = ans;
    ans = 0;
    d = b-a;

    ans += d /10; 
    d = d%10;
    if(d - (d/5)*5 > ((d/5)+1)*5-d){ans += (d/5) + 1; d = ((d/5)+1)*5-d;}
    else{ ans += d/5; d = d%5; }
    ans += d;

    ta = ta>ans? ans : ta;
    cout << ta << endl;  
    return 0;
}