#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int row=nums.size();
    if(row==0)
        return nums;
    int col=nums[0].size();
    if(row*col!=r*c)
        return nums;

    vector<int> tmp;
    vector<vector<int>> res;
    int count=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            tmp.push_back(nums[i][j]);
            count++;
            if(count==c){

                res.push_back(tmp);
                tmp.clear();
                count=0;
            }
        }
    }

    return res;

}