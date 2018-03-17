#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>& nums);
bool makesquare(vector<int>& nums);
bool can(vector<int>& nums,int start,int left,int count,int target,bool used[]);
int main() {
    vector<int> nums(4,5);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    bool res=makesquare(nums);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}
void Sort(vector<int>& nums){
    for(int i=1;i<nums.size();i++){
        int num=nums[i];
        for(int j=i-1;j>=0;j--){
            if(nums[j]>num)
                swap(nums[j],nums[j+1]);
        }

    }
}

bool can(vector<int>& nums,int start,int left,int count,int target,bool used[]){
    if(start==nums.size()&&left==0&&count==0)
        return true;
    if(start==nums.size()||(left==0&&count==0))
        return false;

    if(left==0)
        return can(nums,0,target,count-1,target,used);

    for(int i=start;i<nums.size();i++){
        if(used[i])
            continue;
        int num=nums[i];
        if(num<=left){
            used[i]=true;
            bool f=can(nums,i+1,left-num,count,target,used);
            if(f)
                return f;
            used[i]=false;
        }else{
            return false;
        }
    }
    return false;
}
bool makesquare(vector<int>& nums){

    int sum=0;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];
    if(sum%4||nums.size()<4)
        return false;

    Sort(nums);

    int target=sum/4;

    int left=0;
    int count=4;
    int start=0;
    bool used[nums.size()];
    for(int i=0;i<nums.size();i++)
        used[i]=false;
    bool res=can(nums,start,left,count,target,used);
    return res;
}