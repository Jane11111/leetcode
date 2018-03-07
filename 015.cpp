#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);
void SelectSort(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void SelectSort(vector<int>& nums){
    int len=nums.size();
    while(len>0){
        int max=INT_MIN;
        int index=0;
        for(int i=0;i<len;i++){
            if(nums[i]>max){
                max=nums[i];
                index=i;
            }
        }
        swap(nums[len-1],nums[index]);
        len--;
    }

}
vector<vector<int>> threeSum(vector<int>& nums) {

    SelectSort(nums);
    int len=nums.size();
    vector<vector<int>> res;
    for(int k=0;k<len-1;){
        int num=nums[k];
        int i=k+1;
        int j=len-1;

        while(i<j){
            if(nums[i]+nums[j]==-num){
                vector<int> r;
                r.push_back(num);
                r.push_back(nums[i]);
                r.push_back(nums[j]);
                res.push_back(r);
                i++;
                while(i<len&&nums[i]==nums[i-1])
                    i++;

            }else if(nums[i]+nums[j]<-num){
                i++;
                while(i<len&&nums[i]==nums[i-1])
                    i++;
            }else{
                j--;
                while(j>=i&&nums[j]==nums[j+1])
                    j--;

            }
        }
        k++;
        while(k<len&&nums[k]==nums[k-1])
            k++;
    }

    return res;
}