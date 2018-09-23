#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> transpose(vector<vector<int>>& A);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<vector<int>> transpose(vector<vector<int>>& A) {
    int m=A.size();
    if(m==0)
        return A;
    int n=A[0].size();

    vector<vector<int>> res;
    for(int i=0;i<n;i++)
        res.push_back(vector<int>());

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int num=A[i][j];
            res[j].push_back(num);
        }
    }
    return res;

}