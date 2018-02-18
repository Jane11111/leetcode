#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int minSubArrayLen(int s, vector<int>& nums) {
    int res=0;

    int len=nums.size();

    for(int i=0;i<len;i++){
        int sum=nums[i];
        int count=1;
        int j=i+1;
        while(sum<s&&j<len){
            count+=1;
            sum+=nums[j];
            j++;
        }
        if(sum>=s&&(count<res||res==0))
            res=count;
    }
    return res;

}