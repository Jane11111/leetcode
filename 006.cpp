#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string convert(string s, int numRows) {

    if(numRows<=1)
        return s;
    string r[numRows];
    int i=0;
    while(i<s.size()){
        for(int row=0;i<s.size()&&row<numRows;row++){
            r[row].push_back(s[i]);
            i++;
        }
        for(int row=numRows-2;row>=1&&i<s.size();row--){
            r[row].push_back(s[i]);
            i++;
        }
    }
    string res;
    for(int i=0;i<numRows;i++)
        res=res+r[i];
    return res;
}