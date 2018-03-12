#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums);
int main() {
    vector<int>nums;
    int res=firstMissingPositive(nums);
    cout<<res<<endl;
}

int firstMissingPositive(vector<int>& nums) {

    for(int i=0;i<nums.size();){
        if(nums[i]<=0)
            nums.erase(nums.begin()+i);
        else
            i++;
    }
    int len=nums.size();
    nums.push_back(nums.size()+1);
    for(int i=0;i<len;i++){
        if(nums[nums[i]-1]>0)
            nums[nums[i]-1]*=(-1);
    }
    for(int i=0;i<nums.size();i++)
        if(nums[i]>0)
            return i+1;
}