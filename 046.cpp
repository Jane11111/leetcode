#include <iostream>
#include <vector>
using namespace std;

void reOrder(vector<int>& nums,vector<int>& re_nums,bool used[]);
vector<vector<int>> permute(vector<int>& nums);
vector<vector<int>> res;
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>>r=permute(nums);
    cout<<r.size()<<endl;
}


void reOrder(vector<int>& nums,vector<int>& re_nums,bool used[]){
    int len=nums.size();
    if(re_nums.size()==len)
        res.push_back(re_nums);
    else{

        for(int i=0;i<len;i++){
            if(!used[i]){
                used[i]=true;
                re_nums.insert(re_nums.begin(),nums[i]);
                reOrder(nums,re_nums,used);
                used[i]=false;
                re_nums.erase(re_nums.begin());
            }
        }
    }

}
vector<vector<int>> permute(vector<int>& nums) {
    vector<int> re_nums;
    int len=nums.size();
    if(len){
        bool used[len];
        for(int i=0;i<len;i++)
            used[i]=false;
        for(int i=0;i<len;i++) {
            used[i]=true;
            re_nums.insert(re_nums.begin(),nums[i]);
            reOrder(nums, re_nums, used);
            re_nums.erase(re_nums.begin());
            used[i]=false;
        }
    }
    return res;
}