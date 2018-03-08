#include <iostream>
#include <vector>
using namespace std;

string addBinary(string a, string b);
int main() {
    string a="0";
    string b="0";
    string res=addBinary(a,b);
    cout<<res<<endl;
    return 0;
}


string addBinary(string a, string b) {

    int len=max(a.size(),b.size());
    if(len==0)
        return "0";
    while(a.size()<len)
        a.insert(a.begin(),'0');
    while(b.size()<len)
        b.insert(b.begin(),'0');

    int flag=0;
    for(int i=len-1;i>=0;i--){

        int n1=a[i]-'0';
        int n2=b[i]-'0';
        int s=n1+n2+flag;
        if(s%2)
            a[i]='1';
        else
            a[i]='0';
        flag=s/2;
    }
    if(flag==1)
        a.insert(a.begin(),'1');
    return a;
}