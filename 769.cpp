#include <iostream>
#include <vector>
using namespace std;

int maxChunksToSorted(vector<int>& arr);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


int maxChunksToSorted(vector<int>& arr) {
    int result=0;
    int len=arr.size();
    if(len==0)
        return 0;
    int i=0;
    int max;
    while(i<len){
        max=arr[i];
        while(i<=max){

            max=max>arr[i]?max:arr[i];
            i++;
        }
        result++;

    }
    return result;


}