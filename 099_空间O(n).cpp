#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
void recoverTree(TreeNode* root);
void Recover(TreeNode* root,int num1,int num2);
void InOrder(TreeNode* root,vector<int>& orders);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void InOrder(TreeNode* root,vector<int>& orders){
    if(root==NULL)
        return ;
    InOrder(root->left,orders);
    orders.push_back(root->val);
    InOrder(root->right,orders);
}
void Recover(TreeNode* root,int num1,int num2){
    if(root==NULL)
        return ;
    if(root->val==num1)
        root->val=num2;
    else if(root->val==num2)
        root->val=num1;
    Recover(root->left,num1,num2);
    Recover(root->right,num1,num2);
}
void recoverTree(TreeNode* root){

    vector<int> orders;
    InOrder(root,orders);


    vector<int> sort_orders=orders;
    for(int i=0;i<sort_orders.size();i++){
        int num=sort_orders[i];
        for(int j=i-1;j>=0;j--){
            if(sort_orders[j]>num)
                swap(sort_orders[j],sort_orders[j+1]);
        }
    }

    int i1=-1;
    int i2=-1;
    for(int i=0;i<orders.size();i++){
        if(orders[i]!=sort_orders[i]){
            if(i1==-1)
                i1=i;
            else
                i2=i;
        }
    }

    if(i1==-1||i2==-1)
        return ;
    Recover(root,orders[i1],orders[i2]);


}