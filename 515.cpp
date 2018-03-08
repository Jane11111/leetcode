#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<int> largestValues(TreeNode* root);
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    vector<TreeNode*> Q;
    if(root){
        Q.push_back(root);
        res.push_back(root->val);
        root->val=0;
    }
    while(!Q.empty()){
        TreeNode * p=Q[0];
        Q.erase(Q.begin());
        if(p->left||p->right)
            if(res.size()==p->val+1)
                res.push_back(INT_MIN);
        if(p->left){
            res[p->val+1]=max(res[p->val+1],p->left->val);
            p->left->val=p->val+1;
            Q.push_back(p->left);
        }if(p->right){
            res[p->val+1]=max(res[p->val+1],p->right->val);
            p->right->val=p->val+1;
            Q.push_back(p->right);
        }
    }
    return res;

}