#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height);
int main() {
    vector<int> height;
    height.push_back(1);
    height.push_back(1);
    int r=maxArea(height);
    cout<<r<<endl;
    return 0;
}


int maxArea(vector<int>& height) {
    int i=0;
    int j=height.size()-1;
    int res=0;
    while(i<j){
        int h=min(height[i],height[j]);
        res=max(res,h*(j-i));
        while(height[i]<=h)i++;
        while(height[j]<=h)j--;
    }
    return res;

}