#include <iostream>
#include <vector>
using namespace std;

bool isOneBitCharacter(vector<int>& bits);
int main() {
    vector<int> bits;
    bits.push_back(1);
    bits.push_back(1);
    bits.push_back(1);
    bits.push_back(0);
    bool res=isOneBitCharacter(bits);
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}

bool isOneBitCharacter(vector<int>& bits) {

    if(bits.empty())
        return false;
    int len=bits.size();
    int i=0;
    for(;i<len-1;){
        if(bits[i]==0)
            i++;
        else{
            i+=2;
        }
    }
    if(i==len||bits[i]==1)
        return false;
    return true;
}