#include <iostream>
#include <vector>
using namespace std;
int findTargetSumWays(vector<int>& nums, int S);
int ResiveFind(vector<int>& nums,int s,int index);
int main() {
    vector<int> nums(8,0);
    int s=1;
    /*nums.push_back(7);
    nums.push_back(0);
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(9);*/
    nums.push_back(1);
   /* nums.push_back(7);
    nums.push_back(2);
    nums.push_back(3);*/
    int res=findTargetSumWays(nums,s);
    cout<<res<<endl;
}
int findTargetSumWays(vector<int>& nums, int S) {
    if(nums.size()==0)
        return 0;
    int res=ResiveFind(nums,S,nums.size()-1);
    return res;

}

int ResiveFind(vector<int>& nums,int s,int index){
    if(index==0&&(s==nums[0]&&s==0))
        return 2;
    if(index==0&&(s==nums[0]||s==-nums[0]))
        return 1;
    else if(index==0&&s!=nums[0]&&s!=-nums[0])
        return 0;
    int res=0;
    res+=ResiveFind(nums,s-nums[index],index-1);
    res+=ResiveFind(nums,s+nums[index],index-1);
    return res;
}