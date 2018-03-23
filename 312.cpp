#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxCoins(vector<int>& nums);
void Rec(int start,int end,int left,int right,double& sum,vector<int>& nums,map<vector<int>,double> & mymap);
int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(8);
    int res=maxCoins(nums);
    cout<<res<<endl;
    return 0;
}
void Rec(int start,int end,int left,int right,double& sum,vector<int>& nums,map<vector<int>,double>& mymap){
    if(mymap.find({start,end,left,right})!=mymap.end()){
        sum=mymap[{start,end,left,right}];
        return ;
    }
    if(start==end){
        sum=left*nums[start]*right;
        mymap[{start,end,left,right}]=sum;
        return ;
    }

    double res=INT_MIN;
    double n1;
    Rec(start+1,end,nums[start],right,n1,nums,mymap);
    double n2;
    Rec(start,end-1,left,nums[end],n2,nums,mymap);
    n1+=left*nums[start]*right;
    n2+=left*nums[end]*right;
    if(n1>n2){
        res=n1;
    }else {
        res=n2;
    }
    for(int i=start+1;i<=end-1;i++){

        Rec(start,i-1,left,nums[i],n1,nums,mymap);

        Rec(i+1,end,nums[i],right,n2,nums,mymap);

        double tmp=n1+n2+left*nums[i]*right;
        if(tmp>res){
            res=tmp;
        }
    }

    sum=res;
    mymap[{start,end,left,right}]=sum;
}
int maxCoins(vector<int>& nums) {

    if(nums.size()==1)
        return nums[0];
    else if(nums.empty())
        return 0;

    double res;
    map<vector<int>,double> mymap;
    Rec(0,nums.size()-1,1,1,res,nums,mymap);
    return res;


}