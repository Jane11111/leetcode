#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k){

    int len=nums.size();
    vector<int> sums(len,0),leftPos(len,0),rightPos(len,0);
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        sums[i]=sum;
    }
    int max=INT_MIN;
    for(int i=k-1;i<len;i++){//尾是i
        int n1=i==k-1?0:sums[i-k];
        if(sums[i]-n1>max){
            max=sums[i]-n1;
            leftPos[i]=i;
        }else
            leftPos[i]=leftPos[i-1];
    }

    max=INT_MIN;
    for(int i=len-k;i>=0;i--){//头是i
        int n1=i==0?0:sums[i-1];
        if(sums[i+k-1]-n1>=max){
            max=sums[i+k-1]-n1;
            rightPos[i]=i;
        }else
            rightPos[i]=rightPos[i+1];
    }

     max=INT_MIN;
    vector<int> res;
    for(int i=k;i<=len-k-k;i++){
        int n1=leftPos[i-1];
        int n2=rightPos[i+k];

        int t=n1==k-1?0:sums[n1-k];
        int s1=sums[n1]-t;
        int s2=sums[i+k-1]-sums[i-1];
        int s3=sums[n2+k-1]-sums[n2-1];
        if(s1+s2+s3>max){
            max=s1+s2+s3;
            res={n1-k+1,i,n2};
        }


    }
    return res;




}