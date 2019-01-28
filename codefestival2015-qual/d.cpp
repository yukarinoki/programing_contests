#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    long long int n, m;
    cin >> n >> m;
    vector<long long int> x(m); for(int i=0;i<m;i++) cin >> x[i];
    long long int left = -1, right = 2000000000;
    while(right - left > 1){
        long long int mid = (left + right) / 2;
        // mid で可能なら flag = true, else flag = false;
        bool flag = true;
        int pos = 0;
        for(int i=0;i<m;i++){
            if(x[i] - pos - 1 > mid){flag = false; break;}
            else{
                if(pos >= x[i] - 1) pos = x[i] + mid;
                else pos = max(x[i] + (mid - (x[i] - pos - 1)) / 2, x[i] + mid - 2 * (x[i] - pos -1));
            }
            if(pos >= n) break;
            //cout << pos << endl;
        }
        if(pos < n) flag = false;
        if(flag) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}