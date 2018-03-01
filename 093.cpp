#include <iostream>
#include<vector>
#include <sstream>
using namespace std;

vector<string> restoreIpAddresses(string s);
void isOk(string str,vector<int>&  nums,int start,int left);
string IntToStr(int num);
vector<string> res;

int main() {
    char c='3';
    int num=c-'0';
    cout<<num<<endl;
}
string IntToStr(int num){
    ostringstream stream;
    stream<<num;
    return stream.str();
}
void isOk(string str,vector<int>&  nums,int start,int left){

    if(start==-1&&left==0)
        res.push_back(str);
    else if(start==-1||left==0)
        return ;

    int base=1;
    int sum=0;
    for(int i=start;i>=0;i--){
        sum+=base*nums[i];

        if(sum>=0&&sum<=255){
            if(base!=1&&nums[i]==0) {
                base*=10;
                continue;
            }
            string s=IntToStr(sum);
            if(left!=4)
                s+='.';
            isOk(s+str,nums,i-1,left-1);
        }else{
            break;
        }
        base*=10;

    }

}
vector<string> restoreIpAddresses(string s) {
    vector<int> nums;
    int len=s.size();
    for(int i=0;i<len;i++){
        nums.push_back(s[i]-'0');
    }
    string str;
    isOk(str,nums,len-1,4);
    return res;

}