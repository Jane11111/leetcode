#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


bool isAnagram(string s, string t) {
    if(s.size()!=t.size())
        return false;

    map<char,int> mymap;
    for(int i=0;i<s.size();i++){
        mymap[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        mymap[t[i]]--;
        if(mymap[t[i]]<0)
            return false;
    }
    return true;

}