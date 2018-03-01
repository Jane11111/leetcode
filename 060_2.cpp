#include <iostream>
using namespace std;

string getPermutation(int n, int k);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string getPermutation(int n, int k){
    string str(n,'0');
    int mul=1;
    for(int i=1;i<=n;i++) {
        str[i - 1] += i;
        mul*=i;
    }

    for(int i=0;i<n;i++){
        mul/=(n-i);//A(n,i+1)
        int x=k/mul;
        int y=k%mul;
        if(y==0){
            x--;
            y=mul;
        }

        char c=str[x+i];
        for(;x+i>i;x--){
            str[x+i]=str[x+i-1];
        }
        str[i]=c;


        k=y;
    }
    return str;

}