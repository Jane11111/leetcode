#include <iostream>
#include <vector>
using namespace std;

struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
     };
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class SummaryRanges {
public:
    vector<int> nums;
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {

        int i=0;
        for(i;i<nums.size();i++)
            if(val<=nums[i]){
                break;
            }
        if(i<nums.size()&&nums[i]==val)
            return ;
        nums.insert(nums.begin()+i,val);

    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        for(int i=0;i<nums.size();){
            int start=i;
            int end=i+1;
            while(end<nums.size()&&nums[end]==nums[end-1]+1)
                end++;
            end--;
            Interval interval;
            interval.start=nums[start];
            interval.end=nums[end];

            res.push_back(interval);
            i=end+1;

        }

        return res;



    }
};