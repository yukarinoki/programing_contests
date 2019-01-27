#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

static int a[100000];
static int n;
bool checkmax(ll x){
    for(int i=0;i<n;i++){
        x = x - (x % a[i]);
    }
    return x<=2 ? true : false; 
}
bool checkmin(ll x){
    for(int i=0;i<n;i++){
        x = x - (x % a[i]);
    }
    return x>=2 ? true : false; 
}
int binary_search_min(bool func(ll),ll max,int min){
    
    int mid;
    while(max!=min){
        mid = (max+min)/2;
        if(func(mid)){
            max = mid;
        }else{
            min = mid+1; 
        }
    }
    return min;
}
int binary_search_max(bool func(ll),long long max,int min){
    
    ll mid;
    while(max!=min){
        mid = (max+min)/2+1;
        if(func(mid)){
            min = mid;
        }else{
            max = mid-1; 
        }
      //  cout << min <<endl;
    }
    return min;
}

int main(){
    cin >> n;
    int ma=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(ma < a[i]) ma = a[i];
    }

    int max = binary_search_max(checkmax,(ll)ma*n+2,2);
    int min = binary_search_min(checkmin,(ll)ma*n+2,2);

    if(max < min) cout << "-1" << endl;
    else{
        cout << min << " " << max << endl;
    }
    return 0;
}
