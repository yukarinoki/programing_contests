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
bool check(int d,string &s){
    int le = s.length();
    int dame = 0,cha=1;
    rep(i,le){
        if(s[i]=='S'){dame += cha;}
        else cha*=2;
    }
    if(dame>d) return false;
    else return true;
}

int main(){
    int n;
    cin >> n;
    rep(l,n){
        int d,st=0; string s;
        cin >> d >> s;
        rep(i,s.length()){
            if(s[i]=='S') st++;
        }

        if(st > d){printf("Case #%d: IMPOSSIBLE\n", l+1); continue;}
        if(check(d,s)){printf("Case #%d: 0\n", l+1); continue;}

        int ans=0;
        int le = s.length();
        while(!check(d,s)){
            rep(j,le-1){
                if(s[le-j-1]=='S'&&s[le-j-2]=='C'){
                    swap(s[le-j-1],s[le-j-2]);
                    ans++;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", l+1, ans);
    }
    return 0;
}