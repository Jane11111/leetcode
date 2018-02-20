#include <iostream>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string reverseString(string s) {
    string str="";
    for(int i=0;i<s.size();i++)
        str.insert(str.begin(),s[i]);
    return str;

}