#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int threeSumClosest(vector<int>& nums, int target);
void SelectSort(vector<int>&  nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void SelectSort(vector<int>&  nums){
    int len=nums.size();
    while(len>0){
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
int threeSumClosest(vector<int>& nums, int target) {

    SelectSort(nums);
    int len=nums.size();
    int res=INT_MAX;
    for(int k=0;k<len;k++){
        int num=nums[k];
        int i=k+1;
        int j=len-1;
        while(i<j){
            int r=num+nums[i]+nums[j];
            if(res==INT_MAX||abs(r-target)<abs(res-target))
                res=r;
            if(r==target)
                return target;
            else if(r>target){
                j--;
            }else{
                i++;
            }
        }
    }
    return res;


}