#include <iostream>
#include<vector>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval():start(0),end(0){}
    Interval(int s,int e):start(s),end(e){}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) ;
void swap(int* arr,int n1,int n2);
void PrintVector(vector<Interval> intervals);

int main() {
    vector<Interval> intervals;
    Interval newInterval=Interval(3,4);
    intervals.push_back(Interval(0,5));
    intervals.push_back(Interval(8,9));
    //intervals.push_back(Interval(6,7));
    //intervals.push_back(Interval(8,10));
    //intervals.push_back(Interval(12,16));

    vector<Interval>result=insert(intervals,newInterval);
    PrintVector(result);
}
void PrintVector(vector<Interval> intervals){
    int len=intervals.size();
    Interval interval;
    for(int i=0;i<len;i++){
        interval=intervals[i];
        cout<<interval.start<<" "<<interval.end<<endl;
    }
}

void swap(int* arr, int n1,int n2){
    int tmp=arr[n1];
    arr[n1]=arr[n2];
    arr[n2]=tmp;
}



vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    int size=intervals.size();


    if(size==0){
        vector<Interval> result;
        result.push_back(newInterval);
        return result;
    }

    int nums[size*2];
    int index=0;
    //把intervals中的数全都取出来放到nums数组中
    for (int i=0;i<size;i++){
        Interval interval=intervals[i];
        nums[index]=interval.start;
        nums[index+1]=interval.end;
        index+=2;
    }
    //插入排序
    for(int i=0;i<size*2;i++){
        int n=nums[i];
        for(int j=i-1;j>=0;j--){
            if(nums[j]>n){
                swap(nums,j,j+1);
            }
            else{
                break;
            }
        }
    }

    if (newInterval.start>newInterval.end){
        int tmp=newInterval.start;
        newInterval.start=newInterval.end;
        newInterval.end=tmp;
    }

    int first_larger_than_s=size*2;//这个数及其后面的全都比start大,这个数及其之后的数都应被删除
    int last_smaller_than_e=-1;//这个数及其前面全都比end小，这个数及其之前的数都应被删除

    for(int i=0;i<size*2;i++){
        if(nums[i]>=newInterval.start){
            first_larger_than_s=i;
            break;
        }
    }
    for(int i=size*2-1;i>=0;i--){
        if(nums[i]<=newInterval.end){
            last_smaller_than_e=i;
            break;
        }
    }
    vector<int> new_nums;
    bool ifdel[2];

    if(first_larger_than_s<=last_smaller_than_e) {//first_larger_than_s 至 last_smaller_than_e 闭区间内的数都应被删除

        //判断 newInteravl 内的书是否需要被删除
        if ((first_larger_than_s % 2) == 1)
            ifdel[0] = true;
        else
            ifdel[0] = false;
        if (last_smaller_than_e % 2 == 1)
            ifdel[1] = false;
        else
            ifdel[1] = true;

        //构造一个新的nums数组
        for(int i=0;i<size*2;i++){
            if(i<first_larger_than_s||i>last_smaller_than_e)
                new_nums.push_back(nums[i]);
            if(i==first_larger_than_s)
                if(!ifdel[0])
                    new_nums.push_back(newInterval.start);
            if(i==last_smaller_than_e)
                if(!ifdel[1])
                    new_nums.push_back(newInterval.end);
        }

    }else{//或者newInterval被包含在某一个interval之间，或者newInterval不于任何interval重叠
        //判断newInterval被包含在某一个interval之间还是不于任何interval重叠
        if(last_smaller_than_e-first_larger_than_s==-1&&first_larger_than_s<size*2&&last_smaller_than_e>=0&&last_smaller_than_e%2==0){
            ifdel[0]=true;
            ifdel[1]=true;
        }else{
            ifdel[0]=false;
            ifdel[1]=false;
        }
        //构造新的nums
        for(int i=0;i<size*2;i++){
            if(!ifdel[0] && newInterval.end<nums[i]){
                new_nums.push_back(newInterval.start);
                new_nums.push_back(newInterval.end);
                ifdel[0]=true;
                ifdel[1]=true;
            }
            new_nums.push_back(nums[i]);
            new_nums.push_back(nums[i+1]);
            i+=1;
        }
        if(!ifdel[0] && newInterval.start>nums[size*2-1]){
            new_nums.push_back(newInterval.start);
            new_nums.push_back(newInterval.end);
        }

    }

    //新的interval即为结果
    vector<Interval> result;
    int len=new_nums.size();
    for(int i=0;i<len;i++){
        Interval interval(new_nums[i],new_nums[i+1]);
        result.push_back(interval);
        i+=1;
    }

    return result;

    }