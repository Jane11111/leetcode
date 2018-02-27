#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
void genSet(vector<int> set,int start,int target,vector<int>& candidates);
void MergeSort(vector<int>& candidates,int s,int e);
void Merge(vector<int>& candidates,int s,int m,int e);
vector<vector<int>> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void MergeSort(vector<int>& candidates,int s,int e){
    if(s>=e)
        return;
    int m=(s+e)/2;
    MergeSort(candidates,s,m);
    MergeSort(candidates,m+1,e);
    Merge(candidates,s,m,e);
}
void Merge(vector<int>& candidates,int s,int m,int e){
    vector<int> left;
    vector<int> right;
    for(int i=s;i<=m;i++)
        left.push_back(candidates[i]);
    left.push_back(INT_MAX);
    for(int i=m+1;i<=e;i++)
        right.push_back(candidates[i]);
    right.push_back(INT_MAX);
    int i=0,j=0;
    for(int index=s;index<=e;index++){
        if(left[i]<=right[j]){
            candidates[index]=left[i];
            i++;
        }else{
            candidates[index]=right[j];
            j++;
        }

    }
}
void genSet(vector<int> set,int start,int target,vector<int>& candidates){
    if(target==0){
        res.push_back(set);
        return;
    }
    int len=candidates.size();
    for(int i=start;i<len;){
        int num=candidates[i];
        if(num<=target){
            set.insert(set.begin(),num);
            genSet(set,i+1,target-num,candidates);
            set.erase(set.begin());
        }
        i++;
        while(i<len&&candidates[i]==num)
            i++;
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    int len=candidates.size();
    MergeSort(candidates,0,len-1);

    vector<int> set;
    genSet(set,0,target,candidates);

    return res;
}