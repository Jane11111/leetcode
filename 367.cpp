#include <iostream>
using namespace std;
bool isPerfectSquare(int num);
int main() {
    int num=2147483647;
    bool res=isPerfectSquare(num);
    if(res)
        cout<<"is"<<endl;
    else
        cout<<"is not"<<endl;
}

bool isPerfectSquare(int num) {
    int s=1;
    int e=num;

    while(s<=e){
        double d_mid=((double)s+(double)e)/2;
        int mid=int(d_mid);
        double t=(double)num/mid;
        //double square=mid*mid;
        if(t==mid)
            return true;
        if(t>mid)
            s=mid+1;
        if(t<mid)
            e=mid-1;
    }
    return false;

}