#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int,int> mymap;
    for(int i=0;i<nums.size();i++){
        if(mymap.count(nums[i])){
            if(i-mymap[nums[i]]<=k)
                return true;
        }
        mymap[nums[i]]=i;
    }
    return false;

}