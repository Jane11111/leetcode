#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void setZeroes(vector<vector<int>>& matrix) {

    int m=matrix.size();
    if(m==0)
        return ;
    int n=matrix[0].size();

    vector<bool> row_zero;
    vector<bool> col_zero;

    for(int i=0;i<m;i++)
        row_zero.push_back(false);
    for(int i=0;i<n;i++)
        col_zero.push_back(false);

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(matrix[i][j]==0){
                row_zero[i]=true;
                col_zero[j]=true;
            }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(row_zero[i]||col_zero[j])
                matrix[i][j]=0;
}