#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;
typedef long long ll;



int main(){
    int n,a,b;
    cin >> n >> a >> b;
    if(a>b){
        int t;
        t = a;
        a = b;
        b = t;
    }
    int r=1;
    while((a+1) /2 != (b+1) /2){
        b = (b+1) / 2;
        a = (a+1) / 2;
        r++;
    }
    if(pow(2,r) == n) cout << "Final!" << endl;
    else cout << r << endl;

    return 0;
}