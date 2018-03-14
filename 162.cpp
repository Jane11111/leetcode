#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums);
int main() {
    cout<<INT_MIN<<endl;
    double min=2*(double(INT_MIN));;
    if(INT_MIN>min)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}


int findPeakElement(vector<int>& nums) {
    int len=nums.size();

    double min=2*(double(INT_MIN));
    for(int i=0;i<len;i++){
        double left=i==0?min:nums[i-1];
        double right=i==len-1?min:nums[i+1];
        if(nums[i]>left&&nums[i]>right)
            return i;
    }
    return -1;

}