#include <iostream>
#include <vector>
using namespace std;

string shortestPalindrome(string s);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string shortestPalindrome(string s) {

    if(s.size()<=1)
        return s;

    string pre;
    int last=s.size()-1;
    while(last>=0){
        if(s[0]==s[last]){
            int lo=1;
            int hi=last-1;
            while(lo<hi&&s[lo]==s[hi]){
                lo++;
                hi--;
            }
            if(lo>=hi)
                break;

        }

        pre.push_back(s[last]);
        last--;
    }
    return pre+s;
}