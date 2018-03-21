#include <iostream>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isInterleave(string s1, string s2, string s3){

    if(s3.size()!=s1.size()+s2.size())
        return false;

    int len1=s1.size();
    int len2=s2.size();
    bool dp[len1+1][len2+1];

    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0&&j==0)
                dp[i][j]=true;
            else if(i==0){
                dp[i][j]=dp[i][j-1]&&s2[j-1]==s3[j-1];
            }else if(j==0)
                dp[i][j]=dp[i-1][j]&&s1[i-1]==s3[i-1];
            else{
                dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
    }
    return dp[len1][len2];

}