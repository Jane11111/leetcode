#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target);
int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    int target=3;
    int res=search(nums,target);
    cout<<res<<endl;

}
int search(vector<int>& nums, int target) {
    int len=nums.size();
    for(int i=0;i<len;i++)
        if(nums[i]==target)
            return i;
    return -1;

}