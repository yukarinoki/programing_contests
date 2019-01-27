#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int main(){
    string s;
    s.resize(1001);
    cin >> s;
    bool c1=false,c2=false,c3=false,c4=false;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='N') c1 = true;
        else if(s[i]=='W') c2 = true;
        else if(s[i]=='E') c3 = true;
        else if(s[i]=='S') c4 = true;
    }
    if((c1!=c4)||(c2!=c3)) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}