#include <iostream>
using namespace std;
int minSteps(int n);
int main() {
    int n=3;
    int res=minSteps(n);
    cout<<res<<endl;
}

int minSteps(int n) {
    if(n==1)
        return 0;

    int res=2;
    int tmp=2;
    int pre=1;
    while(tmp<n){

        if(tmp!=1&&n%tmp==0){
            res+=2;
            pre=tmp;
            tmp+=pre;
        }else{
            res++;
            tmp+=pre;
        }
    }
    return res;

}