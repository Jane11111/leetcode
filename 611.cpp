#include <iostream>
#include <vector>
using namespace std;

int triangleNumber(vector<int>& nums);
void SelectSort(vector<int>& nums);
int maxIndex(vector<int>& nums,int s,int e,int target);
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    int res=triangleNumber(nums);
    cout<<res<<endl;
}
void SelectSort(vector<int>& nums){
    int len=nums.size();
    while(len>0){//选择排序
        int index=0;
        int max=INT_MIN;
        for(int i=0;i<len;i++){
            if(nums[i]>max){
                max=nums[i];
                index=i;
            }

        }
        swap(nums[index],nums[len-1]);
        len--;
    }
}
//小于target的最大的下标
int maxIndex(vector<int>& nums,int s,int e,int target){

    if(s==e&&nums[s]>=target||s>e)
        return -1;//未找到
    if(s==e)
        return s;
    int mid=(s+e)/2;
    if(nums[mid]<target){
        if(nums[mid+1]>=target)
            return mid;
        else{
            return maxIndex(nums,mid+1,e,target);
        }

    }else {
        return maxIndex(nums,s,mid-1,target);
    }
}
int triangleNumber(vector<int>& nums) {

    SelectSort(nums);
    int count=0;
    int len=nums.size();
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            int target=nums[i]+nums[j];
            int last=maxIndex(nums,j+1,len-1,target);
            if(last!=-1){
                count+=(last-j);
            }
        }
    }
    return count;

}