#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);
int main() {
    vector<vector<int>> matrix;
    vector<int> row1;
    vector<int> row2;
    row1.push_back(2);
    row1.push_back(5);
    row1.push_back(8);
    row2.push_back(4);
    row2.push_back(0);
    row2.push_back(-1);
    matrix.push_back(row1);
    matrix.push_back(row2);
    vector<int> res=spiralOrder(matrix);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {

    vector<int> res;
    int m=matrix.size();
    if(m==0)
        return res;
    int n=matrix[0].size();
    if(n==0)
        return res;

    int start=0;
    int left=0;
    int right=n-1;
    int end=m-1;
    while(start<=end&&left<=right){

        int l=start;
        int r=n-start;
        int b=m-start;

        int t=l;

        //向右
        while(t<r){
            res.push_back(matrix[start][t]);
            t++;
        }
        //向下
        t=l+1;
        while(t<b-1){
            res.push_back(matrix[t][r-1]);
            t++;
        }
        //向左

        t=r-1;
        while(t>=l&&b-1>start){
            res.push_back(matrix[b-1][t]);
            t--;
        }
        //向上
        t=b-2;
        while(t>l&&l<r-1){
            res.push_back(matrix[t][l]);
            t--;
        }

        start++;
        end--;
        left++;
        right--;
    }
    return res;

}