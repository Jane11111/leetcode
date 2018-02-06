#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* Construct(vector<int>preorder,int ps,int pe,vector<int> inorder,int is,int ie);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    TreeNode* root=Construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    return root;
}

TreeNode* Construct(vector<int>preorder,int ps,int pe,vector<int> inorder,int is,int ie){
    TreeNode*root;
    if(is==ie){
        root=new TreeNode(inorder[is]);
        return root;
    }else if(is>ie){
        return NULL;
    }
    root=new TreeNode(preorder[ps]);
    int i=is;
    for(;i<=ie;i++){
        if(inorder[i]==preorder[ps])
            break;
    }
    TreeNode* left=Construct(preorder,ps+1,ps+1+i-1-is,inorder,is,i-1);
    TreeNode* right=Construct(preorder,pe-(ie-i-1),pe,inorder,i+1,ie);
    root->left=left;
    root->right=right;
    return root;


}