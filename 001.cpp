#include<vector>
#include <iostream>
using namespace std;
vector<int> twoSum(vector<int>& arr, int sum);
int main() {
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    int sum=6;
    vector<int> result=twoSum(arr,sum);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

}

vector<int> twoSum(vector<int>& arr, int sum) {
    int len=arr.size();

    for (int l=0;l<len;l++){
        for (int r=0;r<len;r++){
            if (r==l)
                continue;
            if(arr[r]==sum-arr[l]){
                vector<int> temp;
                temp.push_back(l);
                temp.push_back(r);
                return temp;

            }
        }
    }
}