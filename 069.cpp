#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x);
int main() {
    int x=10;
    int res=mySqrt(x);
    cout<<res<<endl;
}

int mySqrt(int x) {
    if(x==0)
        return 0;
    double s=1;
    double e=x;

    while(s<=e){
        int mid=(s+e)/2;
        int x1=x/mid;
        int x2=x/(mid+1);
        if(x1>=mid&&x2<(mid+1))
            return mid;
        if(x1>mid)
            s=mid+1;
        else
            e=mid-1;
    }


}