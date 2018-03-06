#include <iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};
vector<int> postorderTraversal(TreeNode* root);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


vector<int> postorderTraversal(TreeNode* root){
    vector<TreeNode*> Q;
    vector<int> res;
    while(root){
        res.insert(res.begin(),root->val);
        Q.insert(Q.begin(),root);
        root=root->right;
    }
    while(!Q.empty()){
        TreeNode * p=Q[0];
        Q.erase(Q.begin());
        p=p->left;
        while(p){
            res.insert(res.begin(),p->val);
            Q.insert(Q.begin(),p);
            p=p->right;
        }

    }
    return res;
}
