#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


int largestRectangleArea(vector<int>& heights) {
    //找到向左向右第一个比它矮的下标

    int len=heights.size();
    if(len==0)
        return 0;
    int left[len];
    int right[len];

    vector<int>tmp;
    //向右 第一个小于它的下标
    for(int i=0;i<len;i++){
        while(!tmp.empty()&&heights[i]<heights[tmp[0]]){
            right[tmp[0]]=i;
            tmp.erase(tmp.begin());
        }
        tmp.insert(tmp.begin(),i);
    }
    for(int i=0;i<tmp.size();i++)
        right[tmp[i]]=len;

    tmp.clear();
    //向左第一个小于它的下标
    for(int i=len-1;i>=0;i--){
        while(!tmp.empty()&&heights[i]<heights[tmp[0]]){
            left[tmp[0]]=i;
            tmp.erase(tmp.begin());
        }
        tmp.insert(tmp.begin(),i);

    }
    for(int i=0;i<tmp.size();i++){
        left[tmp[i]]=-1;
    }

    int res=0;
    for(int i=0;i<len;i++){
        int area=heights[i]*(right[i]-left[i]-1);
        res=res>area?res:area;
    }
    return res;

}
