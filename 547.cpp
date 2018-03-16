#include <iostream>
#include <vector>
using namespace std;

int findCircleNum(vector<vector<int>>& M);
void DFS(int x,vector<vector<int>>& M);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void DFS(int x,vector<vector<int>>& M){
    M[x][x]=0;
    vector<int> friends=M[x];
    for(int i=0;i<friends.size();i++){
        if(friends[i]==1){
            M[x][i]=0;
            DFS(i,M);
            M[i][x]=0;
        }
    }
}
int findCircleNum(vector<vector<int>>& M) {

    int res=0;
    int n=M.size();
    for(int i=0;i<n;i++){
        if(M[i][i]==1){
            res++;
            DFS(i,M);
        }
    }
    return res;

}