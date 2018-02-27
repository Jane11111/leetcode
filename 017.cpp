#include <iostream>
#include<vector>
#include<map>
using namespace std;


vector<string> letterCombinations(string digits);
void genStr(string str,string digits,int start);
map<char,string> my_map;
vector<string> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void genStr(string str,string digits,int start){

    if(start==digits.size()){
        res.push_back(str);
        return;
    }
    char num=digits[start];
    string s=my_map[num];
    if(s.size()==0)
        genStr(str,digits,start+1);
    else {
        for (char c:s) {
            str.push_back(c);
            genStr(str, digits, start + 1);
            str.erase(str.size() - 1);
        }
    }
}
vector<string> letterCombinations(string digits) {
    my_map['0']="";
    my_map['1']="";
    my_map['2']="abc";
    my_map['3']="def";
    my_map['4']="ghi";
    my_map['5']="jkl";
    my_map['6']="mno";
    my_map['7']="pqrs";
    my_map['8']="tuv";
    my_map['9']="wxyz";
    if(digits.size()==0)
        return res;
    string str;
    genStr(str,digits,0);
    return res;
}