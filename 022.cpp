#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generateParenthesis(int n);
void genStr(vector<string>& remind,string str,int left);
vector<string> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void genStr(vector<string>& remind,string str,int left){
    if(left==0&&remind.empty()){
        res.push_back(str);
        return ;
    }

    if(left) {
        remind.insert(remind.begin(), "(");//只能插入“（”
        string new_str = str + "(";
        genStr(remind, new_str, left - 1);
        remind.erase(remind.begin());//“还原"
    }
    if(!remind.empty()){
        remind.erase(remind.begin());//只能插入“）”
        string new_str=str+")";
        genStr(remind,new_str,left);
        remind.insert(remind.begin(),"(");//”还原“
    }
}
vector<string> generateParenthesis(int n) {
    string str;
    vector<string> remind;
    genStr(remind,str,n);
    return res;
}