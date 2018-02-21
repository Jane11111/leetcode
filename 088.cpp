#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
int main() {
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(0);
    nums2.push_back(1);
    int m=0;
    int n=1;
    merge(nums1,m,nums2,n);
    for(int i=0;i<m+n;i++){
        cout<<nums1[i]<<endl;
    }
    return 0;
}


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0;
    int j=0;
    nums1.insert(nums1.begin()+m,INT_MAX);
    nums2.insert(nums2.begin()+n,INT_MAX);

    int t=m;
    while(i<m||j<n){
        if(nums1[i]>nums2[j]){
            nums1.insert(nums1.begin()+i,nums2[j]);
            i++;
            m++;
            j++;
        }else{
            i++;
        }
    }
    int len=nums1.size();
    while(t+n<len) {
        nums1.erase(nums1.begin() + (t + n));
        len--;
    }
}