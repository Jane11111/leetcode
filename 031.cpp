#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void nextPermutation(vector<int>& nums) {

    if(nums.empty())
        return ;
    int i=nums.size()-1;
    for(;i>=1;i--){
        if(nums[i-1]<nums[i])
            break;
    }
    if(i==0){//需要全部调转
        int lo=0;
        int hi=nums.size()-1;
        while(lo<hi){
            swap(nums[lo],nums[hi]);
            lo++;
            hi--;
        }
    }else{
        int lo=i;
        int hi=nums.size()-1;
        while(lo<hi){
            swap(nums[lo],nums[hi]);
            lo++;
            hi--;
        }
        for(int t=i;t<nums.size();t++){
            if(nums[t]>nums[i-1]){
                swap(nums[t],nums[i-1]);
                break;
            }
        }
    }

}