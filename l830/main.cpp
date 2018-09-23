#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> largeGroupPositions(string S);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> res;

    int start=0;
    for(int i=1;i<S.length();i++){
        while(i<S.length()&&S[i]==S[start])
            i++;
        if(i-start>=3)
            res.push_back({start,i-1});
        start=i;
    }
    return res;

}