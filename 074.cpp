#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target);
bool BinarySearch(vector<int>& nums,int s,int e,int target);

int main() {
    vector<vector<int>> matrix;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(3);
    row1.push_back(5);
    row1.push_back(7);
    vector<int>row2;
    row2.push_back(10);
    row2.push_back(11);
    row2.push_back(16);
    row2.push_back(20);
    vector<int> row3;
    row3.push_back(23);
    row3.push_back(30);
    row3.push_back(34);
    row3.push_back(50);
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    int target=3;
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
    int i=1;
    for(;i<matrix.size();i++)
        if(target<matrix[i][0])
            break;
    return BinarySearch(matrix[i-1],0,matrix[i-1].size()-1,target);

}
bool BinarySearch(vector<int>& nums,int s,int e,int target){
    if(s>e)
        return false;
    int mid=(s+e)/2;
    if(nums[mid]==target)
        return true;
    if(target<nums[mid])
        e=mid-1;
    else
        s=mid+1;
    return BinarySearch(nums,s,e,target);
}