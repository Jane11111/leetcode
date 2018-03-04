#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int res=0;
    int count=0;
    for(int x:nums){
    if(x==0){
        res=res>count?res:count;
        count=0;
    }else{
        count++;
    }
    }
    res=res>count?res:count;
    return res;

}