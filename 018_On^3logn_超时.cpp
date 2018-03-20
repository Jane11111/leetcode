#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);
int BiSearch(vector<int>& nums,int s,int e,int target);
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
int BiSearch(vector<int>& nums,int s,int e,int target){//返回索引
    if(s>e)
        return -1;
    int m=(s+e)/2;
    if(nums[m]==target)
        return m;
    if(target<nums[m])
        return BiSearch(nums,s,m-1,target);
    else
        return BiSearch(nums,m+1,e,target);
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
        int i1=i;
        int num1=nums[i];
        for(int j=i+1;j<nums.size();){
            int i2=j;
            int num2=nums[j];
            nums.erase(nums.begin()+j);
            int i3=BiSearch(nums,j,nums.size()-1,target-num1-num2);
            if(i3!=-1){
                vector<int> t;
                t.push_back(num1);
                t.push_back(num2);
                t.push_back(nums[i3]);
                res.push_back(t);
            }
            nums.insert(nums.begin()+j,num2);
            j++;
            while(j<nums.size()&&nums[j]==num2)
                j++;
        }
        i++;
        while(i<nums.size()&&nums[i]==num1)
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