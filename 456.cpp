#include <iostream>
#include <vector>
using namespace std;
bool find132pattern(vector<int>& nums);
int main() {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-1);
    nums.push_back(2);
    bool res=find132pattern(nums);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

bool find132pattern(vector<int>& nums) {
    bool is_valid[2];
    int len=nums.size();
    for(int i=2;i<len;i++){
        int cur=nums[i];
        is_valid[0]=false;
        is_valid[1]=false;
        for(int j=0;j<i;j++){
            if(!is_valid[0]&&nums[j]<cur){
                is_valid[0]=true;
            }else{
                if(is_valid[0]&&nums[j]>cur)
                    is_valid[1]=true;
            }
            if(is_valid[0]&&is_valid[1])
                return true;
        }

    }
    return false;

}