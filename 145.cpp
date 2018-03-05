#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
vector<int> res;
void RecTra(TreeNode* root);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
void RecTra(TreeNode* root){
    if(root==NULL)
        return ;
    RecTra(root->left);
    RecTra(root->right);
    res.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    RecTra(root);
    return res;

}
