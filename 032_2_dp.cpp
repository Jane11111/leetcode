#include <iostream>
#include <vector>
using namespace std;

int longestValidParentheses(string s);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int longestValidParentheses(string s){

    int res=0;
    int len=s.size();
    if(len==0)
        return res;

    vector<int> dp(len,-1);

    for(int i=0;i<len;i++){
        if(s[i]==')'){
            if(i==0)continue;
            if(s[i-1]=='('){
                int count=2;
                if(i-2>0&&dp[i-2]>0)
                    count+=dp[i-2];
                dp[i]=count;
            }else{
                if(dp[i-1]>0){
                    int t=dp[i-1];
                    if(i-t-1>=0&&s[i-t-1]=='(')
                        dp[i]=2+dp[i-1]+(i-t-2>0&&dp[i-t-2]>0?dp[i-t-2]:0);

                }
            }
        }
        res=max(dp[i],res);
    }
    return res;

}