#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums);
int main() {
    vector<int> nums(5,-1);
    nums.push_back(0);
    int res=pivotIndex(nums);
    cout<<res<<endl;
}

int pivotIndex(vector<int>& nums) {
    int sum=0;
    int len=nums.size();
    for(int i=0;i<len;i++)
        sum+=nums[i];
    int cur=0;
    for(int i=0;i<len;i++){
        if(sum-nums[i]==cur*2)
            return i;
        cur+=nums[i];
    }
    return -1;
}