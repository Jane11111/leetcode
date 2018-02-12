#include <iostream>
#include <vector>
#include<map>
vector<int> topKFrequent(vector<int>& nums, int k);
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> freq_map;
    int len=nums.size();
    for(int i=0;i<len;i++)
        freq_map[nums[i]]+=1;

    vector<int> vs[len+1];
    for(auto&it:freq_map){
        int num=it.first;
        int freq=it.second;
        vs[freq].push_back(num);
    }

    vector<int> res;
    for(int i=len;i>=0;i--){
        vector<int> tmp=vs[i];
        if(!tmp.empty()){
            for(int j=0;j<tmp.size();j++){
                res.push_back(tmp[j]);
                if(res.size()==k)
                    return res;
            }
        }

    }
    return res;

}