#include <iostream>
#include <vector>
using namespace std;


vector<vector<string>> partition(string s);
void isOk(vector<string> subSet,int start,string str);
bool isPal(string str);
vector<vector<string>> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool isPal(string str){
    int s=0;
    int e=str.size()-1;
    while(s<e){
        if(str[s]!=str[e])
            return false;
        s++;
        e--;
    }
    return true;
}
void isOk(vector<string> subSet,int start,string str){
    if(start==str.size()){
        res.push_back(subSet);
        return;
    }
    string tmp;
    for(int i=start;i<str.size();i++){
        tmp.push_back(str[i]);
        if(isPal(tmp)){
            subSet.push_back(tmp);
            isOk(subSet,i+1,str);
            subSet.erase(subSet.begin()+subSet.size()-1);
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<string> subSet;
    isOk(subSet,0,s);
    return res;

}