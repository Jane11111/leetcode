#include <iostream>
#include <vector>
using namespace std;

void genSet(vector<int> set,int start,vector<int>& nums);
vector<vector<int>> subsetsWithDup(vector<int>& nums);
void MergeSort(vector<int>& nums,int s,int e);
void Merge(vector<int>&  nums,int s,int m,int e);
vector<vector<int>> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void MergeSort(vector<int>& nums,int s,int e){
    if(s>=e)
        return;
    int m=(s+e)/2;
    MergeSort(nums,s,m);
    MergeSort(nums,m+1,e);
    Merge(nums,s,m,e);
}
void Merge(vector<int>&  nums,int s,int m,int e){
    vector<int> left;
    vector<int> right;
    for(int i=s;i<=m;i++)
        left.push_back(nums[i]);
    left.push_back(INT_MAX);
    for(int i=m+1;i<=e;i++)
        right.push_back(nums[i]);
    right.push_back(INT_MAX);

    int i=0;int j=0;
    for(int index=s;index<=e;index++){
        if(left[i]<=right[j]){
            nums[index]=left[i];
            i++;
        }else{
            nums[index]=right[j];
            j++;
        }
    }
}
void genSet(vector<int> set,int start,vector<int>& nums){
    res.push_back(set);
    int len=nums.size();
    for(int i=start;i<len;){
        int num=nums[i];
        set.insert(set.begin(),num);
        genSet(set,i+1,nums);
        set.erase(set.begin());
        i++;
        while(i<len&&nums[i]==num)
            i++;
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<int> set;
    int len=nums.size();
    MergeSort(nums,0,len-1);
    genSet(set,0,nums);
    return res;
}