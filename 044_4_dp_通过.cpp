#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p);
int main() {
    string s="a";
    string p="*";
    bool res=isMatch(s,p);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

bool isMatch(string s, string p){
    if(s.size()==0){
        int s2=0;
        while(p[s2]=='*')
            s2++;
        if(s2==p.size())
            return true;
        else
            return false;
    }
    if(p.size()==0)
        return false;

    int m=s.size();
    int n=p.size();
    bool dp[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=false;
    bool used=false;
    for(int i=0;i<n;i++){
        bool f=false;
        if(p[i]=='*'){
            if(i==0)
                f=true;
            else{
                f=dp[0][i-1];
            }
        }else{
            if(!used) {
                f = s[0] == p[i] || p[i] == '?';
                used = true;
            }
        }
        dp[0][i]=f;
    }
    for(int i=1;i<m;i++){
        dp[i][0]=p[0]=='*';
    }


    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            bool f;
            if(p[j]=='*'){
                f=false;
                int t=i;
                while(t>=0) {
                    f = f || dp[t][j - 1];
                    t--;
                }
            }else{
                f=dp[i-1][j-1]&&(s[i]==p[j]||p[j]=='?');
            }

            dp[i][j]=f;
        }
    }

    return dp[m-1][n-1];

}