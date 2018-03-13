#include <iostream>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix);
int calMax(vector<int> nums);

int main() {
   vector<vector<char>> matrix;
    vector<char> row1(5,'1');
    vector<char> row2(5,'1');
    vector<char> row3(5,'1');
    vector<char> row4(5,'1');
    row1[1]='0';row1[3]='0';row1[4]='0';
    row2[1]='0';
    row4[1]='0';row4[2]='0';row4[4]='0';
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    int res=maximalRectangle(matrix);
    cout<<res<<endl;


}

int calMax(vector<int> nums){
    int len=nums.size();
    vector<int> left(len,-1);
    vector<int> right(len,len);

    vector<int> Q;
    for(int i=0;i<len;i++){

        while(!Q.empty()&&nums[i]<nums[Q[0]]){
            right[Q[0]]=i;
            Q.erase(Q.begin());
        }
        Q.insert(Q.begin(),i);
    }

    for(int i=len-1;i>=0;i--){

        while(!Q.empty()&&nums[i]<nums[Q[0]]){
            left[Q[0]]=i;
            Q.erase(Q.begin());
        }
        Q.insert(Q.begin(),i);
    }

    int max=0;
    for(int i=0;i<len;i++){
        int area=(right[i]-left[i]-1)*nums[i];
        if(area>max)
            max=area;
    }
    return max;


}
int maximalRectangle(vector<vector<char>>& matrix) {

    int row=matrix.size();
    if(row==0)
        return 0;
    int col=matrix[0].size();



    int max=0;
    vector<int> height;
    for(int i=0;i<col;i++){
        height.push_back(0);
    }
    for(int i=0;i<row;i++){

        for(int j=0;j<col;j++){
            if(matrix[i][j]=='1')
                height[j]++;
            else
                height[j]=0;
        }
        int m=calMax(height);
        if(m>max)
            max=m;
    }

    return max;

}