#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinationSum3(int k, int n);
void genCom(vector<int>& r,bool used[],int last,int left,int count);
vector<vector<int>> res;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

//last 上一个数，left 还剩余多少才到n，count 还可以再填几个数
void genCom(vector<int>& r,bool used[],int last,int left,int count){
    if(count==0&&left==0) {
        res.push_back(r);
    }
    if(count){
        int min=left<9?left:9;
        for(int i=last+1;i<=min;i++){
            if(!used[i]){
                used[i]=true;
                r.insert(r.begin(),i);
                genCom(r,used,i,left-i,count-1);
                used[i]=false;
                r.erase(r.begin());
            }
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> r;
    bool used[10];
    for(int i=0;i<=9;i++)
        used[i]=false;
    genCom(r,used,0,n,k);
    return res;
}