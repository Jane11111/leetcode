#include <iostream>
#include<cmath>
using namespace std;
int arrangeCoins(int n);
int main() {
    int n=1804289383;
    int res=arrangeCoins(n);
    cout<<res<<endl;
}

int arrangeCoins(int n){
    double t=2.0*n;
    double num=int(sqrt(t));
    if((num+1)*(num+2)<=t)
        return num+1;
    if(num*(num+1)<=t)
        return num;
    return num-1;
}