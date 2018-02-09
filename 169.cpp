#include <iostream>
#include <vector>
#include <map>
using namespace std;
int majorityElement(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int majorityElement(vector<int>& nums) {
    int len=nums.size();

    int res=0;
    map<int,int> res_map;
    for(int i=0;i<len;i++){
        int num=nums[i];
        if(res_map.count(num)==0)
            res_map[num]=0;
        res_map[num]+=1;
        if(res_map[num]>len/2)
            return num;
    }
    return res;

    }