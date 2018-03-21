#include <iostream>
#include <vector>
using namespace std;
string multiply(string num1, string num2);
string add(string s1,string s2,int num);
string mul(char n,string s);
int main() {
    string s1="110";
    string s2="120";
    string res=multiply(s1,s2);
    cout<<res<<endl;
}
string mul(char n,string s){
    int n1=n-'0';
    int carry=0;
    string res;
    int i=s.size()-1;
    while(i>=0){
        int n2=s[i]-'0';
        int r=n1*n2+carry;
        carry=r/10;
        char c='0'+r%10;
        res.insert(res.begin(),c);
        i--;
    }
    if(carry)
        res.insert(res.begin(),'0'+carry);
    if(res.empty())
        res="0";
    return res;
}
string add(string s1,string s2,int num){
    while(num){
        s2.push_back('0');
        num--;
    }

    string res;
    int i=s1.size()-1;
    int j=s2.size()-1;
    int carry=0;
    while(i>=0||j>=0){
        int n1=0;
        int n2=0;
        if(i>=0){
            n1=s1[i]-'0';
            i--;
        }
        if(j>=0){
            n2=s2[j]-'0';
            j--;
        }
        int r=n1+n2+carry;
        carry=r/10;
        res.insert(res.begin(),'0'+(r%10));
    }
    if(carry)
        res.insert(res.begin(),'0'+carry);
    if(res.empty())
        res="0";
    return res;

}
string multiply(string num1, string num2){

    int i=num1.size()-1;
    int base=0;
    string cur;
    while(i>=0){
        char n1=num1[i];
        string s2=mul(n1,num2);
        cur=add(cur,s2,base);
        base++;
        i--;
    }
    while(!cur.empty()&&cur[0]=='0')
        cur.erase(cur.begin());
    if(cur.empty())
        cur="0";
    return cur;

}


