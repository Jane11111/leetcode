#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int removeElement(vector<int>& nums, int val) {
    int len=nums.size();
    
    for(int i=0;i<len;){
        if(nums[i]==val){
            nums.erase(nums.begin()+i);
            len--;
        }else{
        i++;
        }
    }
    return len;

}