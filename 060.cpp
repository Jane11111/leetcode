#include <iostream>
#include <vector>
using namespace std;

char IntToChar(int i);
string getPermutation(int n, int k);
void Rec(vector<int> &nums,int start,int end,int k);
int main() {
    int n=3;
    int k=4;
    string str=getPermutation(n,k);
    cout<<str<<endl;

}
char IntToChar(int i){
    switch(i){
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return 0;
    }
}
void Rec(vector<int> &nums,int start,int end,int k){//k<=(end-start+1)!
    if(start==end||k==1)//第一个或者只有一个元素
        return;

    int i=start;
    int tmp=1;
    int mul=end-start+1;
    for(int i=mul;i>=1;i--)//tmp=(end-start+1)!
        tmp*=i;

    while(tmp>k){
        i++;
        tmp/=(mul);
        mul--;
    }
    if(tmp==k){
        //i-end倒排
        while(i<end){
            swap(nums[i],nums[end]);
            i++;
            end--;
        }
        return;
    }

    //tmp<k
    int x=k/tmp;
    int y=k%tmp;

    if(y==0){
        x--;
        y=k-(tmp*x);
    }


    int num=nums[i-1];
    nums[i-1]=nums[i-1+x];
    //依次后移
    for(int j=i+x-2;j>=i;j--)
        nums[j+1]=nums[j];
    nums[i]=num;


    Rec(nums,i,end,y);

}
string getPermutation(int n, int k){

    vector<int> nums;
    for(int i=1;i<=n;i++)
        nums.push_back(i);
    Rec(nums,0,n-1,k);
    string str;
    for(int i=0;i<nums.size();i++)
        str.push_back(IntToChar(nums[i]));
    return str;

}