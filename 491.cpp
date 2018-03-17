#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<int>> res;
vector<vector<int>> findSubsequences(vector<int>& nums);
void dfs(vector<int> list,int s,vector<int>& nums,vector<map<int,bool>>& graph);
int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(7);
    vector<vector<int>> res=findSubsequences(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j];
        cout<<endl;
    }
}
void dfs(vector<int> list,int s,vector<int>& nums,vector<map<int,bool>>& graph){


    list.push_back(nums[s]);
    if(list.size()>=2)
        res.push_back(list);
    map<int,bool> neighbors=graph[s];

    map<int,bool>::iterator ite=neighbors.begin();
    while(ite!=neighbors.end()){
        dfs(list,ite->first,nums,graph);
        ite++;
    }


}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    int len=nums.size();
    vector<map<int,bool>> graph;

    for(int i=0;i<len;i++){
        map<int,bool> neighbors;
        map<int,bool> tmp;
        for(int j=i+1;j<len;j++){
            if(nums[j]>=nums[i]&&tmp.find(nums[j])==tmp.end()){
                neighbors[j]=true;
                tmp[nums[j]]=true;
            }
        }
        graph.push_back(neighbors);
    }

    map<int,bool> visited;
    for(int i=0;i<len;i++){
        vector<int> list;
        if(visited.find(nums[i])==visited.end()) {
            dfs(list, i, nums, graph);
            visited[nums[i]]=true;
        }
    }

    return res;




}