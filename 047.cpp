#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums);
void isOk(vector<int> r,vector<int>& nums,bool used[]);
vector<vector<int>> res;
int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(9);
    vector<vector<int>> r=permuteUnique(nums);
    cout<<r.size()<<endl;
    return 0;
}

void isOk(vector<int> r,vector<int>& nums,bool used[]){
    int len=nums.size();
    if(r.size()==len){
        res.push_back(r);
        return;
    }
    for(int i=0;i<len;){
        int num=nums[i];
        if(!used[i]){
            r.insert(r.begin(),num);
            used[i]=true;
            isOk(r,nums,used);
            used[i]=false;
            r.erase(r.begin());
            i++;
            while(i<len&&nums[i]==num)
                i++;
        }else
            i++;


    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    int len=nums.size();
    if(len==0)
        return res;
    for(int i=1;i<len;i++){//排序
        int num=nums[i];
        for(int j=i-1;j>=0;j--){
            if(nums[j]>num)
                swap(nums[j],nums[j+1]);
        }
    }
    bool used[len];
    for(int i=0;i<len;i++)
        used[i]=false;
    vector<int > r;
    isOk(r,nums,used);
    return res;
}