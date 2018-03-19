#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
string longestPalindrome(string s){
    if(s.size()<=1)
        return s;

    int len=s.size();
    bool f[len][len];
    for(int i=0;i<len;i++)
        f[i][i]=true;

    int start=0;
    int end=0;
    for(int step=1;step<len;step++){
        for(int i=0;i+step<len;i++){
            int x=i;
            int y=x+step;
            f[x][y]=(s[x]==s[y]&&(x+1>=y-1||f[x+1][y-1]));
            if(f[x][y]){
                start=x;
                end=y;
            }
        }
    }
    return s.substr(start,end-start+1);
}