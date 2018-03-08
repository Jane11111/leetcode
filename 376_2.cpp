#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int wiggleMaxLength(vector<int>& nums){

    int len=nums.size();
    if(len==0)
    return 0;
    int up=1;
    int down=1;
    for(int i=1;i<len;i++){
        if(nums[i]>nums[i-1]){
            up=down+1;
        }else if(nums[i]<nums[i-1]){
            down=up+1;
        }
    }
    return max(up,down);
}