#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
TreeNode* Contruct(vector<int>& inorder,int is,int ie,vector<int>&postorder,int ps,int pe);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    TreeNode* root=Contruct(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    return root;
}

TreeNode* Contruct(vector<int>& inorder,int is,int ie,vector<int>&postorder,int ps,int pe){
    TreeNode* root;
    if(is==ie){
        root=new TreeNode(inorder[is]);
        return root;
    }else if(is>ie){
        return NULL;
    }
    root=new TreeNode(postorder[pe]);
    int i=is;
    for(;i<=ie;i++){
        if(inorder[i]==postorder[pe])
            break;
    }

    TreeNode* left=Contruct(inorder,is,i-1,postorder,ps,i-1-is+ps);
    TreeNode* right=Contruct(inorder,i+1,ie,postorder,pe-1-(ie-i-1),pe-1);
    root->left=left;
    root->right=right;
    return root;
}