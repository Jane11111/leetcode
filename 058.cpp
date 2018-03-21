#include <iostream>
#include <vector>
using namespace std;

int lengthOfLastWord(string s);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int lengthOfLastWord(string s) {
    int count=0;
    int i=s.size()-1;
    while(i>=0&&s[i]==' ')
        i--;
    for(;i>=0;i--){
        if(s[i]==' ')
            return count;
        count++;
    }
    return count;

}