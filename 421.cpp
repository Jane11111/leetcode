#include <iostream>
#include<vector>
#include <cmath>
using namespace std;

struct BiNode{

    BiNode* nodes[2];
    BiNode(){
        nodes[0]=NULL;
        nodes[1]=NULL;
    }
};


int findMaximumXOR(vector<int>& nums);

int main() {

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(25);
    nums.push_back(2);
    nums.push_back(8);
    int res=findMaximumXOR(nums);
    cout<<res<<endl;
}
int findMaximumXOR(vector<int>& nums){
    BiNode * root=new BiNode();
    int arr[32];
    for(int i=0;i<32;i++)
        arr[i]=0;
    for(int num:nums){//build tree
        BiNode* p=root;
        int index=0;
        while(num!=0){
            int n=num%2;
            arr[index]=n;
            num/=2;
            index++;
        }
        for(int i=31;i>=0;i--){
            int n=arr[i];
            if(p->nodes[n]==NULL)
                p->nodes[n]=new BiNode();
            p=p->nodes[n];
            arr[i]=0;
        }

    }

    int res=INT_MIN;
    for(int num:nums){
        BiNode* p=root;
        int index=0;
        while(num!=0){
            int n=num%2;
            arr[index]=n;
            num/=2;
            index++;
        }

        //int base=pow(2,31)-1;
        int sum=0;
        for(int i=31;i>=0;i--){
            int base=pow(2,i);
            if(i==31)
                base=pow(2,i)-1;
            int n=arr[i];
            if(n==1&&p->nodes[0]){
                sum+=base;
                p=p->nodes[0];
            }else if(n==1&&!p->nodes[0]){
                p=p->nodes[1];
            }else if(n==0&& p->nodes[1]){
                sum+=base;
                p=p->nodes[1];
            }else{
                p=p->nodes[0];
            }

            arr[i]=0;

        }
        if(sum>res)
            res=sum;
    }
    return res;


}
