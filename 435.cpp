#include <iostream>
#include <vector>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval():start(0),end(0){}
    Interval(int s,int e):start(s),end(e){}
};

int eraseOverlapIntervals(vector<Interval>& intervals);
void MergeSort(vector<Interval>& intervals,int s,int e);
void Merge(vector<Interval>& intervals,int s,int mid,int e);

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1,100));
    intervals.push_back(Interval(11,22));
    intervals.push_back(Interval(1,11));
    intervals.push_back(Interval(2,12));

    int res=eraseOverlapIntervals(intervals);
    cout<<res<<endl;
}


void MergeSort(vector<Interval>& intervals,int s,int e){
    if(s>=e)
        return;
    int mid=(s+e)/2;
    MergeSort(intervals,s,mid);
    MergeSort(intervals,mid+1,e);
    Merge(intervals,s,mid,e);

}
void Merge(vector<Interval>& intervals,int s, int mid,int e){
    vector<Interval> t1;
    vector<Interval> t2;
    for(int i=s;i<=mid;i++)
        t1.push_back(intervals[i]);
    t1.push_back(Interval(INT_MAX,INT_MAX));
    for(int i=mid+1;i<=e;i++)
        t2.push_back(intervals[i]);
    t2.push_back(Interval(INT_MAX,INT_MAX));

    int i=0;
    int j=0;
    for(int index=s;index<=e;index++){
        if(t1[i].start<t2[j].start||t1[i].start==t2[j].start&&t1[i].end<t2[j].end){
            intervals[index]=t1[i];
            i++;
        }else{
            intervals[index]=t2[j];
            j++;
        }
    }
}


int eraseOverlapIntervals(vector<Interval>& intervals) {
    int res=0;
    int len=intervals.size();
    if(len==0)
        return 0;
    MergeSort(intervals,0,len-1);

    for(int i=0;i<len-1;i++){
        Interval interval1=intervals[i];
        Interval interval2=intervals[i+1];
        if(interval2.start<interval1.end){
            res++;

            if(interval1.end>interval2.end){//删除interval1
                intervals.erase(intervals.begin()+i);
                len--;
            }else{//删除interval2
                intervals.erase(intervals.begin()+i+1);
                len--;
            }
            i--;
        }

    }
    return res;
}