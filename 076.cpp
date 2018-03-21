#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string minWindow(string s, string t);
int main() {
    string s="ab";
    string t="a";
    string res=minWindow(s,t);
    cout<<res<<endl;
    return 0;
}

string minWindow(string s, string t) {

    string res;
    if(s.empty()||t.empty())
        return res;

    map<char,int> tmap;
    int tlen=t.size();
    int slen=s.size();
    for(int i=0;i<tlen;i++)
        tmap[t[i]]++;

    int left=0;
    int count=0;
    map<char,int> cmap;
    for(int i=0;i<slen;i++){
        char c=s[i];
        cmap[s[i]]++;
        if(tmap[s[i]]>=cmap[s[i]]&&tmap.find(s[i])!=tmap.end())
            count++;
        if(count==tlen){
            while(cmap[s[left]]>tmap[s[left]]){
                cmap[s[left]]--;
                left++;
            }
            //string r=s.substr(0,0+1-0);
            int start=left;
            int size=i+1-left;
            string r=s.substr(start,size);
            if(res.empty()||res.size()>r.size())
                res=r;
            cmap[s[left]]--;
            left++;
            count--;
        }

    }
    return res;

}