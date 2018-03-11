#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
vector<string> summaryRanges(vector<int>& nums);
string IntToStr(int n);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
string IntToStr(int n){
    ostringstream os;
    os<<n;
    return os.str();
}
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    for(int i=0;i<nums.size();){
        int start=i;
        int end=i+1;
        while(nums[end]==nums[end-1]+1)
            end++;
        end--;
        string s=IntToStr(nums[start]);
        if(start!=end){
            s+=("->"+IntToStr(nums[end]));
        }
        res.push_back(s);
        i=end+1;

    }
    return res;
}