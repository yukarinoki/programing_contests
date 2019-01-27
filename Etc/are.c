#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <cfloat>
#include <map>
int main(int argc, const char * argv[]) {
        int n, t, tot = 0, s, count;
        bool flag = true;
        bool flag2 = true;
    int sect=0;
    int ind=0;
        t = 0;
        n = 0;
        s = 0;
        count =0;
        scanf("%d", &n);
        
        int a[n];
        for(int i=0;i<n;i++){
           scanf("%d", &a[i]);
            tot += a[i];
        }
        s = tot % n;
        if(s != 0){ printf("-1\n"); return 0;}
        while(flag){
            if(a[t] != s){
                sect =0 ;
                ind=0;
                sect = a[t];
                while(flag2){
                    t++;
                    ind++;
                    sect += a[t];
                    if(((sect % n) == 0)){
                    if((((sect / (ind+1)) == s))){
                        count += ind;
                        flag2 = false;
                        t++;
                    }
                    }
                    
                    flag2 = true;
                    
                    if(t >= n) flag = false;
                }
                printf("%d", count);
                return 0;
            }}}


