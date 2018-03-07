#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findMin(vector<int>& nums) {
    int len=nums.size();
    int res=INT_MAX;
    for(int i=0;i<len;i++)
        if(nums[i]<res)
            res=nums[i];
    return res;

}