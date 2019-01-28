#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    vector<long long int> as(2*n+1);
    for(int i=0;i<n;i++) cin >> a[i]; 
    as[0] = a[0];
    for(int i=1;i<2*n; i++){
        as[i] = a[i % n] + as[i-1];
       // cout << as[i] << (i==2*n-1 ? "\n" : " ");
    }

    long long int sum = as[n-1];
    long long int left = 0, right = 200000000000000;
    while(right - left > 1){
        long long int mid = (right + left) / 2;
        bool flag = false;
        if(as[n-1] > mid){
            for(int i=0;i<n;i++){
                int fpos = lower_bound(as.begin(),as.end(), mid + (i==0 ? 0 : as[i-1])) - as.begin();
                long long int fp = as[fpos] - (i==0 ? 0 : as[i-1]);
                auto itr = lower_bound(as.begin(), as.end(), mid + fp + (i==0 ? 0 : as[i-1]));
                if(itr == as.end()) continue;
                int spos = lower_bound(as.begin(), as.end(), mid + fp + (i==0 ? 0 : as[i-1])) - as.begin();
                long long int sp = as[spos] - fp - (i==0 ? 0 : as[i-1]) ;
               // printf("mid : %lld, fp: %lld, sp: %lld\n", mid, fp, sp);
                if(fp + sp > sum || sum - (fp + sp) < mid) continue;
                else{flag = true; break;}
            }
        }
        if(!flag) right = mid;
        else left = mid;
    }
    cout << left << endl;
}