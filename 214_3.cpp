#include <iostream>
#include <vector>
using namespace std;

string shortestPalindrome(string s);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
string shortestPalindrome(string s){

    if(s.size()<=1)
        return s;

    string t;
    for(int i=s.size()-1;i>=0;i--)
        t.push_back(s[i]);


    t=s+"#"+t;
    int len=t.size();
    int next[len+1];
    int k=-1;
    next[k]=-1;

    int j=0;
    while(j<len){
        if(k==-1||t[j]==t[k]){
            k++;
            j++;
            next[j]=k;
        }else{
            k=next[k];
        }
    }

    int p=next[len];
    string tmp;
    int index=s.size()-1;
    while(index>=p){
        tmp.push_back(s[index]);
        index--;
    }

    return tmp+s;




}
