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

        if(st > d){cout << "IMPOSSIBLE" << endl; continue;}
        if(check(d,s)){cout << "0" << endl; continue;}

        queue<pair<string, int> > q;
        q.push(make_pair(s,0));
        while(!q.empty()){
            string ts = q.front().first;
            int tim = q.front().second;
            q.pop();
            if(check(d,ts)){cout << tim << endl; break;}
            else{
                rep(j,ts.length()-1){
                    if(ts[j]=='C'&&ts[j+1]=='S'){
                        swap(ts[j],ts[j+1]);
                        q.push(make_pair(ts,tim+1));
                        swap(ts[j],ts[j+1]);
                    }
                }
            }
        }
    }
    return 0;
}