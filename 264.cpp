#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int nthUglyNumber(int n){

    vector<int> seq(n,1);

    int p1=0;
    int p2=0;
    int p3=0;

    for(int i=1;i<n;i++){

        seq[i]=min(2*seq[p1],min(3*seq[p2],5*seq[p3]));
        if(seq[i]==2*seq[p1])p1++;
        if(seq[i]==3*seq[p2])p2++;
        if(seq[i]==5*seq[p3])p3++;


    }
    return seq[n-1];

}