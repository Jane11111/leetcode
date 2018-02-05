#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix);
int main() {
    vector<vector<int>> matrix;
    vector<int> row1(10,1);
    row1[6]=0;
    vector<int> row2(10,0);
    row2[0]=1;row2[1]=1;row2[7]=1;row2[8]=1;row2[9]=1;
    vector<int>row3(10,1);
    row3[0]=0;row3[2]=0;row3[7]=0;row3[8]=0;row3[0]=0;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    vector<vector<int>> res=updateMatrix(matrix);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

    if(matrix.empty()||matrix[0].empty())
        return matrix;
    int row=matrix.size();
    int col=matrix[0].size();
    vector<vector<int>> res;
    int is_visited[row][col];

   // vector<int> tmp;
   // res.push_back(tmp);
    for(int i=0;i<row;i++){
        vector<int> tmp;
        for(int j=0;j<col;j++){
            tmp.push_back(-1);
            is_visited[i][j]=-1;
        }
        res.push_back(tmp);
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0){
                res[i][j]=0;
                continue;
            }

            pair<int,int> s=pair<int,int>(i,j);
            pair<int,int> nearest;
            int flag=i*row+j;
            vector<pair<int,int>> Q;
            Q.push_back(s);
            is_visited[i][j]=flag;
            while(!Q.empty()){
                pair<int,int> u=Q[0];
                Q.erase(Q.begin());
                pair<int,int> n_d=pair<int,int>(u.first-1,u.second);
                pair<int,int> s_d=pair<int,int>(u.first+1,u.second);
                pair<int,int> w_d=pair<int,int>(u.first,u.second-1);
                pair<int,int> e_d=pair<int,int>(u.first,u.second+1);
                if(n_d.first>=0&&is_visited[n_d.first][n_d.second]!=flag){
                    if(matrix[n_d.first][n_d.second]==0){
                        res[i][j]=abs(n_d.first-s.first)+abs(n_d.second-s.second);
                        break;
                    }else{
                        Q.push_back(n_d);
                        is_visited[n_d.first][n_d.second]=flag;
                    }
                }
                if(s_d.first<row&&is_visited[s_d.first][s_d.second]!=flag){
                    if(matrix[s_d.first][s_d.second]==0){
                        res[i][j]=abs(s_d.first-s.first)+abs(s_d.second-s.second);
                        break;
                    }else{
                        Q.push_back(s_d);
                        is_visited[s_d.first][s_d.second]=flag;
                    }
                }
                if(w_d.second>=0&&is_visited[w_d.first][w_d.second]!=flag){
                    if(matrix[w_d.first][w_d.second]==0){
                        res[i][j]=abs(w_d.first-s.first)+abs(w_d.second-s.second);
                        break;
                    }else{
                        Q.push_back(w_d);
                        is_visited[w_d.first][w_d.second]=flag;
                    }
                }
                if(e_d.second<col&&is_visited[e_d.first][e_d.second]!=flag){
                    if(matrix[e_d.first][e_d.second]==0){
                        res[i][j]=abs(e_d.first-s.first)+abs(e_d.second-s.second);
                        break;
                    }else{
                        Q.push_back(e_d);
                        is_visited[e_d.first][e_d.second]=flag;
                    }
                }
            }

        }
    }
    return res;

}