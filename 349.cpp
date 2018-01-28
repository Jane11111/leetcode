#include <iostream>
#include<vector>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
bool isContain(vector<int>& nums,int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    vector<int> new_vector;
    int len1=nums1.size();
    int len2=nums2.size();
    for(int i=0;i<len1;i++){
        int num=nums1[i];
        for(int j=0;j<len2;j++){
            if(nums2[j]==num){
                if(!isContain(new_vector,num))
                    new_vector.push_back(num);
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