#include <iostream>
#include <vector>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int maxProfit(vector<int>& prices) {
    int profit=0;
    int len=prices.size();
    if(len==0)
        return profit;
    int isUp[len];
    for(int i=1;i<len;i++){
        if(prices[i]>prices[i-1])
            isUp[i-1]=true;
        else
            isUp[i-1]=false;
    }
    isUp[len-1]=false;


    bool has=false;
    for(int i=0;i<len;i++){
        if(!has&&isUp[i]) {
            profit -= prices[i];//买股票
            has=true;
        }
        if(has&&!isUp[i]) {
            profit += prices[i];
            has=false;
        }
    }
    return profit;

}