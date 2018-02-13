#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
vector<int> nextGreaterElements(vector<int>& nums) {


    int len=nums.size();
    vector<int> res;
    for(int i=0;i<len;i++)
        res.push_back(-1);
    stack<int> myStack;
    for(int i=0;i<len;i++){
        int num=nums[i];
        while(!myStack.empty()&&num>nums[myStack.top()]){
            res[myStack.top()]=num;
            myStack.pop();
        }
        myStack.push(i);
    }
    for(int i=0;i<len;i++){
        int num=nums[i];
        while(!myStack.empty()&&num>nums[myStack.top()]){
            res[myStack.top()]=num;
            myStack.pop();
        }
    }
    return res;

}