#include <iostream>
#include <vector>
using namespace std;

bool can(vector<int>& nums,int s1,int s2,int s3,int s4,int target);
bool makesquare(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool can(vector<int>& nums,int s1,int s2,int s3,int s4,int target){
    if(nums.empty()&&s1==target&&s2==target&&s3==target&&s4==target)
        return true;
    if(nums.empty())
        return false;
    int num=nums[0];
    nums.erase(nums.begin());
    bool f1=false;
    bool f2=false;
    bool f3=false;
    bool f4=false;
    if(num+s1<=target)
        f1=can(nums,s1+num,s2,s3,s4,target);
    if(f1)
        return f1;
    if(num+s2<=target&&s2!=s1)
        f2=can(nums,s1,s2+num,s3,s4,target);
    if(f2)
        return f2;
    if(num+s3<=target&&s3!=s2&&s3!=s1)
        f3=can(nums,s1,s2,s3+num,s4,target);
    if(f3)
        return f3;
    if(num+s4<=target&&s4!=s3&&s4!=s2&&s4!=s1)
        f4=can(nums,s1,s2,s3,s4+num,target);
    if(f4)
        return f4;

    nums.insert(nums.begin(),num);
    return false;


}
bool makesquare(vector<int>& nums) {

    int sum=0;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];
    if(sum%4||nums.size()<4)
        return false;


    int target=sum/4;

    int s1=0;
    int s2=0;
    int s3=0;
    int s4=0;
    bool res=can(nums,s1,s2,s3,s4,target);
    return res;



}