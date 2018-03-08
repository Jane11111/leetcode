#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL)
        return NULL;
    if(root->val==key){
        if(root->left){
            TreeNode *p=root->left;
            while(p->right!=NULL){
                p=p->right;
            }
            p->right=root->right;
            root=root->left;
        }else if(root->right){
            TreeNode *p=root->right;
            while(p->left){
                p=p->left;
            }
            p->left=root->left;
            root=root->right;
        }else{
            root=NULL;
        }
    }else if(root->val>key){
        root->left=deleteNode(root->left,key);
    }else{
        root->right=deleteNode(root->right,key);
    }
    return root;

}