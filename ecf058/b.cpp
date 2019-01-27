#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.length();
    int lp=-1,rp=-1;
    for(int i=0;i<n;i++) if(s[i]=='['){lp = i; break;}
    for(int i=n-1;i>=0;i--) if(s[i]==']'){rp = i; break;}
   // cout << lp << " " << rp << endl;
    if(lp==-1|| rp==-1 || rp<=lp ){cout << -1 << endl; return 0;}

    int lc=-1,rc=-1;
    for(int i=lp+1;i<rp;i++) if(s[i]==':'){ lc = i; break;}
    
    for(int i=rp-1;i>lp;i--) if(s[i]==':'){rc = i; break;}
    
   // cout << lc << " " << rc << endl;
    if(lc==-1|| rc==-1 || rc<=lc ){cout << -1 << endl; return 0;}
    int c=0;
    for(int i=lc+1;i<rc;i++) if(s[i]== '|') c++;
    cout << n - (n - c - 4) << endl;
    return 0;
}