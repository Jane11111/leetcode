#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main() {
    vector<vector<int>> matrix;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(4);
    row1.push_back(7);
    row1.push_back(11);
    row1.push_back(15);
    vector<int> row2;
    row2.push_back(2);
    row2.push_back(5);
    row2.push_back(8);
    row2.push_back(12);
    row2.push_back(19);
    vector<int> row3;
    row3.push_back(3);
    row3.push_back(6);
    row3.push_back(9);
    row3.push_back(16);
    row3.push_back(22);
    vector<int> row4;
    row4.push_back(10);
    row4.push_back(13);
    row4.push_back(14);
    row4.push_back(17);
    row4.push_back(24);
    vector<int> row5;
    row5.push_back(18);
    row5.push_back(21);
    row5.push_back(23);
    row5.push_back(26);
    row5.push_back(30);
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    matrix.push_back(row5);
    int target=20;
    bool res=searchMatrix(matrix,target);
    if(res)
        cout<<"is"<<endl;
    else
        cout<<"is not"<<endl;
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    if(matrix.size()==0||matrix[0].size()==0)
        return false;
    int row=matrix.size();
    int col=matrix[0].size();
    int i=1;
    for(;i<row;i++)
        if(matrix[i][0]>target)
            break;
    i--;//>i的行不再考虑。
    int j=1;
    for(;j<col;j++)
        if(matrix[0][j]>target)
            break;
    j--;//>j的列不再考虑。
    int j_l=0;
    for(;j_l<j;j_l++)
        if(matrix[i][j_l]>=target)
            break;
    //<j_l的列不再考虑。
    int i_l=0;
    for(;i_l<i;i_l++)
        if(matrix[i_l][j]>=target)
            break;
    //<i_l的列不再考虑。
    for(int r=i_l;r<=i;r++)
        for(int c=j_l;c<=j;c++ )
            if(matrix[r][c]==target)
                return true;
    return false;
}