#include <iostream>
using namespace std;
int checkRecord(int n);
int main() {
    int n=100;
    int res=checkRecord(n);
    cout<<res<<endl;
}
int checkRecord(int n) {
    double W[3][2][4];

    int t=1000000000+7;
    W[0][0][0]=0;
    W[0][0][1]=1;
    W[0][0][2]=0;
    W[0][0][3]=0;

    W[1][0][0]=0;
    W[1][0][1]=0;
    W[1][0][2]=0;
    W[1][0][3]=1;

    W[2][0][0]=0;
    W[2][0][1]=0;
    W[2][0][2]=0;
    W[2][0][3]=1;

    for(int i=1;i<n;i++){
        W[0][i%2][0]=W[1][(i-1)%2][2]+W[1][(i-1)%2][3];
        while(W[0][i%2][0]>t)
            W[0][i%2][0]-=t;
        W[0][i%2][1]=W[2][(i-1)%2][2]+W[2][(i-1)%2][3];
        while(W[0][i%2][1]>t)
            W[0][i%2][1]-=t;
        W[0][i%2][2]=0;
        while(W[0][i%2][1]>t)
            W[0][i%2][1]-=t;
        W[0][i%2][3]=0;
        while(W[0][i%2][1]>t)
            W[0][i%2][1]-=t;

        W[1][i%2][0]=W[1][(i-1)%2][1];
        while(W[1][i%2][0]>t)
            W[1][i%2][0]-=t;
        W[1][i%2][1]=W[0][(i-1)%2][0]+W[0][(i-1)%2][1]+W[2][(i-1)%2][0]+W[2][(i-1)%2][1];
        while(W[1][i%2][1]>t)
            W[1][i%2][1]-=t;
        W[1][i%2][2]=W[1][(i-1)%2][3];
        while(W[1][i%2][2]>t)
            W[1][i%2][2]-=t;
        W[1][i%2][3]=W[2][(i-1)%2][2]+W[2][(i-1)%2][3];
        while(W[1][i%2][3]>t)
            W[1][i%2][3]-=t;

        W[2][i%2][0]=W[1][(i-1)%2][0]+W[1][(i-1)%2][1];
        while(W[2][i%2][0]>t)
            W[2][i%2][0]-=t;
        W[2][i%2][1]=W[0][(i-1)%2][0]+W[0][(i-1)%2][1]+W[2][(i-1)%2][0]+W[2][(i-1)%2][1];
        while(W[2][i%2][1]>t)
            W[2][i%2][1]-=t;
        W[2][i%2][2]=W[1][(i-1)%2][2]+W[1][(i-1)%2][3];
        while(W[2][i%2][2]>t)
            W[2][i%2][2]-=t;
        W[2][i%2][3]=W[2][(i-1)%2][2]+W[2][(i-1)%2][3];
        while(W[2][i%2][3]>t)
            W[2][i%2][3]-=t;
    }

    double res=0;
    res=res+W[0][(n-1)%2][0]+W[0][(n-1)%2][1]+W[0][(n-1)%2][2]+W[0][(n-1)%2][3];
    res=res+W[1][(n-1)%2][0]+W[1][(n-1)%2][1]+W[1][(n-1)%2][2]+W[1][(n-1)%2][3];
    res=res+W[2][(n-1)%2][0]+W[2][(n-1)%2][1]+W[2][(n-1)%2][2]+W[2][(n-1)%2][3];

    while(res>t)
        res-=t;
    return int(res);

}