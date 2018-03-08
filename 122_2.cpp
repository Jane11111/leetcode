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
    int s0=0;int s1=INT_MIN;

    for(int i=0;i<len;i++){
        s0=max(s1+prices[i],s0);
        s1=max(s1,s0-prices[i]);
    }

    return s0;

}