#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


vector<int> findDisappearedNumbers(vector<int>& nums) {
    for(int x:nums){
        int index=abs(x)-1;
        if(nums[index]>0)
            nums[index]*=(-1);
    }

    vector<int> res;
    for(int i=1;i<=nums.size();i++){
        if(nums[i-1]>0)
            res.push_back(i);
    }

    return res;
}