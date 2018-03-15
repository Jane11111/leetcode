#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int openLock(vector<string>& deadends, string target);
char right(char c);
char left(char c);
int main() {
    vector<string> deadends;
    string target;
    deadends.push_back("0201");
    deadends.push_back("0101");
    deadends.push_back("0102");
    deadends.push_back("1212");
    deadends.push_back("2002");
    target="0202";
    int res=openLock(deadends,target);
    cout<<res<<endl;
}
char left(char c){
    int n=c-'0';
    char res=char((n+1)%10+'0');
    return res;
}
char right(char c){
    int n=c-'0';
    char res=char((n+9)%10+'0');
    return res;
}
int openLock(vector<string>& deadends, string target) {

    map<string,int> visited;
    for(int i=0;i<deadends.size();i++) {
        visited[deadends[i]]=-1;
    }


    if(visited.find("0000")!=visited.end()||visited.find(target)!=visited.end())
        return -1;


    queue<string> Q;
    Q.push("0000");
    visited["0000"]=0;

    while(!Q.empty()){
        string cur=Q.front();
        Q.pop();
        int step=visited[cur];
        if(cur==target)
            return step;

        for(int i=0;i<cur.size();i++){
            //处理left
            string next=cur;
            next[i]=left(cur[i]);
            if(visited.find(next)==visited.end()){//可以通过且没有visited过
                Q.push(next);
                visited[next]=step+1;

            }
            //处理right
            next=cur;
            next[i]=right(cur[i]);
            if(visited.find(next)==visited.end()){//可以通过且没有visited过
                Q.push(next);
                visited[next]=step+1;

            }
        }



    }


    return -1;


}