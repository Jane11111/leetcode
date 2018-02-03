#include <iostream>
using namespace std;
bool checkRecord(string s);
int main() {
    string s="PPALLL";
    bool res=checkRecord(s);
    if(res)
        cout<<"is"<<endl;
    else
        cout<<"is not"<<endl;
    return 0;
}

bool checkRecord(string s) {
    bool contain_A=false;
    bool continue_L[2];
    continue_L[0]=false;
    continue_L[1]=false;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c=='A'){
            if(contain_A)
                return false;
            contain_A=true;
        }
        if(c=='L'){
            if(continue_L[1])
                return false;
            if(continue_L[0])
                continue_L[1]=true;
            else{
                continue_L[0]=true;
            }
        }else{
            continue_L[0]=false;
            continue_L[1]=false;
        }
    }
    return true;

}