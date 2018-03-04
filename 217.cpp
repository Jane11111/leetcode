#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool containsDuplicate(vector<int>& nums) {
    map<int,bool> mymap;
    for(int num:nums){
        if(mymap.count(num))
            return true;
        mymap[num]=true;
    }
    return false;
}