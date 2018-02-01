#include <iostream>
#include <vector>
using namespace std;
bool wordBreak(string s, vector<string>& wordDict) ;

int main() {
    string s="leetcode";
    vector<string> wordDict;
    wordDict.emplace_back("leet");
    wordDict.emplace_back("code");

    wordDict.emplace_back("aaa");
    wordDict.emplace_back("aaaa");
    wordDict.emplace_back("aaaaa");
    wordDict.emplace_back("aaaaaa");
    bool res=wordBreak(s,wordDict);
    if(res)
        cout<<"can "<<endl;
    else
        cout<<"can not "<<endl;
    return 0;
}

bool wordBreak(string s, vector<string>& wordDict) {

   vector<bool> can_be_divided;
    for(int i=0;i<=s.size();i++)
        can_be_divided.push_back(false);
    can_be_divided[0]=true;
    for(int i=1;i<=s.size();i++){
        for(int j=i-1;j>=0;j--){
            if(can_be_divided[j]){
                string sub_str=s.substr(j,i-j);
                for(int k=0;k<wordDict.size();k++){
                    if(wordDict[k]==sub_str)
                        can_be_divided[i]=true;
                }
            }
        }
    }
    return can_be_divided[s.size()];

}