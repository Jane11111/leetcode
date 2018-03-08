#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<vector<int>>& intervals);
int intersectionSizeTwo(vector<vector<int>>& intervals);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void Sort(vector<vector<int>>& intervals){
    int len=intervals.size();
    while(len>0){
        int index=0;
        int start=INT_MAX;
        int max=INT_MIN;
        for(int i=0;i<len;i++){
            if(intervals[i][1]>max||intervals[i][1]==max&&intervals[i][0]<start){
                index=i;
                start=intervals[i][0];
                max=intervals[i][1];
            }
        }
        swap(intervals[index],intervals[len-1]);
        len--;
    }
}
int intersectionSizeTwo(vector<vector<int>>& intervals) {
    Sort(intervals);
    int len=intervals.size();
    int count=0;
    int last;
    int max;
    for(int i=0;i<len;i++){
        vector<int> inter=intervals[i];
        if(i==0){
            count+=2;
            last=inter[1]-1;
            max=inter[1];
        }else{
            if(inter[0]<max){
                if(last>=inter[0])
                    continue;
                if(max==inter[1]){
                    last=inter[1]-1;
                    count+=1;
                }else{
                    last=max;
                    max=inter[1];
                    count+=1;
                }


            }else if(inter[0]==max){
                count+=1;
                last=max;
                max=inter[1];

            }else{
                count+=2;
                last=inter[1]-1;
                max=inter[1];
            }
        }


    }
    return count;


}