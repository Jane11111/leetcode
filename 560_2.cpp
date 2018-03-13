#include <iostream>
#include <map>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int subarraySum(vector<int>& nums, int k) {
    int sum=0;
    map<int,int> mymap;
    int res=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k)
            res++;
        res+=mymap[sum-k];
        mymap[sum]++;
    }
    return res;
}