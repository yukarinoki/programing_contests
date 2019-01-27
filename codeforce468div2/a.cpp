#include <cstdio>
#include <iostream>
#include <bitset>

using namespace std;
typedef long long ll;

int sol(int n){
    return (n * n + n);
}

int main(){
    int a,b;
    cin >> a >> b;
    int dif = a > b ? a - b : b - a;
    if(dif % 2==0) cout << sol(dif/2) << endl;
    else cout << sol(dif/2) + (dif/2 + 1 ) << endl;
    return 0;
}