#include <iostream>
using namespace std;
int uniquePaths(int m, int n) ;
int main() {
    int m=53;
    int n=4;
    int res=uniquePaths(m,n);
    cout<<res<<endl;
}

int uniquePaths(int m, int n) {

    int total_step=m+n-2;
    double res=1;
    int tmp=m<n?m:n;
    for (int i=0;i<tmp-1;i++)
        res*=(total_step-i);
    for(int i=1;i<=tmp-1;i++)
        res/=i;
    return res;

}