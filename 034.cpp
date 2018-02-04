#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target);
int BinaryLeft(vector<int>& nums,int s,int e,int target);
int BinaryRight(vector<int>& nums,int s,int e,int target);

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    int target=8;
    vector<int> res=searchRange(nums,target);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}

vector<int> searchRange(vector<int>& nums, int target) {

    int len=nums.size();
    vector<int> res;
    int left=BinaryLeft(nums,0,len-1,target);
    int right=BinaryRight(nums,0,len-1,target);
    res.push_back(left);
    res.push_back(right);
    return res;
}

int BinaryLeft(vector<int>& nums,int s,int e,int target){
    if(s>e)
        return -1;
    int mid=(s+e)/2;
    if(target==nums[mid]&&(mid==0||nums[mid-1]<target))
        return mid;
    if(target==nums[mid]&&nums[mid-1]==target)
        e=mid-1;
    else if(target<nums[mid])
        e=mid-1;
    else
        s=mid+1;
    return BinaryLeft(nums,s,e,target);
}
int BinaryRight(vector<int>& nums,int s,int e,int target){
    if(s>e)
        return -1;
    int mid=(s+e)/2;
    if(target==nums[mid]&&(mid==nums.size()-1||target<nums[mid+1]))
        return mid;
    if(target==nums[mid]&&target==nums[mid+1])
        s=mid+1;
    else if(target<nums[mid])
        e=mid-1;
    else
        s=mid+1;
    return BinaryRight(nums,s,e,target);
}