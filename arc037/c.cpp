#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<long long int> a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n*n == k){cout << a[n-1] * b[n-1] << endl; return 0;}
    int bmax = b[n-1];
    long long int left = -1, right = a[n-1] * b[n-1];

    



}