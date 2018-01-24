#include <iostream>
#include<vector>
using namespace std;
bool isPalindrome(int x);

int main() {
    int num=1211;
    bool res=isPalindrome(num);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}
bool isPalindrome(int x) {
    vector<int> num;
    if (x==0)
        return true;
    if(x<0)
        return false;

    while(x!=0){
        num.push_back(x%10);
        x=x/10;
    }

    int l=0;
    int r=num.size()-1;
    while(l<r){
        if(num[l]!=num[r])
            return false;
        l++;
        r--;
    }
    return true;

}