#include <iostream>
using namespace std;
double myPow(double x, int n);
int main() {
    double x=2;
    int n=-2147483648;
    double res=myPow(x,n);
    cout<<res<<endl;
}

double myPow(double x, int n) {

    if(n==0)
        return 1;
    double count=n;
    if(n<0){
        x=1/x;
        count=-(double(n));
    }

    double final_res=1;
    while(count>=1){
        double res=x;
        int i=1;
        for(;i<count/2;){
            res*=res;
            i+=i;
        }
        final_res*=res;
        count-=i;
    }

    return final_res;
}