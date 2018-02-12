#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums);
int main() {
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(4);
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(2);
    vector<int> res=nextGreaterElement(nums1,nums2);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

    int len=nums.size();
    map<int,int> my_map;
    for(int i=0;i<len;i++)
        my_map[nums[i]]=i;

    vector<int> res;
    for(int i=0;i<findNums.size();i++){
        int num=findNums[i];
        int index=my_map[num];
        int j;
        for( j=index+1;j<len;j++){
            if(nums[j]>num){
                res.push_back(nums[j]);
                break;
            }
        }
        if(j==len)
            res.push_back(-1);

    }
    return res;

}