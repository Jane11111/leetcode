#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findDuplicates(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
vector<int> findDuplicates(vector<int>& nums) {

    vector<int> res;
    for(int x:nums){
        int index=abs(x)-1;
        if(nums[index]<0)
            res.push_back(abs(x));
        else
            nums[index]*=(-1);
    }
    return res;
}