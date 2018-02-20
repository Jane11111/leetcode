#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool canJump(vector<int>& nums) {
    int len=nums.size();
    if(len==0)
        return true;
    int visited[len];
    for(int i=0;i<len;i++)
        visited[i]=false;

    vector<int> Q;
    visited[0]=true;
    Q.push_back(0);
    if(0==len-1)
        return true;
    while(!Q.empty()){
        int index=Q[0];
        Q.erase(Q.begin());
        int num=nums[index];
        for(int j=1;j<=num&&index+j<len;j++){

            if(!visited[index+j]){
                visited[index+j]=true;
                Q.push_back(index+j);if(index+j==len-1)
                    return true;
            }
        }
    }
    return false;

}