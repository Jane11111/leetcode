#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findDuplicate(vector<int>& nums) {

    int len=nums.size();
    int n=len-1;
    bool arr[len];
    for(int i=0;i<len;i++)
        arr[i]=false;
    for(int i=0;i<len;i++){
        int num=nums[i];
        if(!arr[num])
            arr[num]=true;
        else
            return num;
    }
    return 0;

}