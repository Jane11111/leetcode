#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> combine(int n, int k);
void genSet(vector<int> set,int start,int k,int n);
vector<vector<int>> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void genSet(vector<int> set,int start,int k,int n){

    if(k==0){
        res.push_back(set);
        return;
    }
    for(int i=start+1;i<=n;i++){
        set.insert(set.begin(),i);
        genSet(set,i,k-1,n);
        set.erase(set.begin());
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<int> set;
    genSet(set,0,k,n);
    return res;
}