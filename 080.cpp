#include <iostream>
#include<vector>
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
        i++;
        if(i<len&&nums[i]==num){
            i++;
            while(i<len&&nums[i]==num){
                nums.erase(nums.begin()+i);
                len--;
            }
        }
    }
    return nums.size();

}