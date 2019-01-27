#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c,d; cin >> a >> b >> c >> d;
    if(a==b||a==c||a==d||b==c||b==d||c==d){
        cout << "NO" << endl;
        return 0;
    }
    bool flag = true;
    if(!(a==1||b==1||c==1||d==1)) flag = false;
    if(!(a==7||b==7||c==7||d==7)) flag = false;
    if(!(a==9||b==9||c==9||d==9)) flag = false;
    if(!(a==4||b==4||c==4||d==4)) flag = false;
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}