#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
int numSubarrayProductLessThanK(vector<int>& nums, int k){

    int len=nums.size();
    int start=0;
    int count=0;
    int mul=1;
    for(int i=0;i<len;i++){
        mul*=nums[i];
        if(mul<k){
            count+=(i-start+1);
        }else{
            while(start<=i&&mul>=k){
                mul/=nums[start];
                start++;
            }
            if(mul<k)
                count+=(i-start+1);
        }
    }
    return count;


}