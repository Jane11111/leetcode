#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int removeDuplicates(vector<int>& nums) {
    int len=nums.size();
    for(int i=0;i<len;){
        int num=nums[i];
        for(i++;i<len;){
            if(nums[i]==num){
                nums.erase(nums.begin()+i);
                len--;
            }else
                break;
        }
    }
    return nums.size();

}