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
    vector<Interval> vec;

/** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {

        int i=0;
        for(;i<vec.size()&&val>=vec[i].start-1;i++){
            Interval interval=vec[i];
            if(val==interval.start||val==interval.end)
                return;
            if(val>=interval.start-1&&val<=interval.end+1)
                break;
        }

        int start=val,end=val;
        for(;i<vec.size()&&end>=vec[i].start-1;){
            start=min(start,vec[i].start);
            end=max(end,vec[i].end);
            vec.erase(vec.begin()+i);
        }
            vec.insert(vec.begin()+i,Interval(start,end));
    }

    vector<Interval> getIntervals() {
        return vec;
    }
};