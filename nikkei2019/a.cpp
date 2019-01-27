#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,a,b; cin >> n >> a >> b;
    cout << min(a,b) << " " << (n >= a+b ? 0 : a+b-n) << endl;
    return 0;
}