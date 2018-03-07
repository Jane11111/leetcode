#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


vector<int> exclusiveTime(int n, vector<string>& logs) {

    vector<int> res;
    for(int i=0;i<n;i++)
        res.push_back(0);

    vector<pair<int,int>> stack;
    for(int i=0;i<logs.size();i++){
        string str=logs[i];
        int t_id;
        int time;
        vector<string> ss;
        string s;
        for(int i=0;i<str.size();i++){
            if(str[i]==':'){
                ss.push_back(s);
                s="";

            }else{
                s.push_back(str[i]);
            }
        }
        ss.push_back(s);
        istringstream is(ss[0]);
        is>>t_id;
        istringstream is2(ss[2]);
        is2>>time;

        string event=ss[1];
        if(event=="start"){
            stack.insert(stack.begin(),pair<int,int>(t_id,time));
        }else{
            pair<int,int> p=stack[0];
            stack.erase(stack.begin());
            int t_id=p.first;
            int s_time=p.second;
            int dur=time-s_time+1;
            res[t_id]+=dur;
            if(!stack.empty()){
                res[stack[0].first]-=dur;
            }

        }
    }
    return res;


}