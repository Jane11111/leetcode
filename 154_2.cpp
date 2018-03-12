#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int findMin(vector<int>& nums){

    int low=0;
    int high=nums.size()-1;
    while(low<high){
        int m=(low+high)/2;
        if(nums[m]>nums[high]){
            low=m+1;
        }else if(nums[m]<nums[high])
            high=m;
        else
            high--;
    }
    return nums[low];

}
