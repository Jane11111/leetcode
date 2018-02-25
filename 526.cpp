#include <iostream>
using namespace std;

int countArrangement(int N);
int  isOk(int pos,bool used[],int N);
int main() {
    int N=4;
    int res=countArrangement(N);
    cout<<res<<endl;
}
int isOk(int pos,bool used[],int N){
    int count=0;
    if(pos==N+1)
        return 1;
    int i=1;
    int res;
    for(;i<=N;i++){
        res=0;
        if((!used[i])&&(pos%i==0||i%pos==0)){
            used[i]=true;
            res= isOk(pos+1,used,N);
            used[i]=false;
        }
        count+=res;

    }
    return count;
}
int countArrangement(int N) {
    int count=0;
    bool used[N+1];
    for(int i=0;i<=N;i++)
        used[i]=false;
    for(int i=1;i<=N;i++){
        used[i]=true;
        int res=isOk(2,used,N);
        count+=res;
        used[i]=false;
    }
    return count;

}