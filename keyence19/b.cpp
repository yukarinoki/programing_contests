#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s, k = "keyence"; cin >> s;
    int pos = 0;
    int state=0;
    
    for(int i=0;i<8;i++){
        if(s.substr(0,i)+s.substr(s.length()-(7-i),7-i)==k.substr(0,7)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}