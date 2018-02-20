#include <iostream>
#include <vector>
using namespace std;
int findMinArrowShots(vector<pair<int, int>>& points);
void MergeSort(vector<pair<int,int>>& points,int s,int e);
void Merge(vector<pair<int,int>>& points,int s,int m,int e);
int main() {
    vector<pair<int,int>>points;
    pair<int,int>p1={1,2};
    pair<int,int>p2={3,4};
    pair<int,int> p3={5,6};
    pair<int,int> p4={7,8};
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    int res=findMinArrowShots(points);
    cout<<res<<endl;
}
void MergeSort(vector<pair<int,int>>& points,int s,int e){
    if(s==e)
        return;
    int m=(s+e)/2;
    MergeSort(points,s,m);
    MergeSort(points,m+1,e);
    Merge(points,s,m,e);
}
void Merge(vector<pair<int,int>>& points,int s,int m,int e){

    vector<pair<int,int>> left;
    vector<pair<int,int>> right;
    for(int i=s;i<=m;i++)
        left.push_back(points[i]);
    left.push_back(pair<int,int>(INT_MAX,INT_MAX));

    for(int i=m+1;i<=e;i++){
        right.push_back(points[i]);
    }
    right.push_back(pair<int,int>(INT_MAX,INT_MAX));

    int i=0;int j=0;
    for(int index=s;index<=e;index++){
        if(left[i].second<=right[j].second){
            points[index]=left[i];
            i++;
        }else{
            points[index]=right[j];
            j++;
        }
    }

}

int findMinArrowShots(vector<pair<int, int>>& points) {

    int len=points.size();
    if(len==0)
        return 0;
    MergeSort(points,0,len-1);

    int count=0;
    for(int i=0;i<len;){
        count++;
        int num=points[i].second;
        for(i++;i<len&&points[i].first<=num;i++);
    }
    return count;




}