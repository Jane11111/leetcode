#include <iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


vector<int> productExceptSelf(vector<int>& nums) {
    double product=1;
    int zeros=0;
    for(int x:nums) {
        if(x==0){
            zeros++;
            continue;
        }
        product *= x;
    }

    vector<int> res;
    for(int x:nums) {
        int num;
        if(zeros>1){
            num=0;
        }else if(zeros==1){
            if(x==0)
                num=product;
            else
                num=0;
        }else{
            num=product/x;
        }
        res.push_back(num);
    }
    return res;
}