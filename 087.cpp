#include <iostream>
#include <vector>
#include<map>
using namespace std;


bool isScramble(string s1, string s2);
int main() {
    string s1="abc";
    string s2="acb";
    bool res=isScramble(s1,s2);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

bool isScramble(string s1, string s2) {


    int len1=s1.size();
    int len2=s2.size();
    if(len1!=len2)
        return false;
    if(s1==s2)
        return true;

    map<char,int> mymap;
    for(int i=0;i<len1;i++)
        mymap[s1[i]]++;
    for(int i=0;i<len1;i++){
        mymap[s2[i]]--;
        if(mymap[s2[i]]<0)
            return false;
    }

    for(int i=1;i<len1;i++){
        bool f=isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i));
        if(f)
            return true;
        f=isScramble(s1.substr(0,i),s2.substr(len1-i,i))&&isScramble(s1.substr(i),s2.substr(0,len1-i));
        if(f)
            return true;
    }
    return false;


}