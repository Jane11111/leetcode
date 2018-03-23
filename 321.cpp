#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);
vector<int> Merge(vector<int>&nums1,vector<int>& nums2);

vector<int> Extract(vector<int>&  nums,vector<int> & right,int k);
bool Cmp(vector<int> &  nums1,vector<int> & nums2);
int main() {
    vector<int> nums1({6,7});
    vector<int> nums2({6,0,4});
    vector<int> res=maxNumber(nums1,nums2,5);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;

    return 0;
}
vector<int> Merge(vector<int>&nums1,vector<int>& nums2){
    int m=nums1.size();
    int n=nums2.size();

    vector<int> nums;

    int i=0;
    int j=0;
    while(i<m||j<n){
        if(j==n){
            nums.push_back(nums1[i]);
            i++;
        }else if(i==m){
            nums.push_back(nums2[j]);
            j++;
        }else{
            if(nums1[i]>nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }else if(nums2[j]>nums1[i]){
                nums.push_back(nums2[j]);
                j++;
            }else{
                int t1=i;
                int t2=j;
                while(t1<m&&t2<n&&nums1[t1]==nums2[t2]){
                    t1++;
                    t2++;
                }

                if(t2==n||t1<m&&nums1[t1]>nums2[t2]){
                    nums.push_back(nums1[i]);
                    i++;
                    /*for(;i<t1;i++)
                        nums.push_back(nums1[i]);*/
                }else{
                    nums.push_back(nums2[j]);
                    j++;
                    /*for(;j<t2;j++)
                        nums.push_back(nums2[j]);*/
                }
            }

        }
    }
    vector<int> right(m+n,-1);
    stack<int> Q;
    for(int i=0;i<m+n;i++){
        while(!Q.empty()&&nums[i]>nums[Q.top()]){
            right[Q.top()]=i;
            Q.pop();
        }
        Q.push(i);
    }
    return nums;
}

vector<int> Extract(vector<int>&  nums,vector<int> & right,int k){
    if(nums.size()==k)
        return nums;
    if(k==0)
        return vector<int>(0,0);

    int count=nums.size()-k;
    vector<int> res;
    for(int i=0;i<nums.size();i++){
        if(right[i]==-1||right[i]-i>count){
            res.push_back(nums[i]);
        }else{
            count-=(right[i]-i);
            i=right[i]-1;
        }
    }
    while(res.size()>k)
        res.erase(res.begin()+res.size()-1);
    return res;
}

bool Cmp(vector<int> &  nums1,vector<int> & nums2){
    for(int i=0;i<nums1.size();i++){
        if(nums1[i]>nums2[i])
            return true;
        else if(nums1[i]<nums2[i])
            return false;
        else
             continue;
    }
    return true;
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){

    int m=nums1.size();
    int n=nums2.size();
    if(k>m+n)
        return vector<int> (0,0);

    vector<int> right1(m+n,-1);
    vector<int> right2(m+n,-1);

    stack<int> Q;
    for(int i=0;i<m;i++){
        while(!Q.empty()&&nums1[i]>nums1[Q.top()]){
            right1[Q.top()]=i;
            Q.pop();
        }
        Q.push(i);
    }

    while(!Q.empty())
        Q.pop();

    for(int i=0;i<n;i++) {
        while (!Q.empty() && nums2[i] > nums2[Q.top()]) {
            right2[Q.top()] = i;
            Q.pop();
        }
        Q.push(i);
    }

    vector<int> res(k,INT_MIN);

    for(int i=0;i<=k;i++){
        if(i>m||k-i>n)
            continue;
        vector<int> v1=Extract(nums1,right1,i);
        vector<int> v2=Extract(nums2,right2,k-i);
        vector<int> v=Merge(v1,v2);
        if(!Cmp(res,v))
            res=v;

    }

    return res;



}