#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void genSet(vector<int> set,vector<int>& candidates,int start,int target);
vector<vector<int>> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void genSet(vector<int> set,vector<int>& candidates,int start,int target){
    if(target==0){
        res.push_back(set);
        return ;
    }
    int len=candidates.size();
    for(int i=start;i<len;i++){
        if(candidates[i]<=target){
            set.insert(set.begin(),candidates[i]);
            genSet(set,candidates,i,target-candidates[i]);
            set.erase(set.begin());
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<int> set;
    genSet(set,candidates,0,target);
    return res;
}