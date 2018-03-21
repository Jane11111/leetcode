#include <iostream>
#include <vector>
using namespace std;

int minDistance(string word1, string word2);
int main() {
    string word1="a";
    string word2="b";
    int res=minDistance(word1,word2);
    cout<<res<<endl;
    return 0;
}

int minDistance(string word1, string word2){
    int len1=word1.size();
    int len2=word2.size();

    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
    for(int i=1;i<=len1;i++)
        dp[i][0]=i;
    for(int i=1;i<=len2;i++)
        dp[0][i]=i;

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            int t=1;
            if(word1[i-1]==word2[j-1])
                t=0;
            int n1=t+dp[i-1][j-1];
            int n2=dp[i-1][j]+1;
            int n3=dp[i][j-1]+1;
            int res=min(n1,n2);
            res=min(res,n3);
            dp[i][j]=res;
        }
    }
    return dp[len1][len2];
}