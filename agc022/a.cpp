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
void solve(string &s,string &aa){
    
}

int main(){
    string s,aa;
    cin >> s;
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << "-1" << endl;
        return 0;
    }
    if(s.length() <= 25){
        rep(i, 26){
            if((int)s.find((char)i +'a') == -1){
                s[s.length()] = (char)i + 'a';
                s[s.length()+1] = '\0';
                break;
            }
        }
    }
    if(s.length() == 26){
        rep(i,s.length()-1){
            if(s[25-i] > s[24-i]){
                while(s[24-i])
                s[24-i] = s[25];
                s[25-i] = '\0';
                rep(j,26-i){
                    aa[i] = s[i];
                }
                break;
            }
        }
    }
    printf("%s\n", aa);
    return 0;
}