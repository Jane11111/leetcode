#include <iostream>
#include<vector>
#include <map>
using namespace std;
int findShortestSubArray(vector<int>& nums);

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    int res=findShortestSubArray(nums);
    cout<<res<<endl;
}


int findShortestSubArray(vector<int>& nums) {
    map<int,int> mymap;
    int len=nums.size();
    for(int i=0;i<len;i++){
        int num=nums[i];
        if(mymap.count(num)==0){
            nums[i]=-1;
        }else
            nums[i]=mymap[num];
        mymap[num]=i;//纪录上一跳信息
    }

    int res=0;
    int max_count=0;
    for(int i=len-1;i>=0;i--){
        int pre=i;
        int num=nums[i];
        int count=1;
        while(num!=-1){
            pre=num;
            num=nums[num];
            nums[pre]=-1;//销毁
            count++;

        }
        int step=i-pre+1;
        if(count>max_count||count==max_count&&step<res){
            max_count=count;
            res=step;
        }

    }
    return res;

}