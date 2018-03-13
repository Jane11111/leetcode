#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void rotate(vector<int>& nums, int k) {
    while(k>0){
        nums.insert(nums.begin(),nums[nums.size()-1]);
        nums.erase(nums.begin()+nums.size()-1);
        k--;
    }

}