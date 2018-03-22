#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>
using namespace std;

string largestNumber(vector<int>& nums);
string IntToSTr(int num);
string StrangeSort(vector<string>& nums);
int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    string res=largestNumber(nums);
    cout<<res<<endl;
    return 0;
}
string IntToSTr(int num){
    ostringstream os;
    os<<num;
    return os.str();
}
string StrangeSort(vector<string>& nums){
    string res;
    if(nums.empty())
        return res;



    for(int i=0;i<nums.size();i++){
        string num=nums[i];
        for(int j=i;j>=0;j--){
            if(num+nums[j]>nums[j]+num)
                swap(nums[j],nums[j+1]);

        }
    }
    for(int i=0;i<nums.size();i++)
        res+=nums[i];
    return res;
}
string largestNumber(vector<int>& nums) {
    map<char,vector<string>> mymap;

    for(int i=0;i<nums.size();i++){
        string s=IntToSTr(nums[i]);
        if(s.empty())
            continue;
        mymap[s[0]].push_back(s);
    }

    string res;
    for(int i=9;i>=0;i--){
        char c=i+'0';
        if(mymap.find(c)!=mymap.end())
            res+=StrangeSort(mymap[c]);
    }
    while(!res.empty()&&res[0]=='0')
        res.erase(res.begin());
    if(res.empty())
        res="0";
    return res;

}