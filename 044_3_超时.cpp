#include <iostream>
#include <vector>
using namespace std;

bool RecMatch(string s,int s1,string p,int s2);
bool isMatch(string s, string p);
int main() {
    string s="abefcdgiescdfimde";
    string p="ab*cd?i*de";
    bool f=isMatch(s,p);
    if(f)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
bool RecMatch(string s,int s1,string p,int s2){
    if(s1==s.size()){
        while(s2<p.size()&&p[s2]=='*')
            s2++;
        if(s2==p.size())
            return true;
        else
            return false;
    }
    if(s2==p.size())
        return false;

    if(s[s1]==p[s2]||p[s2]=='?')
        return RecMatch(s,s1+1,p,s2+1);
    else if(p[s2]=='*'){
        while(s2<p.size()&&p[s2]=='*')
            s2++;
        for(;s1<s.size();s1++){
            if(s1<s.size()-1&&s2<p.size()&&p[s2]!='?'&&s[s1]!=p[s2])
                continue;
            bool f=RecMatch(s,s1,p,s2);
            if(f)
                return f;
        }
        return RecMatch(s,s1,p,s2);


    }else
        return false;

}
bool isMatch(string s, string p){

    return RecMatch(s,0,p,0);
}