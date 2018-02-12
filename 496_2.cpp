#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums){
    if(nums.size()==0){
        vector<int> res;
        return res;
    }
    vector<int> not_find;
    map<int,int> my_map;
    int len=nums.size();
    not_find.insert(not_find.begin(),nums[0]);
    for(int i=1;i<len;i++){
        int num=nums[i];
        while(!not_find.empty()&&num>not_find[0]){
            my_map[not_find[0]]=num;
            not_find.erase(not_find.begin());
        }
        not_find.insert(not_find.begin(),num);
    }
    vector<int> res;
    for(int i=0;i<findNums.size();i++){
        int num=findNums[i];
        if(my_map.count(num)==0)
            res.push_back(-1);
        else
            res.push_back(my_map[num]);
    }
    return res;
}