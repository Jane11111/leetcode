#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target);
int BinarySearch(vector<int>& nums,int s,int e,int target);
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    int target=5;
    int res=searchInsert(nums,target);
    cout<<res<<endl;
}

int searchInsert(vector<int>& nums, int target) {

    int len=nums.size();
    if(len==0)
        return 0;
    return BinarySearch(nums,0,len-1,target);

}

int BinarySearch(vector<int>& nums,int s,int e,int target){
    /*if(s==e&&nums[s]!=target){
        if(target>nums[s])
            return s+1;
        else
            return s-1>0?s-1:0;
    }*/
    if(s>e)
        return s;
    int mid=(s+e)/2;
    if(nums[mid]==target)
        return mid;
    if(target<nums[mid])
        e=mid-1;
    else
        s=mid+1;
    return BinarySearch(nums,s,e,target);
}
