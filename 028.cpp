#include <iostream>
using namespace std;

int strStr(string haystack, string needle);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int strStr(string haystack, string needle) {
    int len1=haystack.size();
    int len2=needle.size();
    if(len2==0)
        return 0;

    for(int i=0;i<=len1-len2;i++){
        if(haystack[i]==needle[0]){
            int j=0;
            for(;j<len2&&j+i<len1;j++){
                if(haystack[j+i]!=needle[j])
                    break;
            }
            if(j==len2)
                return i;
        }
    }
    return -1;
}