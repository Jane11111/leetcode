#include <iostream>
#include <vector>
using namespace std;

int thirdMax(vector<int>& nums);
int main() {
    vector<int> nums;
    //nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    int res=thirdMax(nums);
    cout<<res<<endl;
}

int thirdMax(vector<int>& nums) {

    int count=3;
    if(nums.size()<count)
        count=1;
    int res=0;
    int max=INT_MIN;
    bool first=true;
    while(count>0&&!nums.empty()){
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
            }
        }
        for(int i=0;i<nums.size();){
            if(nums[i]==max){
                nums.erase(nums.begin()+i);
            }else{
                i++;
            }
        }

        if(first){
            first=false;
            res=max;
        }
        max=INT_MIN;
        count--;
    }

    if(count==0)
        res=max;
    return res;
}