#include <iostream>
#include <vector>
using namespace std;

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs);
int Rec(vector<int>& price,vector<vector<int>>& special,int start,vector<int>& needs);
int main() {
    vector<int> price;
    price.push_back(2);
    price.push_back(5);
    vector<vector<int>> special;
    vector<int> s1;
    vector<int> s2;
    s1.push_back(3);
    s1.push_back(0);
    s1.push_back(5);
    s2.push_back(1);
    s2.push_back(2);
    s2.push_back(10);
    special.push_back(s1);
    special.push_back(s2);
    vector<int> need;
    need.push_back(3);
    need.push_back(2);
    int res=shoppingOffers(price,special,need);
    cout<<res<<endl;
    return 0;
}
int Rec(vector<int>& price,vector<vector<int>>& special,int start,vector<int>& needs){
    ////////////终止条件///////////////
    bool done=true;
    for(int i=0;i<needs.size();i++){
        if(needs[i]!=0){
            done=false;
            break;
        }
    }

    if(done)
        return 0;

    if(start==special.size()){//无special可用
        int res=0;
        for(int i=0;i<needs.size();i++){
            res+=needs[i]*price[i];
        }
        return res;
    }
    /////////////////////////////////

    int res=INT_MAX;
    int i=start;
    for(;i<special.size();i++){
        vector<int> cur=special[i];
        bool can_buy=true;
        for(int j=0;j<needs.size();j++){//判断是否可以买这个special

            if(cur[j]>needs[j]){
                can_buy=false;
                break;
            }
        }

        if(can_buy){

            vector<int> still_need;
            for(int j=0;j<needs.size();j++){
                still_need.push_back(needs[j]-cur[j]);
            }
            int money=cur[cur.size()-1]+Rec(price,special,i,still_need);
            res=min(res,money);
        }


    }
    int money=Rec(price,special,i,needs);
    res=min(res,money);
    return res;

}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int res=Rec(price,special,0,needs);
    return res;
}