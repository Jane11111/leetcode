#include <iostream>
#include <cmath>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int missingNumber(vector<int>& nums) {
    int len=nums.size();
    for(int i=0;i<len;i++)
        nums[i]+=1;
    nums.push_back(1);
    for(int i=0;i<len;i++){
        int index=abs(nums[i])-1;
        nums[index]*=-1;
    }
    for(int i=0;i<=len;i++){
        if(nums[i]>0)
            return i;
    }
    return 0;

}