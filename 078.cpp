#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> subsets(vector<int>& nums);
void genSet(vector<int> r,int n,int start,bool used[],vector<int>& nums);
vector<vector<int>> res;
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> r=subsets(nums);
    cout<<r.size()<<endl;
}

//n是subset元素个数，start是当前最大下标（下一个需有更大下标），used纪录是否已在集合中
void genSet(vector<int> r,int n,int start,bool used[],vector<int>& nums){
    if(r.size()==n){
        res.push_back(r);
        return;
    }
    int len=nums.size();
    for(int i=start+1;i<len;i++){
        if(!used[i]){
            used[i]=true;
            r.insert(r.begin(),nums[i]);
            genSet(r,n,i,used,nums);
            r.erase(r.begin());
            used[i]=false;

        }
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    int len=nums.size();
    vector<int> r;
    res.push_back(r);
    if(len==0)
        return res;
    bool used[len];
    for(int i=0;i<len;i++)
        used[i]=false;

    for(int count=1;count<=len;count++){
       // for(int start=0;start<len;start++){
            genSet(r,count,-1,used,nums);
        //}
    }
    return res;
}