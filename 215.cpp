#include <iostream>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findKthLargest(vector<int>& nums, int k) {
    //插入排序
    int len=nums.size();
    for(int i=1;i<len;i++){
        int num=nums[i];
        for(int j=i-1;j>=0;j--){
            if(nums[j]<num)
                swap(nums[j],nums[j+1]);
        }
    }
    return nums[k-1];

}