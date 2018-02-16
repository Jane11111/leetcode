#include <iostream>
#include <vector>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval():start(0),end(0){}
    Interval(int s,int e):start(s),end(e){}
};
vector<int> findRightInterval(vector<Interval>& intervals);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> findRightInterval(vector<Interval>& intervals) {

    int len=intervals.size();
    vector<int> res;
    for(int i=0;i<len;i++)
        res.push_back(-1);

    vector<int> index;




    for(int i=0;i<len;i++){
        index.push_back(i);
        Interval p=intervals[i];
        for(int j=i-1;j>=0;j--){
            if(intervals[j].start>p.start) {
                swap(intervals[j], intervals[j + 1]);
                swap(index[j],index[j+1]);
            }
            else
                break;
        }

    }

    for(int i=0;i<len;i++){
        Interval p=intervals[i];
        for(int j=i+1;j<len;j++){
            Interval q=intervals[j];
            if(q.start>=p.end){
                res[index[i]]=index[j];
                break;
            }
        }
    }
    return res;
}