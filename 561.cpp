#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& nums,int s,int e);
int Partition(vector<int>& nums,int s,int e);
int arrayPairSum(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void QuickSort(vector<int>& nums,int s,int e){
    if(s>=e)
        return;
    int p=Partition(nums,s,e);
    QuickSort(nums,s,p-1);
    QuickSort(nums,p+1,e);
}
int Partition(vector<int>& nums,int s,int e){
    int pivot=nums[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(nums[j]<pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    i++;
    swap(nums[i],nums[e]);
    return i;

}
int arrayPairSum(vector<int>& nums) {
    int len=nums.size();
    QuickSort(nums,0,len-1);

    int sum=0;
    for(int i=0;i<len;i++){
        if(i%2==0)
            sum+=nums[i];
    }
    return sum;

}