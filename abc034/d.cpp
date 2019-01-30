#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    double w[n],p[n];

    for(int i=0;i<n;i++) cin >> w[i] >> p[i];

    double left = 0, right = 100.0;
    vector<double> c(n);
    while(right - left > 0.000000001){
        double mid = (right + left) / 2.0;
        for(int i=0;i<n;i++) c[i] = (w[i] * p[i] ) - mid * w[i];
        sort(c.begin(),c.end(), greater<double>());
        double sum = 0.0;
        for(int i=0; i<k;i++) sum += c[i];
        if(sum >= 0) left = mid;
        else right = mid; 
    }
    printf("%.16lf\n", left);
    return 0;
}