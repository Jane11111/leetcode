#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

int StrToInt(string str){
    int n;
    istringstream is(str);
    is>>n;
    return n;
}
bool isOpe(string str){
    return str=="+"||str=="-"||str=="*"||str=="/";
}

int evalRPN(vector<string>& tokens) {

    vector<int> nums;
    for(int i=0;i<tokens.size();i++){
        string str=tokens[i];
        if(isOpe(str)){
            int n1=nums[0];
            int n2=nums[1];
            nums.erase(nums.begin());
            nums.erase(nums.begin());
            int res;
            if(str=="+")
                res=n2+n1;
            else if(str=="-")
                res=n2-n1;
            else if(str=="*")
                res=n2*n1;
            else
                res=n2/n1;
            nums.insert(nums.begin(),res);

        }else{
            int n=StrToInt(str);
            nums.insert(nums.begin(),n);
        }
    }
    return nums[0];


}
