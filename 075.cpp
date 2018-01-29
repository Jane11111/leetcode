#include <iostream>
#include<vector>
using namespace std;
void sortColors(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void sortColors(vector<int>& nums) {
    int len=nums.size();
    for(int i=0;i<len;i++){
        int num=nums[i];
        for(int j=i-1;j>=0;j--){
            if(nums[j]>num)
                swap(nums[j],nums[j+1]);
        }
    }

}