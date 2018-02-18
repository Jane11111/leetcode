#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector<int>& nums);
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
   // nums.push_back(5);
    nums.push_back(5);
    bool res=isPossible(nums);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}


bool isPossible(vector<int>& nums) {

    int len=nums.size();
    if(len==0)
        return true;
    vector<vector<int>> record;
    vector<int> t;
    record.push_back(t);
    for(int i=0;i<len;){
        int cur=nums[i];
        int j=record.size()-1;
        while(nums[i]==cur){
            if(j>=0&&(record[j].empty()||record[j][record[j].size()-1]==cur-1)) {
                //放到最后
                record[j].push_back(cur);
                j--;
            }
            else{
                vector<int> t;
                t.push_back(cur);
                record.push_back(t);
            }
            i++;
        }


    }
    for(int i=0;i<record.size();i++){
        if(record[i].size()<3)
            return false;
    }
    return true;

}