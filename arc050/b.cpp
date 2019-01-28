#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000000000000005;

int main(){
    long long int r,b; cin >> r >> b;
    long long int x, y; cin >> x >> y;

    long long int left = 0, right = INF;
    while(right - left > 1){
        long long int mid = (left + right) / 2;
        bool flag = false;
        // mid で可能なら flag = true, else flag = false;
        if(r < mid || b < mid) flag = true;
        else if((r - mid) / (x-1) + (b - mid) / (y-1)  < mid) flag = true;

        if(flag) right = mid;
        else left = mid;
    }
    cout << left << endl;
    return 0;
}