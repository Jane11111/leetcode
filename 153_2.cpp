#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
int findMin(vector<int>& nums){
    int res=nums[0];
    int l=0;
    int j=nums.size()-1;
    while(l<j){

        int mid=(l+j)/2;//mid不可能是j
        if(nums[mid]>=nums[l]){
            res=min(res,nums[l]);
            res=min(res,nums[j]);
            l=mid+1;
        }else{
            j=mid;
        }
    }
    return res;
}