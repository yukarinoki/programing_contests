#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000000000000;

int main(){
    int n; cin >> n;
    vector<long long int> h(n),s(n);
    for(int i=0;i<n;i++) cin >> h[i] >> s[i];
    long long int left = 0, right = INF;
    while(right - left > 1){
        long long int mid = (left + right) / 2;
        vector<long long int> time(n);
        bool flag = true;
        for(int i=0;i<n;i++){
            if(h[i] > mid){flag = false; break;}
            time[i] = (mid - h[i]) / s[i];
        }
        if(flag == true){
            sort(time.begin(), time.end());
            for(int i=0;i<n;i++){
                if(i > time[i]){flag = false; break;}
            }
        }
        if(flag) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}