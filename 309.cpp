#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices);
int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(0);
    prices.push_back(2);
    int res=maxProfit(prices);
    cout<<res<<endl;
}

int maxProfit(vector<int>& prices) {

    int len=prices.size();
    int s_sold=0;
    int s1=INT_MIN;
    int s_cool=0;

    for(int i=0;i<len;i++){
        int p=prices[i];
        int pre=s_cool;
        s_cool=max(s_cool,s_sold);
        s_sold=max(s_sold,s1+p);
        s1=max(pre-p,s1);

    }

    return max(s_sold,s_cool);
}
