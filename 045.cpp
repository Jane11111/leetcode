#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int jump(vector<int>& nums) {
    int len=nums.size();
    if(len==0)
        return 0;

    int count=0;
    int pre_max=0;
    int max_reach=0;
    for(int i=0;i<len&&i<=max_reach;i++){
        if(i>pre_max){
            count++;
            pre_max=max_reach;
        }
        if(i+nums[i]>max_reach)
            max_reach=i+nums[i];
    }

    return count;

}