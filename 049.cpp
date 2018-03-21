#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);
string normalize(string& s);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string normalize(string& s){
    string t=s;
    for(int i=0;i<t.size();i++){
        char c=t[i];
        for(int j=i-1;j>=0;j--){
            if(t[j]>c){
                char tmp=t[j];
                t[j]=t[j+1];
                t[j+1]=tmp;
            }
        }
    }
    return t;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {

    map<string ,int> mymap;
    vector<vector<string>> res;
    for(int i=0;i<strs.size();i++){
        string t=normalize(strs[i]);
        if(mymap.find(t)==mymap.end()){
            vector<string> v;
            res.push_back(v);
            mymap[t]=res.size()-1;
        }
        res[mymap[t]].push_back(strs[i]);
    }
    return res;
}