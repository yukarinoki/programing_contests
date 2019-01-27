#include <vector>
#include <iostream>
using namespace std;

long long digit_sum(long long x){
    long long t = 1;
    while(x > t) t *= 10;
    long long ret = 0;
    while(x > 0){
        ret += x / t;
        x -= (x / t) * t;
        t /= 10;
    }
    return ret;
}

int main(){
    double t = 1.0;
    double tb[350001];
    bool c[350001];
    for(int i=1;i<350001;i++){
        tb[i] = (double) i / (double) digit_sum(i);
    }
    for(int i=1;i<350001;i++){
        bool flag = true;
        for(int j=i+1;j<i+5000;j++) if(tb[j] < tb[i]){flag = false; break;}
        if(flag) c[i] = true;
        else c[i] = false;
    }
    for(int i=1;i<350001;i++) if(c[i]) cout << i << ": " << tb[i] << endl; 
    cout << (double) 399999 / (double) digit_sum(399999);
    return 0;
}