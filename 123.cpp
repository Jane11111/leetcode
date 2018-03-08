#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int maxProfit(vector<int>& prices) {

    int len=prices.size();
    int k=2;
    vector<int> s0(k+1,0);
    vector<int> s1(k+1,INT_MIN);
    for(int i=0;i<len;i++){
        int p=prices[i];
        for(int j=1;j<=k;j++){
            s0[j]=max(s0[j],s1[j]+p);
            s1[j]=max(s0[j-1]-p,s1[j]);
        }
    }
    return s0[k];
}