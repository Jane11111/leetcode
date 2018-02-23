#include <iostream>
#include <vector>
using namespace std;

int findPairs(vector<int>& nums, int k);
void MergeSort(vector<int> & nums,int s,int e);
void Merge(vector<int>& nums,int s,int m,int e);
bool BiSearch(vector<int>& nums,int s,int e,int target);
int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(5);
    int k=2;
    int res=findPairs(nums,k);
    cout<<res<<endl;
}

void MergeSort(vector<int> & nums,int s,int e){
    if(s>=e)
        return;
    int m=(s+e)/2;
    MergeSort(nums,s,m);
    MergeSort(nums,m+1,e);
    Merge(nums,s,m,e);
}
void Merge(vector<int>& nums,int s,int m,int e){
    vector<int> left;
    vector<int> right;
    for(int i=s;i<=m;i++)
        left.push_back(nums[i]);
    left.push_back(INT_MAX);
    for(int i=m+1;i<=e;i++)
        right.push_back(nums[i]);
    right.push_back(INT_MAX);

    int i=0;
    int j=0;
    for(int index=s;index<=e;index++){
        if(left[i]<=right[j]) {
            nums[index] = left[i];
            i++;
        }
        else {
            nums[index] = right[j];
            j++;
        }
    }
}
bool BiSearch(vector<int>& nums,int s,int e,int target){
    if(s>e)
        return false;
    int m=(s+e)/2;

    if(nums[m]==target)
        return true;
    else if(nums[m]<target)
        s=m+1;
    else
        e=m-1;
    return BiSearch(nums,s,e,target);
}

int findPairs(vector<int>& nums, int k) {
    int len=nums.size();
    if(len==0)
        return 0;

    MergeSort(nums,0,len-1);
    /*for(int i=0;i<len;){
        int num=nums[i];
        i++;
        while(i<len&&nums[i]==num) {
            nums.erase(nums.begin() + i);
            len--;
        }
    }*/

    int res=0;
    for(int i=0;i<len;){
        int num=nums[i];
        int target=num+k;
        bool f=BiSearch(nums,i,len-1,target);
        if(f)
            res++;
        i++;
        while(i<len&&nums[i]==num)
            i++;

    }

    return res;

}