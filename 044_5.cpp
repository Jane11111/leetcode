#include <iostream>
#include <vector>
using namespace std;


bool isMatch(string s, string p);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isMatch(string s, string p){

    int s1=0;
    int s2=0;
    int match=0;
    int startIdx=-1;

    while(s1<s.size()){

        if(s2<p.size()&&(s[s1]==p[s2]||p[s2]=='?')){
            s1++;
            s2++;
        }else if(s2<p.size()&&p[s2]=='*'){

            startIdx=s2;
            match=s1;
            s2++;

        }else if(startIdx!=-1){
            s2=startIdx+1;
            match++;
            s1=match;

        }else
            return false;

    }
    while(s2<p.size()&&p[s2]=='*')
        s2++;
    return s2==p.size();

}