#include <iostream>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target);
int CharToInt(char c);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

char nextGreatestLetter(vector<char>& letters, char target) {
    int num=CharToInt(target);
    int max=INT_MAX;
    char res=target;
    int len=letters.size();
    for(int i=0;i<len;i++){
        char c=letters[i];
        int n=CharToInt(c);
        if(n<=num)
            n+=26;
        if(n<max){
            max=n;
            res=c;
        }
    }
    return res;

}

int CharToInt(char c){
    switch (c){
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        case 'i':
            return 8;
        case 'j':
            return 9;
        case 'k':
            return 10;
        case 'l':
            return 11;
        case 'm':
            return 12;
        case 'n':
            return 13;
        case 'o':
            return 14;
        case 'p':
            return 15;
        case 'q':
            return 16;
        case 'r':
            return 17;
        case 's':
            return 18;
        case 't':
            return 19;
        case 'u':
            return 20;
        case 'v':
            return 21;
        case 'w':
            return 22;
        case 'x':
            return 23;
        case 'y':
            return 24;
        case 'z':
            return 25;
        default:
            return 26;
    }
}