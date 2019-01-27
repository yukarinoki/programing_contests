#include <cstdio>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>


using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
 
int main() {
    int day=28, month=2, year=2015, next_day;
    int next_month, next_year, calculation;
    string s;
    cin >> s;
    stringstream ss;
    ss << s; 
    ss >> year;
    ss.ignore();
    ss >> month;
    ss.ignore();
    ss >> day;

    while(year % (day * month) != 0){
        next_day = day +1;
        next_month = month;
        next_year = year;
        calculation = 31;
    
        if (month == 2) {
            calculation = 28;
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    calculation = 29;
                } 
            }else if (year % 4 == 0) {
                    calculation = 29;
            }
        }else if(month == 4||month==6||month==9||month==11){
            calculation=30;
        }

        if (next_day > calculation) {
                next_day = 1;
                next_month++;
        }
        if (next_month > 12) {
                next_month = 1;
                next_year++;
        }
        day = next_day; month = next_month; year = next_year;
    }
    if(month<10||day<10){ 
    if(month<10&&day<10) printf("%d/0%d/0%d\n", year, month, day);
    else if(month<10)    printf("%d/0%d/%d\n", year, month, day);
    else                 printf("%d/%d/0%d\n", year, month, day);
    }
    else                 printf("%d/%d/%d\n", year, month, day);
    return 0;
}