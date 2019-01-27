#include <cstdio>
#include <iostream>
#include <bitset>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i]; 
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j] < a[j+1]){
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = a[j];
            }
        }
    }
    int sa=0,sb=0;
    for(int i=0;i<n;i++){
        if(i%2 == 0) sa += a[i];
        else sb += a[i];   
    }
    
    cout << (sa - sb) << endl;
    return 0;
}