#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxProfit(vector<int>& prices, int fee);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int maxProfit(vector<int>& prices, int fee) {

    int len=prices.size();
    int s0=0;
    int s1=INT_MIN;
    for(int i=0;i<len;i++){
        s0=max(s0,s1+prices[i]);
        s1=max(s1,s0-prices[i]-fee);

    }
    return s0;


}