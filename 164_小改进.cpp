#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maximumGap(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int maximumGap(vector<int>& nums) {
    if(nums.size()<=1)
        return 0;

    int s=nums[0];
    int l=nums[0];
    for(int i=0;i<nums.size();i++){
        s=min(s,nums[i]);
        l=max(l,nums[i]);
    }

    int len=nums.size();
    int gap=ceil(double(l-s)/(len-1));

    vector<int> min_buc(len-1,INT_MAX);
    vector<int> max_buc(len-1,INT_MIN);

    for(int i=0;i<len;i++){
        int num=nums[i];
        if(num==s||num==l)
            continue;
        int idx=(num-s)/gap;
        min_buc[idx]=min(min_buc[idx],num);
        max_buc[idx]=max(max_buc[idx],num);
    }

    int pre=s;
    int max_gap=0;
    for(int i=0;i<len-1;i++){
        if(min_buc[i]==INT_MAX)
            continue;
        max_gap=max(min_buc[i]-pre,max_gap);
        pre=max_buc[i];
    }
    max_gap=max(max_gap,l-pre);
    return max_gap;



}