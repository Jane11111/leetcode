#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void moveZeroes(vector<int>& nums) {

    int len=nums.size();
    int cur=0;
    for(int i=0;i<len;i++){
        if(nums[cur]==0){
            nums.push_back(0);
            nums.erase(nums.begin()+cur);
        }else{
            cur++;
        }
    }

}