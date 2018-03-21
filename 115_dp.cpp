#include <iostream>
#include <vector>
using namespace std;

int numDistinct(string s, string t);
int main() {
    string s="rabbbit";
    string t="rabbit";
    int res=numDistinct(s,t);
    cout<<res<<endl;
    return 0;
}

int numDistinct(string s, string t){
    int len1=s.size();
    int len2=t.size();

    int dp[len2+1][len1+1];
    for(int i=0;i<=len1;i++)
        dp[0][i]=1;
    for(int i=1;i<=len2;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<=len2;i++){
        for(int j=1;j<=len1;j++){
            if(t[i-1]==s[j-1]){
                dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
            }else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    return dp[len2][len1];
}