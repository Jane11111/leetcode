#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words);
int main() {
    string s="barfoofoobarthefoobarman";
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
    words.push_back("the");
    vector<int> res=findSubstring(s,words);
    cout<<res.size()<<endl;
}

vector<int> findSubstring(string s, vector<string>& words){

    vector<int> res;
    if(s.empty()||words.empty()||words[0].empty())
        return res;

    map<string,int> wmap;
    for(int i=0;i<words.size();i++)
        wmap[words[i]]++;

    int n=words[0].size();
    for(int i=0;i<n;i++){
        int left=i;
        int count=0;
        map<string,int> cmap;
        for(int j=i;j<s.size()-(n-1);j+=n){

            string str=s.substr(j,n);
            if(wmap.find(str)!=wmap.end()){
                cmap[str]++;
                count++;

                while(cmap[str]>wmap[str]){
                    string tmp=s.substr(left,n);
                    count--;
                    cmap[tmp]--;
                    left+=n;
                }


                if(count==words.size()){

                    res.push_back(left);
                    string tmp=s.substr(left,n);
                    cmap[tmp]--;
                    count--;
                    left+=n;
                }

            }else{
                left=j+n;
                cmap.clear();
                count=0;

            }


        }
    }
    return res;

}