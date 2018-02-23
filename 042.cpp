#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height);
int main() {
    vector<int> height;
    height.push_back(4);
    height.push_back(2);
    height.push_back(3);
    int res=trap(height);
    cout<<res<<endl;
}

int trap(vector<int>& height) {
    int len=height.size();
    if(len==0)
        return 0;

    int nextHigher[len];//纪录下一个比他大的下标
    for(int i=0;i<len;i++){
        nextHigher[i]=-1;//初始化
    }
    vector<int> Q;
    for(int i=0;i<len;i++){
        while(!Q.empty()&&height[i]>=height[Q[0]]){
            nextHigher[Q[0]]=i;
            Q.erase(Q.begin());
        }
        Q.insert(Q.begin(),i);
    }

    int res=0;
    for(int i=0;i<len;){
        int h=height[i];
        int max_index=nextHigher[i];
        if(max_index==-1){

            max_index=i+1;//让那个当前最高的和一个较低的围成一个长方形
            while(max_index<len&&nextHigher[max_index]!=-1&&height[max_index]<h)
                max_index=nextHigher[max_index];
            h=height[max_index];
        }
        for(i++;i<max_index;i++)
            res+=(h-height[i]);
    }

    return res;
}