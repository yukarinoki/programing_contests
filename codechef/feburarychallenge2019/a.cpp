#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

long long int gcd(long long int x,long long int y)
{
    long long int r;
    if(x == 0 || y == 0)  
    {
        return 0;
    }

    while((r = x % y) != 0) 
    {
        x = y;
        y = r;
    }
    return y;
}
long long int lcm(long long int x, long long int y){
    return (x * y) / gcd(x,y);
}

int main(){
    long long int t; cin >> t;
    rep(kk,t){
        long long int n,a,b,k; cin >> n >> a >> b >> k;
        long long int solved = (n / a) -  (n / lcm(a,b)) + (n / b) - (n / lcm(a,b));
       // cout << lcm(a,b) << endl;
        if(solved >= k) cout <<"Win" << endl;
        else cout << "Lose" << endl; 
    }
    return 0;
}
