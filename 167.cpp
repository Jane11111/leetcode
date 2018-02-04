#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target);
int BinarySearch(vector<int>& numbers,int s,int e,int target);
int main() {
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(15);
    int target=9;

    vector<int> res=twoSum(numbers,target);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}

vector<int> twoSum(vector<int>& numbers, int target) {

    int len=numbers.size();
    vector<int> res;
    for(int i=0;i<len;i++){
        int index=BinarySearch(numbers,i+1,len-1,target-numbers[i]);
        if(index!=-1){
            res.push_back(i+1);
            res.push_back(index+1);
            return res;
        }
    }
    return res;
}


int BinarySearch(vector<int>& numbers,int s,int e,int target){
    if(s>e)
        return -1;
    int mid=(s+e)/2;
    if(numbers[mid]==target)
        return mid;
    if(numbers[mid]<target)
        s=mid+1;
    else
        e=mid-1;
    return BinarySearch(numbers,s,e,target);
}