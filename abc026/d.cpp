#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a,b,c;
double f(double x){
    return a * x + b * (sin(c * x * M_PI));
}

int main(){
     cin >> a >> b >> c;
    double left = 0.0000000005, right = 102.0;
    while(right - left > 0.0000000001){
        double mid = (left + right) / 2.0;
        // mid で可能なら flag = true, else flag = false;
        if(f(mid) < 100.0) left = mid;
        else right = mid;
    }
    printf("%.16lf\n",left);
    return 0;
}