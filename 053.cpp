#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int maxSubArray(vector<int>& nums) {

    int len=nums.size();
    int res=nums[0];
    for(int i=0;i<nums.size();i++){
        int num=nums[i];
        if(num>res)
            res=num;
        if(num>0){//以这个数开始是否存在着一个子串
            int max=INT_MIN;
            int sum=0;
            for(int j=i+1;j<len;j++){
                sum+=nums[j];
                if(sum>max)
                    max=sum;
            }
            if(max>0&&num+max>res)
                res=num+max;
        }
    }
    return res;
}