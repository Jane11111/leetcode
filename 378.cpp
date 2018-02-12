#include <iostream>
#include <vector>
using namespace std;
void Insert(vector<int> & sort_list,int num);
int kthSmallest(vector<vector<int>>& matrix, int k);
int main() {
    vector<vector<int>> matrix;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    row1.push_back(1);
    row1.push_back(2);
    //row1.push_back(9);
    row2.push_back(1);
    row2.push_back(3);
    //row2.push_back(13);
    row3.push_back(12);
    row3.push_back(13);
    row3.push_back(15);
    matrix.push_back(row1);
    matrix.push_back(row2);
   // matrix.push_back(row3);
    int k=3;

    int res=kthSmallest(matrix,k);
    cout<<res<<endl;
}

void Insert(vector<int> & sort_list,int num){
    int len=sort_list.size();
    sort_list.push_back(num);
    for(int i=len-1;i>=0;i--){
        if(sort_list[i]>num)
            swap(sort_list[i],sort_list[i+1]);
        else
            return;
    }
    //sort_list.insert(sort_list.begin(),num);
}

int kthSmallest(vector<vector<int>>& matrix, int k) {

    int i=0;
    int n=matrix.size();
    for(;i<n;i++){
        if((i+1)*(i+1)>=k)
            break;
    }

    vector<int> sort_list;
    for(int j=0;j<=i;j++){
        for(int r=j;r<n;r++){
            Insert(sort_list,matrix[j][r]);
            if(r!=j)
                Insert(sort_list,matrix[r][j]);
        }
    }
    return sort_list[k-1];

}