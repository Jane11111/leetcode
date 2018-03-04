#include <iostream>
#include<cmath>
#include <vector>
using namespace std;
int arrayNesting(vector<int>& nums);
int main() {
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(2);
    int res=arrayNesting(nums);
    cout<<res<<endl;
    return 0;
}



int arrayNesting(vector<int>& nums) {

    int res=0;
    int len=nums.size();
    for(int i=0;i<len;i++)
        nums[i]+=1;

    for(int x:nums){
        int index=abs(x)-1;
        if(nums[index]>0){//x这个数还没用过
            int count=0;
            while(nums[index]>0){
                nums[index]*=-1;//将x这个数标记为用过
                count++;
                index=abs(nums[index])-1;
            }
            res=res>count?res:count;
        }
    }
    return res;

}