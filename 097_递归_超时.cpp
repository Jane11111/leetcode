#include <iostream>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3);
bool Rec(string str1,int s1,string str2,int s2,string str3,int s3);
int main() {
    string s1="ab";
    string s2="bc";
    string s3="bbac";
    bool res=isInterleave(s1,s2,s3);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

bool Rec(string str1,int s1,string str2,int s2,string str3,int s3){
    if(s1==str1.size()&&s2==str2.size()&&s3==str3.size())
        return true;

    if(str1.size()+str2.size()!=str3.size())
        return false;



    bool f1=false;
    bool f2=false;

    if(s1!=str1.size()&&str1[s1]==str3[s3]){
        f1=Rec(str1,s1+1,str2,s2,str3,s3+1);
    }
    if(s2!=str2.size()&&str2[s2]==str3[s3]){
        f2=Rec(str1,s1,str2,s2+1,str3,s3+1);
    }

    return f1||f2;


}
bool isInterleave(string s1, string s2, string s3) {

    return Rec(s1,0,s2,0,s3,0);
}