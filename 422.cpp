#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findDuplicates(vector<int>& nums);
int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(7);nums.push_back(8);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    vector<int> res=findDuplicates(nums);
    cout<<res.size()<<endl;
}

vector<int> findDuplicates(vector<int>& nums) {
    map<int,bool> mymap;
    vector<int> res;
    int len=nums.size();
    for(int i=0;i<len;i++){
        if(mymap.count(nums[i])){
            res.push_back(nums[i]);
        }
        mymap[nums[i]]=true;
    }
    return res;

}