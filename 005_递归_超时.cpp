#include <iostream>
using namespace std;


string longestPalindrome(string s);
void RecFind(string s,int s1,int s2,int& res,int& start,int & end);

int main() {
    string s="babad";
    string res=longestPalindrome(s);
    cout<<res<<endl;
    return 0;
}
void RecFind(string s,int s1,int s2,int& res,int& start,int &end){
    if(s1==s2){
        res+=1;
        return;
    }
    if(s1>s2)
        return ;

    int n1=0;
    int n2=0;
    int n3=0;
    int t1,t2,t3,t4;
    if(s[s1]==s[s2]){
        n1+=res;
        n1+=2;
        RecFind(s,s1+1,s2-1,n1,start,end);
    }
    t1=s1+1,t2=s2;
    t3=s1,t4=s2-1;
    RecFind(s,s1+1,s2,n2,t1,t2);
    RecFind(s,s1,s2-1,n3,t3,t4);

    res=max(n1,n2);
    res=max(res,n3);
    if(n1>=n2&&n1>=n3);
    else if(n2>=n1&&n2>=n3){
        start=t1;
        end=t2;
    }else{
        start=t3;
        end=t4;
    }

}
string longestPalindrome(string s) {


    if(s.size()<=1)
        return s;
    int res=0;
    int start=0;
    int end=s.size()-1;
    RecFind(s,0,s.size()-1,res,start,end);

    return s.substr(start,end-start+1);
}