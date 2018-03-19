#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p);
bool RecMatch(string s,int s1,string p,int s2);
int main() {
    string s="";
    string p="";
    bool f=isMatch(s,p);
    if(f)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
bool RecMatch(string s,int s1,string p,int s2){

    if(s1==s.size()){
        if(s2==p.size())
            return true;
        while(s2<p.size()&&p[s2]=='*'||s2<p.size()-1&&p[s2+1]=='*')
            s2++;

        if(s2==p.size())
            return true;
        else
            return false;
    }

    if(s2==p.size())
        return false;

    if(s2<p.size()-1&&p[s2+1]=='*'){//后面有*

        char pre=p[s2];
        s2++;
        while(s2<p.size()&&p[s2]=='*')
            s2++;

        while(s1<s.size()&&(s[s1]==pre||pre=='.')){
            bool f=RecMatch(s,s1,p,s2);
            if(f)
                return f;
            s1++;
        }
        return RecMatch(s,s1,p,s2);

    }else{//后面无星
        if(p[s2]=='.'||s[s1]==p[s2])
            return RecMatch(s,s1+1,p,s2+1);
        else
             return false;

    }


}
bool isMatch(string s, string p) {

    return RecMatch(s,0,p,0);

}