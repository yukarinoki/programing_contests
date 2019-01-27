#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    long long r,l;
    int a[100000];
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    r=2; l=2;
    for(int i=1;i<=n;i++){
        if(l%a[n-i]!=0 && (((l/a[n-i]+1)*a[n-i]) > r)){
            cout << "-1" << endl;
            return 0;
          
        }else{
        l = l%a[n-i]==0 ? l : (l/a[n-i]+1)*a[n-i];
        r = r/a[n-i] * a[n-i] + a[n-i] -1;
       
        }
    }
    cout << l << " " << r << endl;
    return 0;
}