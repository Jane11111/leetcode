#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sum1=0;
    int sum2=0;
    for(int i=0;i<A.size();i++)
        sum1+=A[i];
    for(int i=0;i<B.size();i++)
        sum2+=B[i];

    int avg=(sum1+sum2)/2;
    int target=avg-sum1;

    map<int,bool> mB;
    for(int i : B)
        mB.insert(pair<int,bool>(i,true));

    vector<int> res;
    for(int i: A)
        if(mB.find(i+target)!=mB.end()){
            res.push_back(i);
            res.push_back(i+target);
            return res;
        }
    return res;
}