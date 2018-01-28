#include <iostream>
#include<vector>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
bool isContain(vector<int>& nums,int n);
void PrintVector(vector<int> v);
int main() {
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums2.push_back(1);
    vector<int> result=intersect(nums1,nums2);
    PrintVector(result);
}
void PrintVector(vector<int> v){
    int len=v.size();
    for(int i=0;i<len;i++)
        cout<< v[i]<<endl;
}
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {


    vector<int> new_vector;
    int len1=nums1.size();
    int len2=nums2.size();
    if(len2==0){
        return new_vector;
    }

    bool is_used[len2];
    for(int i=0;i<len2;i++)
        is_used[i]=false;
    for(int i=0;i<len1;i++){
        int num=nums1[i];
        for(int j=0;j<len2;j++){
            if((!is_used[j])&&nums2[j]==num){
                new_vector.push_back(num);
                is_used[j]=true;
                break;
            }
        }
    }
    return new_vector;

}
bool isContain(vector<int>& nums,int n){
    int len=nums.size();
    for(int i =0 ;i<len;i++){
        if(nums[i]==n)
            return true;
    }
    return false;
}