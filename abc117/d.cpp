#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
vector<long long int> a;
long long int f(long long int x){
    int n= a.size();
    long long int sum = 0;
    rep(i,n) sum = sum + (x ^ a[i]);
    return sum;
}

int main(){
    long long int n,k; cin >> n >> k;
    rep(i,n){long long int temp; cin >> temp;  a.push_back(temp);}
    long long int twopow = 1, bw = 0;
    while(twopow - 1 < k){ twopow = twopow * 2; bw++;}
    //cout << bw << endl;
    long long int x = 0;
    for(int i = bw-1; i >= 0; i--){
        long long int tp = 1; tp = tp << i;
        int zc=0, oc=0;;
        rep(j,n){
            if((a[j] & tp) == 0) zc++;
            else oc++;
        }
        if(zc > oc && k >= (x | tp)) x = x | tp; 
    }
    //cout << x << endl;
    cout << f(x) << endl;
    return 0;
}