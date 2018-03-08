#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int wiggleMaxLength(vector<int>& nums) {
    int len=nums.size();
    if(len==0)
        return 0;
    int count=1;
    int i=1;
    while(i<len){

        int down=0;
        int up=0;
        while(i<len&&nums[i]<=nums[i-1]){
            if(nums[i]!=nums[i-1])
                down=1;
            i++;
        }

        while(i<len&&nums[i]>=nums[i-1]) {
            if(nums[i]!=nums[i-1])
                up = 1;
            i++;
        }

        count+=(down+up);
    }
    return count;

}