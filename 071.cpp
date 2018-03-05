#include <iostream>
#include<vector>
using namespace std;

string simplifyPath(string path);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


string simplifyPath(string path) {

    vector<string> strs;
    int len=path.size();
    for(int i=0;i<len;i++){
        if(path[i]=='/')
            continue;
        string s;
        s.push_back(path[i]);
        i++;
        while(i<len&&path[i]!='/'){
            s+=path[i];
            i++;
        }
        if(s==".."){
            if(!strs.empty())
                strs.erase(strs.begin());


        }else if(s==".");
        else{
            strs.insert(strs.begin(),s);
        }


    }
    string res="/";
    for(int i=strs.size()-1;i>=0;i--){
        res+=strs[i];
        res+="/";
    }
    if(res.size()>1)
        res=res.substr(0,res.size()-1);
    return res;

}
