#include <iostream>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    n++;
    long long int i=0,j=1;
    while(n % 2==0){n = n / 2; i++; j *= 2;}
    if(i==0) cout << j*n+i << endl;
    else if(n==1) cout << i << endl;
    else cout << j*(n-1) + i << endl;;
    return 0;
}