#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M);

int main() {

    vector<vector<int>> M;
    M.push_back(vector<int>());
    M.push_back(vector<int>());
    M.push_back(vector<int>());
    M[0]={1,1,1};
    M[1]={1,0,1};
    M[2]={1,1,1,};
    vector<vector<int>>res=imageSmoother(M);
    return 0;
}

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {

    vector<vector<int>> res;
    int m=M.size();
    if(m==0)
        return res;
    int n=M[0].size();

    for(int i=0;i<m;i++) {
        res.push_back(vector<int>());
        for (int j = 0; j < n; j++)
            res[i].push_back(0);
    }
    vector<int> arr1={-1,0,1};
    vector<int> arr2={-1,0,1};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            int count=0;
            for(int i1 : arr1){
                for(int j1:arr2){
                    int x=i1+i;
                    int y=j1+j;
                    if(x>=0&&x<m&&y>=0&&y<n){
                        sum+=M[x][y];
                        count+=1;
                    }
                }
            }
            res[i][j]=int(sum/count);
        }
    }
    return res;
}