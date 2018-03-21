#include <iostream>
#include <vector>
using namespace std;

int numDistinct(string s, string t);
int count;
void Find(string s,int start,string subs,string &target);

int main() {
    string s="rabbbit";
    string t="rabbit";
    int res=numDistinct(s,t);
    cout<<res<<endl;
    return 0;
}
void Find(string s,int start,string subs,string &target){

    int r=0;

    if(subs.size()==target.size()) {
        count++;
        return  ;
    }
    int cur=subs.size();
    for(int i=start;i<s.size()-(target.size()-cur-1);i++){
        if(s[i]==target[cur]){
            subs.push_back(s[i]);
            Find(s,i+1,subs,target);

            subs.erase(subs.begin()+subs.size()-1);
        }
    }

}
int numDistinct(string s, string t) {
    count=0;
    if(t.empty())
        return count;
    string subs;
    vector<vector<int>>M(s.size()+1,vector<int>(t.size()+1,-1));
    Find(s,0,subs,t);
    return count;

}