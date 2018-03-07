#include <iostream>
#include <vector>
using namespace std;

int findLengthOfLCIS(vector<int>& nums);
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(7);

    int res=findLengthOfLCIS(nums);
    cout<<res<<endl;

}

int findLengthOfLCIS(vector<int>& nums) {
    int len=nums.size();
    if(len==0)
        return 0;
    int res=0;
    int count=1;
    for(int i=1;i<len;i++){
        if(nums[i]>nums[i-1])
            count++;
        else{
            res=max(res,count);
            count=1;
        }

    }
    res=max(res,count);
    return res;

}