#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int main(){
    int n,ans;
    bool Smode=false;
    string s;
    cin >> s;
    n = s.length();
    ans = n;
    int sc = 0;
    if(s[0]=='S'){Smode = true; sc=1;}

    for(int i=1;i<n;i++){
        if(Smode){
            if(s[i]=='T'){
                Smode = !Smode;
                if(sc>0){
                    sc--;
                    ans-=2;
                }     
            }else{
                sc++;
            }
        }
        else{
            if(s[i]=='S'){
                Smode = !Smode;
                sc++;
            }
            else{
                if(sc>0){
                    sc--;
                    ans-=2;
                }     
            }

        }
    }
    cout << ans << endl;

    return 0;
}