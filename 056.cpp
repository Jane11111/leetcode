#include <iostream>
#include<vector>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval():start(0),end(0){}
    Interval(int s,int e):start(s),end(e){}
};
vector<Interval> merge(vector<Interval>& intervals);
void PrintVector(vector<Interval>& res){
    int len=res.size();
    for(int i=0;i<len;i++){
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
}
int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1,4));
    intervals.push_back(Interval(2,3));
    //intervals.push_back(Interval(8,10));
    //intervals.push_back(Interval(15,18));

    vector<Interval> res=merge(intervals);

    PrintVector(res);
}

vector<Interval> merge(vector<Interval>& intervals) {

    //首先按照start排序，若start相等，按照end排序，从小到大
    int len=intervals.size();
    if(len==0)
        return intervals;
    for(int i=0;i<len;i++){
        int s=intervals[i].start;
        int e=intervals[i].end;
        for(int j=i-1;j>=0;j--){
            if(intervals[j].start>s||
                    (intervals[j].start==s&&intervals[j].end>e))
                swap(intervals[j],intervals[j+1]);
        }
    }

    int cur=0;
    while(cur!=intervals.size()-1){
        Interval cur_interval=intervals[cur];
        Interval next_interval=intervals[cur+1];
        if(cur_interval.start==next_interval.start){
             intervals.erase(intervals.begin()+cur);
        }else{
            if(next_interval.start>cur_interval.end)
                cur+=1;
            else{
                if(cur_interval.end<next_interval.end)
                    intervals[cur].end=next_interval.end;
                intervals.erase(intervals.begin()+cur+1);
            }
        }
    }
    return intervals;


}