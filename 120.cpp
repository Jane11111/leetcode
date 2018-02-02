#include <iostream>
#include <vector>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle);
int main() {
    vector<vector<int>> triangle;
    vector<int> row1;
    row1.push_back(2);
    vector<int> row2;
    row2.push_back(3);
    row2.push_back(4);
    vector<int> row3;
    row3.push_back(6);
    row3.push_back(5);
    row3.push_back(7);
    vector<int> row4;
    row4.push_back(4);
    row4.push_back(1);
    row4.push_back(8);
    row4.push_back(3);
    triangle.push_back(row1);
    triangle.push_back(row2);
    triangle.push_back(row3);
    triangle.push_back(row4);


    int res=minimumTotal(triangle);
    cout<<res<<endl;
}

int minimumTotal(vector<vector<int>>& triangle) {

    int len=triangle.size();
    if (len==0)
        return 0;
    int res[len][len];
    res[0][0]=triangle[0][0];
    for(int row=1;row<len;row++){
        for(int col=0;col<=row;col++){
            int t=triangle[row][col];
            int min=INT_MAX;
            if(col<=row-1&&col>=0)
                if(res[row-1][col]<min)
                    min=res[row-1][col];
            if(col-1<=row-1&&col-1>=0)
                if(res[row-1][col-1]<min)
                    min=res[row-1][col-1];
            res[row][col]=t+min;
        }
    }
    int min=res[len-1][0];
    for(int i=0;i<len;i++)
        if(res[len-1][i]<min)
            min=res[len-1][i];
    return min;


}