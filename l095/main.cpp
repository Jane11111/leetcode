#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A);
int main() {

    return 0;
}

vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> res;
    for(int a: A){
        if(a%2==0)
            res.insert(res.begin(),a);
        else
            res.push_back(a);
    }
    return res;
}