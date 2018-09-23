#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maximumProduct(vector<int>& nums);

int main() {
    vector<int> nums={-4,-3,-2,-1,60};
    int res=maximumProduct(nums);
    cout<<res<<endl;
    return 0;
}

int maximumProduct(vector<int>& nums) {

    vector<int> neg;
    vector<int> pos;

    for(int num: nums){
        if(num<0)
            neg.push_back(num);
        else
            pos.push_back(num);
    }

    for(int i=1;i<neg.size();i++){
        int cur=neg[i];
        for(int j=i-1;j>=0;j--){
            if(neg[j]<cur)
                swap(neg[j],neg[j+1]);
        }
    }
    for(int i=1;i<pos.size();i++){
        int cur=pos[i];
        for(int j=i-1;j>=0;j--){
            if(pos[j]>cur)
                swap(pos[j],pos[j+1]);
        }
    }

    int res=INT_MIN;
    //正数情况
    if(pos.size()>=3)
        res=max(res,pos[pos.size()-1]*pos[pos.size()-2]*pos[pos.size()-3]);
    if(pos.size()>=1&&neg.size()>=2)
        res=max(res,pos[pos.size()-1]*neg[neg.size()-1]*neg[neg.size()-2]);

    //负数情况
    if(neg.size()>=3)
        res=max(res,neg[0]*neg[1]*neg[2]);
    if(neg.size()>=1&&pos.size()>=2)
        res=max(res,neg[0]*pos[0]*pos[1]);

    return res;


}