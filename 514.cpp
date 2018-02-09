#include <iostream>
#include <vector>
using namespace std;
int findRotateSteps(string ring, string key);
int RecFind(string ring,int ring_start ,string key,int key_start,vector<vector<int>>& W);
int main() {
    string ring="godding";
    string key="gd";
    int res=findRotateSteps(ring,key);
    cout<<res<<endl;
}

int findRotateSteps(string ring, string key) {
    int ring_len=ring.size();
    int key_len=key.size();
    vector<vector<int>> W;
    for(int i=0;i<ring_len;i++) {
        vector<int> t;
        for (int j = 0; j < key_len; j++) {
            t.push_back(INT_MAX);
        }
        W.push_back(t);
    }
    int res=RecFind(ring,0,key,0,W);
    return W[0][0];
}

int RecFind(string ring,int ring_start ,string key,int key_start,vector<vector<int>>& W){
    int ring_len=ring.size();
    int key_len=key.size();
    if(key_start==key_len)
        return 0;
    if(W[ring_start][key_start]!=INT_MAX)
        return W[ring_start][key_start];
    int step1=0;
    char c=key[key_start];
    for(;step1<ring_len;step1++)
        if(ring[(ring_start+step1)%ring_len]==c)
            break;
    int step2=0;
    for(;step2<ring_len;step2++)
        if(ring[(ring_start-step2+ring_len)%ring_len]==c)
            break;
    int res1=RecFind(ring,(ring_start+step1)%ring_len,key,key_start+1,W);
    int res2=RecFind(ring,(ring_start-step2+ring_len)%ring_len,key,key_start+1,W);
    res1=res1+step1+1;
    res2=res2+step2+1;
    W[ring_start][key_start]=res1<res2?res1:res2;
    return W[ring_start][key_start];

}