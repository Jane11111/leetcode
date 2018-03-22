#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    if(nums.empty())
        return res;
    int len=nums.size();

    stack<int> mystack;
    vector<int> right(len,-1);
    for(int i=0;i<nums.size();i++){

        while(!mystack.empty()&&nums[i]>nums[mystack.top()]) {
            right[mystack.top()]=i;
            mystack.pop();
        }
        mystack.push(i);

    }

    for(int i=0;i<nums.size()-k+1;i++){
        if(right[i]==-1||right[i]>=i+k){
            res.push_back(nums[i]);
        }else{
            int last_index=right[i];
            while(right[last_index]!=-1&&right[last_index]<i+k)
                last_index=right[last_index];
            res.push_back(nums[last_index]);
        }
    }
    return res;

}