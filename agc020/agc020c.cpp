#include <cstdio>
#include <iostream>
#include <bitset>

using namespace std;
typedef long long ll;


int main(){
    int n;
    int a[2020];
    cin >> n;
    int sm=0;
    for(int i=0;i<n;i++){ cin >> a[i]; sm+=a[i];}
    sm = (sm + 1) / 2;
    
    bitset<4000001> dp;
    dp.set(0);
    for(int i=0;i<n;i++){
        bitset<4000001> pd;
        pd = dp;
        dp |= pd << a[i];
    }
    
    while(dp[sm]==0) sm++;
    printf("%d\n", sm);

   return 0;
}