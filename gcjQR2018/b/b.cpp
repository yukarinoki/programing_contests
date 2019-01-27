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
    scanf("%d", &n);
    rep(l,n){
        int m;
        scanf("%d", &m);
        vector<int> vo, ve,v;
        rep(i,m){
            int t;
            scanf("%d", &t);
            if(i%2==0) ve.push_back(t);
            else vo.push_back(t);    
        }
        sort(ve.begin(),ve.end());
        sort(vo.begin(),vo.end());
        int j=0,k=0;
        rep(i,m){
            if(i%2==0) v.push_back(ve[j++]);
            else v.push_back(vo[k++]);    
        }
        int tnum = -1;
        rep(i,m-1){
            if(v[i] > v[i+1]){tnum = i; break;}
        }
        if(tnum==-1) printf("Case #%d: OK\n", l+1);
        else printf("Case #%d: %d\n", l+1, tnum);
    }
    return 0;
}