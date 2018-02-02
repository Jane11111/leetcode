#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n);
void Next(vector<int>& pre,int num);
int main() {
    int n=5;
    int res=numTrees(n);
    cout<<res<<endl;
}

int numTrees(int n){
    vector<int> tree;
    for(int i=1;i<=n;i++)
        Next(tree,i);
    int res=0;
    for(int i=1;i<=n;i++)
        res+=tree[i];
    return res;
}

void Next(vector<int>& pre,int num){
    if(num==1){
        pre.push_back(0);
        pre.push_back(1);
        return ;
    }
    vector<int> old_pre;
    for(int i=0;i<pre.size();i++) {
        old_pre.push_back(pre[i]);
        pre[i]=0;
    }
    int len=old_pre.size();
    pre.push_back(0);
    for(int i=1;i<len;i++){//长度为i的有old_pre[i]个
        int count=old_pre[i];
        for(int j=1;j<=i+1;j++){
            pre[j]+=count;
        }

    }
}
