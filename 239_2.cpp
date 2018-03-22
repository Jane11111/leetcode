#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k){

    vector<int> res;
    if(nums.empty()||k<=0)
        return res;

    deque <int> myqueue;
    for(int i=0;i<nums.size();i++){

        while(!myqueue.empty()&&myqueue.front()<=i-k)
            myqueue.pop_front();

        while(!myqueue.empty()&&nums[i]>nums[myqueue.back()])
            myqueue.pop_back();

        myqueue.push_back(i);
        if(i>=k-1)
            res.push_back(nums[myqueue.front()]);
    }
    return res;

}