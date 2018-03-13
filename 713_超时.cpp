#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int numSubarrayProductLessThanK(vector<int>& nums, int k) {

    int len=nums.size();
    int count=0;
    for(int i=0;i<len;i++){
        int sum=1;
        for(int j=i;j<len;j++){
            sum*=nums[j];
            if(sum<k)
                count++;
            else
                break;
        }
    }
    return count;

}