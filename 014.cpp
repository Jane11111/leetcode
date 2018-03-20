#include <iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string longestCommonPrefix(vector<string>& strs) {

    string res;
    int cur=0;
    int len=strs.size();
    if(len==0)
        return res;
    while(true){
        if(cur>=strs[0].size())
            return res;
        char c=strs[0][cur];
        for(int i=1;i<len;i++){
            if(strs[i].size()<=cur||strs[i][cur]!=c)
                return res;
        }
        cur++;
        res.push_back(c);
    }

}