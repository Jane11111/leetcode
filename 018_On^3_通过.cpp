#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);
void Sort(vector<int>&  nums);
vector<vector<int>> threeSum(vector<int>& nums,int s,int target);
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    vector<vector<int>> res=fourSum(nums,0);
    cout<<res.size()<<endl;
    return 0;
}
void Sort(vector<int>&  nums){
    for(int i=0;i<nums.size();i++){
        int num=nums[i];
        for(int j=i-1;j>=0;j--){
            if(nums[j]>num)
                swap(nums[j],nums[j+1]);
        }
    }
}
vector<vector<int>> threeSum(vector<int>& nums,int s,int target){
    vector<vector<int>> res;
    for(int i=s;i<nums.size();){
        int num=nums[i];
        int new_target=target-num;
        int lo=i+1;
        int hi=nums.size()-1;
        while(lo<hi){
            if(nums[lo]+nums[hi]==new_target){
                vector<int> r;
                r.push_back(num);
                r.push_back(nums[lo]);
                r.push_back(nums[hi]);
                res.push_back(r);
                int tmp=nums[lo];
                lo++;
                while(lo<hi&&nums[lo]==tmp)
                    lo++;
            }else if(nums[lo]+nums[hi]<new_target){
                lo++;
            }else{
                hi--;
            }
        }
        i++;
        while(i<nums.size()&&nums[i]==num)
            i++;
    }
    return res;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {

    Sort(nums);

    vector<vector<int>> res;
    for(int i=0;i<nums.size();){
        int i1=i;
        int num1=nums[i];
        vector<vector<int>> three_sum=threeSum(nums,i+1,target-num1);
        for(int k=0;k<three_sum.size();k++){
            three_sum[k].insert(three_sum[k].begin(),num1);
            res.push_back(three_sum[k]);
        }
        i++;
        while(i<nums.size()&&nums[i]==num1)
            i++;
    }
    return res;
}