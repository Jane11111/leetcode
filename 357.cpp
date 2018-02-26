#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

void isOk(bool used[],int  base,bool has_nonneg,int n);
int countNumbersWithUniqueDigits(int n);
int count;
int main() {
    int n=2;
    int res=countNumbersWithUniqueDigits(n);
    cout<<res<<endl;
}



void isOk(bool used[],int  base,bool has_nonneg,int n){
    if(base==n) {//已经找到了
        count ++;
        return;
    }

    for(int i=0;i<=9;i++){
        if(!used[i]){
            if(has_nonneg||(!has_nonneg&&i))
                used[i]=true;
            bool f=false;
            if(i||has_nonneg)
                f=true;
            isOk(used,base+1,f,n);
            used[i]=false;
        }
    }

}

int countNumbersWithUniqueDigits(int n) {
    count=0;
    if(n==0)
        return count;
    bool used[10];
    for(int i=0;i<10;i++)
        used[i]=false;

    isOk(used,0,false,n);
    return count;

}