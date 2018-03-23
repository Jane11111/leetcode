#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);

int main() {
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(-1);
    int k=1;
    int t=-1;
    bool res=containsNearbyAlmostDuplicate(nums,k,t);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}


bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
    if(nums.size()<=1||k==0||t<0)
        return false;

    long long gap= t==0?1:t;

    map<long long,long long> buckets;
    long long s=INT_MAX;
    long long l=INT_MIN;

    for (int i=0;i<nums.size();i++){
        s=s<nums[i]?s:nums[i];
        l=l>nums[i]?l:nums[i];
    }

    for(int i=0;i<nums.size();i++){
        long long num=nums[i];
        long long index=(num-s)/gap;
        if(buckets.find(index)!=buckets.end()&&abs(buckets[index]-i)<=k||
                buckets.find(index-1)!=buckets.end()&&abs(buckets[index-1]-i)<=k&&abs(nums[buckets[index-1]]-num)<=t||
                buckets.find(index+1)!=buckets.end()&&abs(buckets[index+1]-i)<=k&&abs(nums[buckets[index+1]]-num)<=t)
            return true;

        buckets[index]=i;
    }
    return false;


}