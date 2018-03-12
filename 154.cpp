#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums);
int Rec(vector<int>& nums,int s,int e);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int Rec(vector<int>& nums,int s,int e){
    if(s==e||nums[s]<nums[e])
        return nums[s];
    int m=(s+e)/2;

    if(nums[m]>=nums[s])
        s=m+1;
    else
        e=m;
    return Rec(nums,s,e);

}
int findMin(vector<int>& nums) {

    for(int i=0;i<nums.size();){
        int num=nums[i];
        i++;
        while(i<nums.size()&&nums[i]==num)
            nums.erase(nums.begin()+i);
    }
    if(nums.size()>=2&&nums[0]==nums[nums.size()-1])
        nums.erase(nums.begin());

    int res=Rec(nums,0,nums.size()-1);
    return res;

}