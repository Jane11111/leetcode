#include <iostream>
#include <vector>
using namespace std;

int monotoneIncreasingDigits(int N);
int main() {
    int N=332;
    int res=monotoneIncreasingDigits(N);
    cout<<res<<endl;
}


int monotoneIncreasingDigits(int N) {

    vector<int> nums;

    while(N>0){
        nums.insert(nums.begin(),N%10);
        N/=10;
    }

    if(nums.empty())
        return 0;

    int len=nums.size();


    bool isDel=false;//是否降过位
    for(int i=1;i<len;i++){
        int min=nums[i-1];
        if(isDel){//已经降过位
            nums[i]=9;
        }else{
            if(nums[i]<min) {
                int j=i-1;
                while(nums[j]==0||(j>0&&nums[j]==nums[j-1])) {//开始降位
                    nums[j]=9;
                    j--;
                }
                nums[j]-=1;
                nums[i]=9;
                isDel=true;
            }

        }

    }
    int t=1;
    int res=0;
    for(int i=len-1;i>=0;i--){
        res+=(t*nums[i]);
        t*=10;
    }
    return res;
}