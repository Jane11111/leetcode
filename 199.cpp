#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<int> rightSideView(TreeNode* root);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(root==NULL)
        return res;
    vector<TreeNode*> Q;
    res.push_back(root->val);
    root->val=0;
    Q.push_back(root);
    while(!Q.empty()){
        TreeNode*p=Q[0];
        Q.erase(Q.begin());
        int num=p->val+1;
        if(p->left==NULL&&p->right==NULL)
            continue;
        while(res.size()<=num)
            res.push_back(0);
        if(p->left!=NULL){
            res[num]=p->left->val;
            p->left->val=num;
            Q.push_back(p->left);
        }
        if(p->right!=NULL){
            res[num]=p->right->val;
            p->right->val=num;
            Q.push_back(p->right);
        }
    }
    return res;

}